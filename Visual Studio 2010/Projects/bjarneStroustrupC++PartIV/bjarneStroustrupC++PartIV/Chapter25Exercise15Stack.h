/*
	TITLE		   new[] vs pool vs stack     	       Chapter25Exercise15Stack.h
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
#ifndef Chapter25Exercise15Stack_h
#define Chapter25Exercise15Stack_h

//----------------------------------------------------------------------------

template <std::size_t N>									 
class Stack
{
	typedef unsigned char uchar;
	typedef std::size_t uint;

	uchar* data;												
	uchar* end;												 
	uchar* top;												 

	uint index;
	uint* memory_blocks_sizes;			    // byte is the smallest memory unit 

	bool is_full() { return !(top < end); }

	bool is_empty() { return top == data && index == 0; }

	void update(uint n, bool allocate) 
	{
		if (allocate)
		{
			top += n;						// shift top n bytes towards the end		
			memory_blocks_sizes[index] = n;	// store size of allocated block
			++index;						// update index to store next
		}
		else
		{
			--index;						// update index to get previous
			n = memory_blocks_sizes[index];	// get size of last allocated block
			top -= n;						// shift top towards the start(data)
		}
	}

	void check_state(const std::string msg) // test function
	{
		std::cout << msg <<'\n';
		std::cout <<"Start Current State\n";
		std::cout <<"is_full(): "<< is_full() <<", is_empty(): "<< is_empty() <<'\n';
		std::cout <<"uchar* data: "<< static_cast<void*>(data) <<'\n';
		std::cout <<"uchar* end: "<< static_cast<void*>(end) <<'\n';
		std::cout <<"uchar* top: "<< static_cast<void*>(top) <<'\n';
		std::cout <<"uint index: "<< index <<'\n';

		std::cout <<"uint memory_blocks_sizes: \n";
		for (uint i = 0 ; i < index; ++i)
		{
			std::cout << i <<" th size: "<< memory_blocks_sizes[i] <<'\n';
		}
		std::cout <<"End Current State\n";
		getchar();
	}

public:
	Stack()
		: data(new uchar[N]), end(data + N), top(data), index(0), memory_blocks_sizes(new uint[N])
	{

	}

	~Stack() { delete[] data; }

	void* get(uint n)
	{
		 if (is_full() || ((top + n) > end))
		 {
			throw std::bad_alloc("Stack::get()::Stack Overflow!\n");
		 }
		 void* ret = (void*) top;

		 update(n, true);

		 return ret;
	}

	void free()
	{
		if (is_empty())
		{
			throw std::bad_alloc("Stack::free()::Stack Underflow!\n");
		}
		update(0, false);
	}

	uint available() const { return uint(end - top); };
};

//----------------------------------------------------------------------------

void test_stack()
{
	const std::size_t bytes = 5;
	Stack<bytes> s;
	std::cout <<"available bytes: " << s.available() <<'\n';
	unsigned char* p = reinterpret_cast<unsigned char*>(s.get(1));
	std::cout <<"available bytes: " << s.available() <<'\n';
	s.free();

	std::cout <<"available bytes: " << s.available() <<'\n';

	unsigned char* p1 = reinterpret_cast<unsigned char*>(s.get(2));
	unsigned char* p2 = reinterpret_cast<unsigned char*>(s.get(2));
	unsigned char* p3 = reinterpret_cast<unsigned char*>(s.get(1));

	s.free();
	s.free();
	unsigned char* p4 = reinterpret_cast<unsigned char*>(s.get(3));
	// unsigned char* p5 = reinterpret_cast<unsigned char*>(s.get(1)); // bad_alloc
	s.free();
	s.free();

	// s.free(); // stack already free

	int* ip = reinterpret_cast<int*>(s.get(sizeof(int)));
	s.free();

	//double* dp = reinterpret_cast<double*>(s.get(sizeof(double))); // bad_alloc
	//s.free();
}

//----------------------------------------------------------------------------

void Stack_time_test()
{
	std::vector<Test_Object*> obj_vect(NUMBER);

	const std::size_t bytes = NUMBER * sizeof(Test_Object);
	Stack<bytes> s;

	for (std::size_t allocations = 0; allocations < NUMBER; ++allocations)
	{
		obj_vect[allocations] = reinterpret_cast<Test_Object*>(s.get(sizeof(Test_Object)));
	}
		 
	for (std::size_t allocations = NUMBER; allocations-- > 0;)
	{
		s.free();
	}
}

//----------------------------------------------------------------------------

void Stack_run_time_test()
{
	std::vector<Measurement> data; 

	std::clock_t start = std::clock();

	Stack_time_test();
			
	double time = 1000.0 * (std::clock() - start) / CLOCKS_PER_SEC;	// find CPU execution time
	data.emplace_back(Measurement(NUMBER, time));
 
	std::string name("Chapter25Exercise15StackSize");					 
	name += std::to_string((unsigned long long)BLOCK_SIZE) + ".txt";
	write_to_file(name, data);
}

#endif
