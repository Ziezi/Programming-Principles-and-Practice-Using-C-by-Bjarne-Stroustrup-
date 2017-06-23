/*
	TITLE		   Vector with pool allocator   		Chapter25Exercise14.h
	COMMENT
		Objective: Implement a simple vector that can hold at most N elements 
				   allocated from a pool. Test it for N == 1000 and integer elements.  

				   Possibly not right!!!

				   How use pool instead of malloc() when I need to pool.get()/free() 
				   each and every element of the vector?
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/

#ifndef Chapter25Exercise14_h
#define Chapter25Exercise14_h

//----------------------------------------------------------------------

// Mine but with Fragmentation & iteration - ugly
template <typename T, std::size_t N>
class Pool_b
{
	T* data;
	bool allocated[N];					   // sizeof(T) is the smallest memory unit

	bool is_full()						   // all memory allocated
	{
		for (std::size_t i = 0; i < N; ++i)
		{
			if (allocated[i] == false)
			{
				return false;
			}
		}
		return true;
	}

	bool is_empty()						   // all memory free
	{
		for (std::size_t i = 0; i < N; ++i)
		{
			if (allocated[i] == true)
			{
				return false;
			}
		}
		return true;
	}

	bool is_valid(T* ptr)
	{
		return ptr >= data && ptr <= (data + N);
	}

	std::size_t index_from_ptr(T* ptr) 
	{ 
		if (!is_valid(ptr))
		{
			throw std::invalid_argument("Pool::free()::index_from_ptr()::invalid pointer address!\n");
		}

		return (std::size_t)(ptr - data);
	}

	void check_state(const std::string msg)	 // test function
	{
		std::cout << msg <<'\n';
		std::cout <<"Start Current State\n";
		std::cout <<"is_full(): "<< is_full() <<", is_empty(): "<< is_empty() <<'\n';
		std::cout <<"T* data: "<< static_cast<void*>(data) <<'\n';
		std::cout <<"Available: " << available() <<'\n';
		std::cout <<"Allocated blocks:\n";
		for (std::size_t i = 0; i < N; ++i)
		{
			std::cout <<"Block: "<< i <<" : "<< std::boolalpha << allocated[i] <<" \n";	 
		}
		std::cout <<"End Current State\n";
		getchar();
	}

public:
	Pool_b()
		: data(new T[N])
	{
		std::fill_n(allocated, N, false);
		// check_state("Constructor");
	}

	~Pool_b() { delete [] data; /*check_state("Destructor");*/ }

	T* get()
	{
		if (is_full())
		{
			throw std::bad_alloc("Pool::get()::bad_alloc!\n");
		}

		T* ret = nullptr;

		for (std::size_t i = 0; i < N; ++i)
		{
			if (allocated[i] == false)
			{
				allocated[i] = true;
				ret = data + i;
				break;
			}
		}

		// check_state("get()");
		return ret;
	}

	void free(T* ptr)
	{
		std::size_t i = index_from_ptr(ptr);

		if (allocated[i] == false)
		{
			throw std::bad_alloc("Pool::free()::memory is already free!\n");
		}

		allocated[i] = false;

		// check_state("free()");
	}

	std::size_t available() const 
	{
		std::size_t free = 0;
		
		for (std::size_t i = 0; i < N; ++i)
		{
			if (allocated[i] == false)
			{
				++free;
			}
		}
		
		return free;
	}
};

//----------------------------------------------------------------------

// from paper 
template <typename T, std::size_t N>								 
class Pool
{
	typedef unsigned char uchar;
	typedef unsigned int uint;

	uint num_of_blocks;								 
	uint size_of_each_block;							 
	uint num_of_free_blocks;							 
	uint num_of_init_blocks;	// index of free blocks						 

	uchar* data;										  
	uchar* next;				// current free block / nullptr

	void create_pool(std::size_t blocks_size, uint blocks_number)
	{
		num_of_blocks = blocks_number;
		size_of_each_block = blocks_size;
		num_of_free_blocks = blocks_number;
		num_of_init_blocks = 0;

		data = new uchar[size_of_each_block * num_of_blocks];
		next = data;
	}

	void destroy_pool()
	{
		delete [] data;
	}

	uchar* addr_from_index(uint i) const
	{
		return data + (i * size_of_each_block);
	}

	uint index_from_addr(const uchar* ptr) const
	{
		return (((uint)(ptr - data)) / size_of_each_block);
	}

public:
	Pool() { create_pool(sizeof(T), N); };													 
	~Pool() { destroy_pool(); };												 
	 
