#include "pch.h"

int main()
{
	Telebook tBook;

	while (true)
	{
		string input = "";
		char buffer[100];

		printf_s("phonebook> ");
		scanf_s("%[^\n]%*c", buffer, std::size(buffer));	// Stores entire input (including spaces) into 'buffer'
		input = buffer;										// Copy value into string

		istringstream istream(input);						// Puts the string into a string buffer
		istream_iterator<string> start(istream), end;		// Iterates through the buffer and splits it at whitespace

		vector<string> params(start, end);					// Adds to the vector from the start of the iterator to the end


		if (params[0] == "add") {							// params[0] - refers to command
			tBook.addEntry(params[1], params[2]);			// params[1] - refers to name
		}													// params[2] - refers to alias or number
		else if (params[0] == "lookup")
		{
			tBook.findEntry(params[1]);
		}
		else if (params[0] == "change")
		{
			tBook.changeEntry(params[1], params[2]);
		}
		else if (params[0] == "alias")
		{
			tBook.aliasEntry(params[1], params[2]);
		}
		else if (params[0] == "quit")
		{
			printf_s("closing..");
			return false;
		}

	}
}