/*	
    TITLE	           English Language Grammar	 Chapter6Exercise6.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement simple grammar that discerns noun, 
			           verb, conjunction and article
					   in the right order to form a valid sentence. 
				Input: Enter a senctence.
			   Output: Prints whether sentences is valid.
			   Author: Chris B. Kirov.
				 Data: 10.02.2015.
*/
#include <iostream>
#include <string>
#include <vector>

void functionInitialization();
bool isValidSentence(const std::string& is);

//================================================================================================
int main()
{
	// loads all the test functions with referent values
	functionInitialization();

	// prompts user to enter a sentence to be validated
	std::cout << "\t\tWelcome to our simple grammar check.\n";
	std::string prompt = "\nEnter a sentence to be tested; 'x' to exit:\n>>";
	std::string sentinel = "x";
	std::string inputSentence;

	while (true)
	{
		std::cout << prompt;
		getline(std::cin, inputSentence);

		if (inputSentence ==  sentinel)
		{
			break;
		}

		// print result
		if( isValidSentence(inputSentence))
		{
			std::cout << "Gramatically valid sentence!\n";
		}
		else
		{
			std::cout << "Gramatically NOT valid sentence!\n";
		}
	}
}
//================================================================================================

// vectore holding the list with reference article values 
std::vector<std::string> article;
// vectore holding the list with reference noun values 
std::vector<std::string> noun;
// vectore holding the list with reference verb values 
std::vector<std::string> verb;
// vectore holding the list with reference noun values 
std::vector<std::string> conjunction;

//-----------------------------------------------------------------
void functionInitialization()
{
	std::string w;
	// initializes articles
	std::string arrA[6] = {"a","A","an","An","the","The"};
	for (int i = 0; i < 6; i++)
	{
		w = arrA[i];
		article.push_back(w);
	}

	// initializes nouns
	std::string arrN[6] = {"birds","Birds","fish","Fish","c++","C++"};
	for (int i = 0; i < 6; i++)
	{
		w = arrN[i];
		noun.push_back(w);
	}
	
	// initializes verbs
	std::string arrV[6] = {"fly","Fly","swim","Swim","rules","Rules"};
	for (int i = 0; i < 6; i++)
	{
		w = arrV[i];
		verb.push_back(w);
	}

	// initializes conjunctions
	std::string arrC[4] = {"and","but","or", ","};
	for (int i = 0; i < 4; i++)
	{
		w = arrC[i];
		conjunction.push_back(w);
	}
}

//-----------------------------------------------------------------
/*
	Function: isArticle()
	Use: bool article = isArticle(const string& a)
	A function that takes the first word from the input stream and
	compares it with the existing references to determine whether it
	is article.
*/
bool isArticle(const std::string& a)
{
	for(unsigned int i = 0; i < article.size(); i++) if(a == article[i]) return true;
	return false;
}

//-----------------------------------------------------------------
/*
	Function: isNoun()
	Use: bool noun = isNoun(const string& a)
	A function that takes the second word from the input stream and
	compares it with the existing references to determine whether it
	is noun.
*/
bool isNoun(const std::string& a)
{
	for(unsigned int i = 0; i < noun.size(); i++) if(a == noun[i]) return true;
	return false;
}

//-----------------------------------------------------------------
/*
	Function: isVerb()
	Use: bool verb = isVerb(const string& a)
	A function that takes the third word from the input stream and
	compares it with the existing references to determine whether it
	is verb.
*/
bool isVerb(const std::string& a)
{
	for(unsigned int i = 0; i < verb.size(); i++) if(a == verb[i]) return true;
	return false;
}

//-----------------------------------------------------------------
/*
	Function: isConjunction()
	Use: bool conjunction = isConjuction(const string& a)
	A function that takes the forth word from the input stream and
	compares it with the existing references to determine whether it
	is conjunction.
*/
bool isConjunction(const std::string& a)
{
	for(unsigned int i = 0; i < conjunction.size(); i++) if(a == conjunction[i]) return true;
	 
	return false;
}

//------------------------------------------------------------------
/*
	Funciton: split()
	Use: split(s, ' ', v)
	Splits a delimited, ' ', string, s, into sequence of strings
	and stores them into vector, v.
*/
void split(const std::string& s, char c, std::vector<std::string>& v)
{
   std::string::size_type i = 0;
   std::string::size_type j = s.find(c);

   while (j != std::string::npos)
   {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == std::string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

/* 
	Function: isValidSentence()
	Use: bool sentence = isValidSentence(const istream& a)
	This function runs through input stream and calls the appropriate
	funtion according to the order of the string in the stream to check if
	it is of the right type(part of the speech).
	All the called functions are AND -ed and should return true for isSentence to
	return true, and, hence, the content of the input stream to be valid sentence.
*/
bool isValidSentence(const std::string& is)
{
	// variables testing sentence structure: noun verb (conjunction)
	bool a1 = 0;
	bool b1 = 0;
	bool c1 = 0;
	// variables testing sentence structure: article noun verb (conjunction)
	bool a2 = 0;
	bool b2 = 0;
	bool c2 = 0;
	bool d2 = 0;

	std::vector<std::string> inputVector;
	split(is, ' ', inputVector);

	unsigned int j = 0;
	while(j < inputVector.size())
	{
		switch(j)
		{
			case 0:
				a1 = isNoun(inputVector[j]);
				a2 = isArticle(inputVector[j]);
			case 1:
				b1 = isVerb(inputVector[j]);
				b2 = isNoun(inputVector[j]);
			case 3:
				c1 = isConjunction(inputVector[j]);
				c2 = isVerb(inputVector[j]);
			case 4:
				d2 = isConjunction(inputVector[j]);
		}
		j++;
	}

	if ((a1 && b1) || (a1 && b1 && c1) || (a2 && b2 && c2) || (a2 && b2 && c2 && d2)) return true;
	else return false;
}

