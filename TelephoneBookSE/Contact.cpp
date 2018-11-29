#include "pch.h"

Contact::Contact()
{
	// Constructor
}

void Contact::addName(string name)
{
	names.push_back(name);

}

void Contact::setNumber(string num)
{
	number = num;
}

vector<string> Contact::getNames()
{
	return names;
}

string Contact::getNumber()
{
	return number;
}

