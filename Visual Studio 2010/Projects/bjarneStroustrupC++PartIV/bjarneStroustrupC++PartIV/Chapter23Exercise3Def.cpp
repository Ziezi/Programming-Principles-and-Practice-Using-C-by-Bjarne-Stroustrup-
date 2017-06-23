/*
	TITLE		   Email file with regular expressions  Chapter23Exercise3.h
	COMMENT
		Objective: Modify the email example from §23.4 to use regular
				   expressions to find the subject and sender.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 26.04.2017
*/

Mail_file::Mail_file(const std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());
	if (!ifs) 
	{
		throw std::runtime_error("Can't open input file: " + file_name);
	}

	// build the vector of lines
	std::string line;
	while (getline(ifs, line))
	{
		lines.push_back(line);
	}

	// build the vector of Messages 
	Line_iter first = lines.begin();
	for (Line_iter p = lines.begin(); p != lines.end(); ++p)
	{
		if (is_end_of_message(p))
		{   
			// message is defined via iterators to its start and end	
			m.push_back(Message(first, p)); 

			// skip the end-of-message indicator
			first = p + 1; 
		}
	}

	std::cout <<"Messages: " << m.size();
	std::cout <<"\nLines: " << lines.size();
}

//---------------------------------------------------------------


/* 
	Function: succes is_prefix(in, in, out) 

	Look for p in s and return true and
	the rest of the matching line in m.
	Otherwise return false and m is empty.	
*/
bool is_prefix(const std::string& s, const std::string& p, std::string& m)
{
	std::regex pattern("^" + p + "(.+)$");
	std::smatch match;

	if (std::regex_search(s, match, pattern))
	{
		m = match[1];
		return true;
	}
	return false;
}

//---------------------------------------------------------------

/* 
	Function: success find_from_addr(in, out)

	Returns true and the name of the sender of the message 
	passed by the first argument, otherwise returns false 
	and sender is an empty string. 
*/
bool find_from_addr(const Message* message, std::string& sender)
{
	for (Line_iter p = message->begin(); p != message->end(); ++p)
	{
		if (is_prefix(*p, "From: ", sender))
		{
			return true;
		}
	}
	return false;
}

//---------------------------------------------------------------

bool find_subject(const Message* message, std::string& subject)
{
	for (Line_iter p = message->begin(); p != message->end(); ++p)
	{
		if (is_prefix(*p, "Subject: ", subject))
		{
			return true;
		}
	}
	return false;
}

//---------------------------------------------------------------

bool is_end_of_message(Line_iter line)
{
	return *line == "----";
}