#include "pch.h"

void insert(string key, string desc, map <string, string> &dict);
void lookup(string key, map <string, string> dict);

DictMap::DictMap()
{
	map <string, string> dict;

	while (true)
	{
		cout << "===================" << endl;
		cout << "Dictionary - Map" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Lookup" << endl;
		cout << "3. Exit" << endl;
		cout << "\n>> ";

		string input, word, desc;
		cin >> input;

		switch (input[0])
		{
		case '1':
			cout << "Word to enter: ";
			cin >> word;
			
			cout << "Description of word: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// safer way to ignore '\n' in the buffer
			getline(cin, desc);

			insert(word, desc, dict);
			break;

		case '2':
			cout << "Word to lookup: ";
			cin >> word;

			lookup(word, dict);
			break;

		case '3':
			cout << "Closing..";
			return;
			break;

		default:
			break;

		}
	}
}

void insert(string key, string desc, map <string, string> &dict)
{
	pair<map<string, string>::iterator, bool> hit;

	hit = dict.insert(pair<string, string>(key, desc));
	if (hit.second == false)
	{
		cout << "Word already exist\n";
	}
}

void lookup(string key, map <string, string> dict)
{
	map<string, string>::iterator hit = dict.find(key);

	if (hit != dict.end())
	{
		cout << dict[key] << endl;
		return;
	}
	cout << "Word was not found" << endl;
}