	T* get()
	{
		if (num_of_init_blocks < num_of_blocks)
		{	// use the variable: num_of_init_blocks: as an index of the free blocks
			// get the address of the current free block
			uint* p = (uint*) addr_from_index(num_of_init_blocks);
			// store the index of the next free block at the address of the current free block
			*p = num_of_init_blocks + 1; 
			++num_of_init_blocks;
		}

		void* ret = nullptr;

		if (num_of_free_blocks > 0)
		{
			ret = (void*) next;
			--num_of_free_blocks;

			if (num_of_free_blocks != 0)
			{	// get index of next free block by dereferencing current value of next*; 
				// use the index to get the address of the next free block;
				// assign the address of the next free block as a new value of next*;
				next = addr_from_index( *((uint*)next) );	
			}
			else
			{	// end of pool
				next = nullptr; 
			}
		}

		return reinterpret_cast<T*>(ret);
	}

	void free(T* ptr2)
	{
		void* ptr = (void*)ptr2;

		if (next != nullptr)
		{	// get the index of the free memory block currently pointer by next
			// assign it to the first 4 bytes of the memory pointer by ptr
			(*(uint*)ptr) = index_from_addr(next);
			// update next to point to the newly freed block
			next = (uchar*)ptr;
		}
		else
		{
			// assign a nun_of_init_blocks value to the last memory block
			*((uint*)ptr) = num_of_blocks;
			// update next to current value of ptr to indicate it is free
			next = (uchar*)ptr;
		}

		++num_of_free_blocks;
	}	 

	std::size_t available() const { return num_of_free_blocks; }
}; 

//----------------------------------------------------------------------

// add size and pool to the template
template <class T>
class Allocator
{
	// Pool<T, 1000> pool; 
	Pool_b<T, 1000> pool; 

public:
	Allocator()
	{
		 
	}

	~Allocator()
	{
		 
	}

	T* allocate () { return pool.get(); }
	void deallocate (T* ptr) { pool.free(ptr); }

	// use pool.get() to obtain the argument, ptr, of this function before using it?
	void construct (T* ptr, const T& v) {  new(ptr) T(v); }   

	// use pool.free() after I destroy the element?
	void destroy (T* ptr) { ptr->~T(); }                      
};

//----------------------------------------------------------------------

template <class T, class A = Allocator<T> >
class Vector
{
public:
	Vector()
		: sz(0), elem(nullptr), space(0)
	{
	
	}

	Vector(int s)
		: sz(s), elem(nullptr), space(s)
	{
		elem = alloc.allocate();

		T init = T();
		for (int i = 0; i < sz; ++i)
		{
			alloc.construct(&elem[i], init);
		}
	}

	Vector(int s, T val)
		: sz(s), elem(nullptr), space(s)
	{
		elem = alloc.allocate();

		for (int i = 0; i < sz; ++i)
		{
			alloc.construct(&elem[i], val);
		}
	}

	Vector<T, A>& operator= (const Vector<T, A>& src)
	{
		if (this == &src)							// self assignment
		{
			return *this;
		}

		if (sz >= src.size())						// already enough memory - overwrite
		{
			for (int i =0; i < sz; ++i)
			{
				alloc.construct(&elem[i], src.elem[i]);
			}

			sz = src.size();

			return *this;
		}

		T* new_ptr = alloc.allocate(src.size());	// make new copy

		for (int i =0; i < src.size(); ++i)
		{
			alloc.construct(&new_ptr[i], src.elem[i]);
		}
		
		for (int i =0; i < sz; ++i)
		{
			alloc.destory(&elem[i]);
		}

		alloc.deallocate(elem);

		space = sz = src.size();
		elem = new_ptr;
		
		return *this;
	}		

	void reserve(int newalloc);
	void resize(int newsize, T val = T());
	void push_back(const T& val);

	T& operator[] (int index) { return elem[index]; }

	int size() const { return sz; }
	int capacity() const { return space; }

private:
	A alloc;
	T* elem;
	int sz;
	int space;
};

//----------------------------------------------------------------------

template <class T, class A>
void Vector <T,A>::reserve(int newalloc)
{
	if (newalloc <= space) 
	{
		return;
	}

	T* new_mem_ptr = alloc.allocate();

	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&new_mem_ptr[i] , elem[i]);
	}

	for (int i = 0; i < sz; ++i) 
	{
		alloc.destroy(&elem[i]);
	}

	if (elem != nullptr) // default constructor, creating a vector from scratch
	{
		alloc.deallocate(elem);
	}

	elem = new_mem_ptr;

	space = newalloc;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::resize(int newsize, T val = T())
{
	reserve(newsize);

	for (size_t i = 0; i < newsize; ++i)
	{
		alloc.construct(elem[i], val);
	}

	for (size_t i = newsize; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}

	sz = newsize;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::push_back(const T& val)
{
	if (space == 0)
	{
		reserve(8);
	}
	else if (sz == space)
	{
		reserve(2 * space);
	}

	alloc.construct(&elem[sz], val);
	++sz;
}

//----------------------------------------------------------------------

#endif