#include "pch.h"

void insert(string s, vector<string> &key, vector<string> &value);
void lookup(string s, vector<string> key, vector<string> value);
bool lookup(string s, vector<string> key);

DictVector::DictVector()
{
	vector<string> key;
	vector<string> value;

	while (true)
	{
		cout << "===================" << endl;
		cout << "Dictionary - Vector" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Lookup" << endl;
		cout << "3. Exit" << endl;
		cout << "\n>>";

		string input, word;
		cin >> input;

		switch (input[0])
		{
		case '1':
			cout << "Word to enter: ";
			cin >> word;

			insert(word, key, value);
			break;

		case '2':
			cout << "Word to lookup: ";
			cin >> word;

			lookup(word, key, value);
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

void insert(string s, vector<string> &key, vector<string> &value)
{
	if (lookup(s, key)) {
		cout << "Word is already defined" << endl;
		return;
	}

	string desc;

	cout << "Enter a description: ";
	cin >> desc;

	key.push_back(s);
	value.push_back(desc);
}

void lookup(string s, vector<string> key, vector<string> value)
{
	int i = 0;

	for (string k : key)
	{
		if (s == k) {
			cout << value.at(i) << endl;
			return;
		}
		i++;
	}

	cout << "Word was not found" << endl;

}

bool lookup(string s, vector<string> key)
{
	int i = 0;

	for (string k : key)
	{
		if (s == k) {
			return true;
		}
		i++;
	}

	return false;
}
