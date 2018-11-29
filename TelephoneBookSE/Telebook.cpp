#include "pch.h"

Telebook::Telebook()
{
	// Constructor;
}

void Telebook::addEntry(string name, string number)
{
	Contact ct;
	ct.addName(name);
	ct.setNumber(number);

	pair<map<string, Contact>::iterator, bool> hit;

	hit = entries.insert(pair<string, Contact>(number, ct));

	if (!hit.second)
	{
		printf_s("Contact already exists\n");
	}
}

void Telebook::addEntry(string number, Contact ct)
{
	ct.setNumber(number);
	pair<map<string, Contact>::iterator, bool> hit;

	hit = entries.insert(pair<string, Contact>(number, ct));

	if (!hit.second)
	{
		printf_s("Occupied number\n");
		return;
	}
}

void Telebook::findEntry(string name)
{
	Contact (*ct) = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	cout << (*ct).getNumber() << endl;
}

Contact* Telebook::getEntry(string name)
{
	map<string, Contact>::iterator outer;

	for (outer = entries.begin(); outer != entries.end(); outer++)
	{
		for (string value : outer->second.getNames())
		{
			if (name == value) {
				return &(outer->second); // Sends reference
			}
		}
	}
	return false;
}

void Telebook::aliasEntry(string name, string alias)
{
	Contact* ct = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	(*ct).addName(alias);
	
}

void Telebook::changeEntry(string name, string number)
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