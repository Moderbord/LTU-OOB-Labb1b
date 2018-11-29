#include "pch.h"

namespace {
	using std::cout;
	using std::endl;
}

Telebook::Telebook()
{
	// Constructor;
}

void Telebook::addEntry(string name, string number)
{
	Contact ct;													// Define contact to add					
	ct.addName(name);
	ct.setNumber(number);

	pair<map<string, Contact>::iterator, bool> hit;				// Pair of iterator and bool

	hit = entries.insert(pair<string, Contact>(number, ct));	// Tries to add contact to map, return false if key (contact number) already existed

	if (!hit.second)
	{
		printf_s("Contact already exists\n");
	}
}

void Telebook::addEntry(string number, Contact ct)				// Used when changing contact number
{
	ct.setNumber(number);										// Sets new number to local copy of contact
	pair<map<string, Contact>::iterator, bool> hit;

	hit = entries.insert(pair<string, Contact>(number, ct));	// Tries to insert contact into map

	if (!hit.second)
	{
		printf_s("Occupied number\n");
		return;
	}
}

void Telebook::findEntry(string name)							// Prints the number of the first found contact matching search name
{
	Contact (*ct) = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	cout << ct->getNumber() << endl;
}

Contact* Telebook::getEntry(string name)						// Method which returns certain contact from map
{
	map<string, Contact>::iterator outer;

	for (outer = entries.begin(); outer != entries.end(); outer++)		// iterator
	{
		for (string value : outer->second.getNames())
		{
			if (name == value) {								// Search value (name) was found in map
				return &(outer->second); // Sends reference
			}
		}
	}
	return false;
}

void Telebook::aliasEntry(string name, string alias)			// Adds the alias to a vector inside the contact
{
	Contact* ct = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	ct->addName(alias);
	
}

void Telebook::changeEntry(string name, string number)			// Adds a new contact with new number and removes old entry
{
	Contact(*ct) = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	addEntry(number, *ct);
	removeEntry(ct->getNumber());
}

void Telebook::removeEntry(string number)
{
	map<string, Contact>::iterator hit = entries.find(number);
	entries.erase(hit);
}