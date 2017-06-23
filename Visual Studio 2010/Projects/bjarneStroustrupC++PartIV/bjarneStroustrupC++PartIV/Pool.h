#ifndef Pool_h
#define Pool_h

// To be completed!!! 

class Pool_c
{
	typedef unsigned int uint;
	typedef unsigned char uchar;

	uint m_numOfBlocks;  
	uint m_sizeOfEachBlock; 
	uint m_numFreeBlocks;  
	uint m_numInitialized; 
	uchar* m_memStart;  
	uchar* m_next;  

	void DestroyPool()
	{
		delete[] m_memStart;
		m_memStart = nullptr;
	}

	uchar* AddrFromIndex(uint i) const
	{
		return m_memStart + ( i * m_sizeOfEachBlock );
	}

	uint IndexFromAddr(const uchar* p) const
	{
		return (((uint)(p - m_memStart)) / m_sizeOfEachBlock);
	}

public:

	Pool_c()
	{
		m_numOfBlocks = 0;
		m_sizeOfEachBlock = 0;
		m_numFreeBlocks = 0;
		m_numInitialized = 0;
		m_memStart = nullptr;
		m_next = 0;
	}

	~Pool_c() { DestroyPool(); }

	void CreatePool(size_t sizeOfEachBlock, uint numOfBlocks)
	{
		m_numOfBlocks = numOfBlocks;
		m_sizeOfEachBlock = sizeOfEachBlock;
		m_memStart = new uchar[ m_sizeOfEachBlock * m_numOfBlocks ];
		m_numFreeBlocks = numOfBlocks;
		m_next = m_memStart;
	}

	void* Allocate()
	{
		if (m_numInitialized < m_numOfBlocks )
		{
			++m_numInitialized;
		}

		void* ret = nullptr;

		if ( m_numFreeBlocks > 0 )
		{
			ret = (void*)m_next;
			--m_numFreeBlocks;

			if (m_numFreeBlocks!=0)
			{
				m_next = AddrFromIndex( *((uint*)m_next) );
			}
			else
			{
				m_next = nullptr;
			}
		}
		return ret;
	}

	void DeAllocate(void* p)
	{
		if (m_next != nullptr)
		{
			(*(uint*)p) = IndexFromAddr( m_next );
			m_next = (uchar*)p;
		}
		else
		{
			*((uint*)p) = m_numOfBlocks;
			m_next = (uchar*)p;
		}

		++m_numFreeBlocks;
	}
};

//----------------------------------------------------------------------

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

	size_t available() const { return num_of_free_blocks; }
};

#endif