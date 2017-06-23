/*
	TITLE		    Skip List	            Chapter18Exercise11v4.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Research and implement the data structure:
					Skip List. 

					Added:

					get_count()
					get_height()
		       
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2017
*/
#ifndef CHAPTER18EXERCISE11V4_H
#define CHAPTER18EXERCISE11V4_H 

class Skip_list 
{
public:
	Skip_list ();
	~Skip_list ();

	int get_count() const { return count; }
	int get_height() const { return nodeLevel(head->forward); }
	void print () const;
	std::string* find (int searchKey) const;

	void insert (int searchKey, std::string newValue);
	void erase (int searchKey); 
	
private:

	struct Skip_Node 
	{
		int key;
		std::string value;

		std::vector<Skip_Node*> forward;

		Skip_Node (int k, const std::string& v, int level)
			:  key(k), value(v)
		{
			for (int i = 0; i < level; ++i) 
			{
				forward.emplace_back(nullptr);
			}
		} 
	};

	int randomLevel () const; 
	static int nodeLevel (const std::vector<Skip_Node*>& v);
	static Skip_Node* makeNode (int key, std::string val, int level);
	std::vector<Skip_list::Skip_Node*> Skip_list::predecessors (int searchKey) const;
	Skip_Node* lower_bound (int searchKey) const ;

	Skip_Node* head;
	Skip_Node* NIL;
	int count;
	float probability;
	int maxLevel;
};

//------------------------------------------------------------------------------------------------------
//Implementations
 
Skip_list::Skip_list()
	: probability(0.5), maxLevel(16), count(0)
{
     int headKey = std::numeric_limits<int>::min();
	 head = new Skip_Node(headKey, "head", maxLevel);

	 int nilKey = std::numeric_limits<int>::max();
	 NIL = new Skip_Node(nilKey, "NIL", maxLevel);

	 for (size_t i = 0; i < head->forward.size(); ++i)
	 {
		 head->forward[i] = NIL;
	 }
}

//------------------------------------------------------------------------------------------------------

Skip_list::~Skip_list ()
{
	Skip_Node *node = head;

	while (node) 
	{
		Skip_Node *succ  = node->forward[0];

		delete node;

		node = succ;
	}
	delete node;
}

//------------------------------------------------------------------------------------------------------

int Skip_list::randomLevel () const
{
	static bool seed_initialized = false;

	if (!seed_initialized)
	{
		srand ((unsigned) time(NULL));
		seed_initialized = true;
	}
	 
	int l = 1;

	while (((double)std::rand() / RAND_MAX) < probability && l < maxLevel) 
	{
		++l;
	}
	return l;
}

//------------------------------------------------------------------------------------------------------

int Skip_list::nodeLevel (const std::vector<Skip_Node*>& v)
{
	int currentLevel = 1;
	 
	int nilKey = std::numeric_limits<int>::max();

	if (v[0]->key == nilKey)
	{
		return currentLevel;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] != nullptr && v[i]->key != nilKey) 
		{
			++currentLevel;
		}
		else 
		{ 
			break;
		}
	}
	return currentLevel;
}

//------------------------------------------------------------------------------------------------------

Skip_list::Skip_Node* Skip_list::makeNode (int key, std::string val, int level)
{
	return new Skip_Node(key, val, level);
}

//------------------------------------------------------------------------------------------------------

std::vector<Skip_list::Skip_Node*> Skip_list::predecessors(int searchKey) const 
{
	std::vector<Skip_Node*> update(head->forward);
	Skip_Node* x = head;

	for (unsigned int i = nodeLevel(head->forward); i-- > 0;) 
	{
		while (x->forward[i]->key < searchKey) 
		{
			x = x->forward[i];
		}
		update[i] = x;
	}
    return update;
}

//------------------------------------------------------------------------------------------------------

Skip_list::Skip_Node* Skip_list::lower_bound(int searchKey) const 
{
	Skip_Node* x = head;

	for (unsigned int i = nodeLevel(head->forward); i-- > 0;) 
	{
        while (x->forward[i]->key < searchKey) 
		{
            x = x->forward[i];
        }
    }
    return x->forward[0];
}

//------------------------------------------------------------------------------------------------------

void Skip_list::print () const
{
	Skip_Node* list = head;
	int lineLenght = 1;

	std::cout <<"{";

	while (list->forward[0] != nullptr) 
	{
		std::cout <<"value: "<< list->forward[0]->value
			      <<", key: "<< list->forward[0]->key
				  <<", level: "<< nodeLevel(list->forward); 

		list = list->forward[0];

		if (list->forward[0] != nullptr)
		{
			std::cout <<" : ";
		}

		if (++lineLenght % 2 == 0)
		{
			std::cout <<"\n";
		}
	}
	std::cout <<"}\n";
}

//------------------------------------------------------------------------------------------------------

std::string* Skip_list::find(int searchKey) const 
{
	Skip_Node* x = lower_bound(searchKey);

	if (x)
	{ 
		if (x->key == searchKey && x != NIL) 
		{
			return &(x->value);
		}
	}
	return nullptr; 
} 

//------------------------------------------------------------------------------------------------------

void Skip_list::insert(int searchKey, std::string newValue)
{
	std::vector<Skip_list::Skip_Node*> update(predecessors(searchKey));
	
	Skip_Node* x = nullptr;
	x = update[0]->forward[0]; 
 
	if (x->key == searchKey && x != NIL) 
	{
		x->value = newValue;
		return;
	}
	
	int newNodeLevel = randomLevel();
	x = makeNode(searchKey, newValue, newNodeLevel); 

	++count;

	for (int i = 0; i < newNodeLevel; ++i) 
	{
		x->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = x;
	}
}

//------------------------------------------------------------------------------------------------------

void Skip_list::erase (int searchKey)
{
	std::vector<Skip_Node*> update(predecessors(searchKey));

	Skip_Node* x = nullptr;
	x = update[0]->forward[0];

	if (!x || x->key != searchKey)
	{
		return;
	}

	for (size_t i = 0; i < update.size(); ++i) 
	{
		if (update[i]->forward[i] != x)
		{
			break;
		}
		update[i]->forward[i] = x->forward[i];
	}
	delete x;

	--count;
}


#endif