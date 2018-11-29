#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iterator>

namespace {

	using std::vector;
	using std::string;
	using std::map;
	using std::pair;
	using std::istringstream;
	using std::istream_iterator;
}

class Contact
{

public:
	Contact();
	void addName(std::string name);
	void setNumber(std::string name);
	std::vector<std::string> getNames();
	std::string getNumber();

private:
	std::vector<std::string> names;
	std::string number;

};

class Telebook
{

public:
	Telebook();
	void addEntry(std::string, std::string);
	void addEntry(std::string number, Contact ct);
	void findEntry(std::string);
	Contact* getEntry(std::string);
	void aliasEntry(std::string, std::string);
	void changeEntry(std::string, std::string);
	void removeEntry(string number);

private:
	std::map<std::string, Contact> entries;

};
