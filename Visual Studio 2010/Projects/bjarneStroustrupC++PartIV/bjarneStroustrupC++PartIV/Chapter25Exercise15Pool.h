/*
	TITLE		   new[] vs pool vs stack     	       Chapter25Exercise15Pool.h
	COMMENT
		Objective: Measure the time it takes to de / allocate 10000 objects 
				   of random sizes in [10000:0) - byte range.
				   Do this twice:
				   a). Deallocate in reverse order.
				   b). Deallocate in random order.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.05.2017
*/
#ifndef Chapter25Exercise15Pool_h
#define Chapter25Exercise15Pool_h

//----------------------------------------------------------------------------

// Fragmentation & iteration - ugly
template <typename T, std::size_t N>
class Pool
{
	T* data;
	bool* allocated;					   // sizeof(T) is the smallest memory unit

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

	void check_state(const std::string msg)
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
	Pool()
		: data(new T[N]), allocated(new bool[N]())
	{

	}

	~Pool() { delete [] data; }

	T* get()
	{
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

		if (ret == nullptr)
		{
			throw std::bad_alloc("Pool::get()::bad_alloc!\n");
		}

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

//----------------------------------------------------------------------------

void test_pool()
{
	const std::size_t size = 4;
	Pool<int, size> p;

	int* p1 = p.get();

	*p1 = 100;
	std::cout <<" p1 address is: " << static_cast<void*>(p1) <<" points to value: " << *p1 <<'\n';

	int* p2 = p.get();
	int* p3 = p.get();
	// int* p5 = p.get();		
	// int* p6 = p.get();	   // bad_alloc

	p.free(p2);
	int* p4 = p.get();

	p.free(p1);
	p.free(p3);
	p.free(p4);
	// p.free(p4);			   // already free

	// int* p5 = new int;
	// p.free(p5);			   // invalid address
}

//----------------------------------------------------------------------------

void Pool_time_test()
{
	std::vector<Test_Object*> obj_vect(NUMBER);
	Pool<Test_Object, NUMBER> p;

	for (std::size_t allocations = 0; allocations < NUMBER; ++allocations)
	{
		obj_vect[allocations] = p.get();
	}
		 
	for (std::size_t allocations = NUMBER; allocations-- > 0;)
	{
		p.free(obj_vect[allocations]);
	}
}

//----------------------------------------------------------------------------

void Pool_run_time_test()
{
	std::vector<Measurement> data; 

	std::clock_t start = std::clock();

	Pool_time_test();
			
	double time = 1000.0 * (std::clock() - start) / CLOCKS_PER_SEC;	// find CPU execution time
	data.emplace_back(Measurement(NUMBER, time));
 
	std::string name("Chapter25Exercise15PoolSize");					 
	name += std::to_string((unsigned long long)BLOCK_SIZE) + ".txt";
	write_to_file(name, data);
}

#endif