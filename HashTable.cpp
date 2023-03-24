#include <iostream>
#include <string>
#include <list>

using namespace std;

const int SIZE = 10;

class HashTable
{
private:
	list<pair<int, string>> table[SIZE];

public:
	bool IsEmpty()
	{
		int sum{};

		for (int i{}; i < SIZE; i++)
		{
			sum += table[i].size();
		}

		if (!sum)
			return true;
		else
			return false;


	}
	
	int HashFunction(int key)
	{
		return key % SIZE;
	}


	void InsertItem(int key, string value)
	{
		int hashValue = HashFunction(key);
		auto& cell = table[hashValue];
		auto Itr = begin(cell);
		bool IfKeyExist = false;
		for (; Itr != end(cell); Itr) 
		{
			if (Itr->first == key)
			{
				IfKeyExist = true;
				Itr->second = value; 
				cout << "Value replaced" << endl;
				break;
			}
		}

		if (!IfKeyExist)
			cell.emplace_back(key, value);
	}

	void RemoveItem(int key)
	{
		int hashValue = HashFunction(key);
		auto& cell = table[hashValue];
		auto Itr = begin(cell);
		bool IfKeyExist = false;
		for (; Itr != end(cell); Itr) 
		{
			if (Itr->first == key)
			{
				IfKeyExist = true;
				Itr = cell.erase(Itr); 
				break;
			}
		}

		if (!IfKeyExist)
			cout << "Key not found" << endl;

	}

	void printTable()
	{
		for (int i{}; i < SIZE; i++)
		{
			if (table[i].size() == 0)
			{
				continue;
			}
			auto Itr = table[i].begin();
			for (; Itr != table[i].end(); Itr++)
				cout << Itr->first << " " << Itr->second << endl;
		}
	}

	string Search(int key)
	{
		int hashValue = HashFunction(key);
		auto& cell = table[hashValue];
		auto Itr = begin(cell);
		bool IfKeyExist = false;
		for (; Itr != end(cell); Itr) 
		{
			if (Itr->first == key)
			{
				if (Itr->first == key)
					return Itr->second;
				else
					cout << "Key not found" << endl;
			}
		}
	}
};

int main()
{

	HashTable Students;

	if (Students.IsEmpty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << endl;

	Students.InsertItem(1, "Pasha");
	Students.InsertItem(2, "Roma");
	Students.InsertItem(3, "Dasha");
	Students.printTable();
	cout << endl;

	Students.InsertItem(3, "Tanya");
	Students.RemoveItem(2);
	Students.printTable();
	cout << endl;

	cout << Students.Search(1) << endl;
}

