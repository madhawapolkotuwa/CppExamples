// https://youtu.be/kQsHF7C-FUY

#include <iostream>
#include <string>
#include <sstream>

class HashTable
{
	struct Entry
	{
		std::string Data;
		std::string Status = "nerver used";
	};

public:
	static const int Size = 26;

public:
	HashTable() = default;

	void Print()
	{
		for (int i = 0; i < Size; i++)
		{
			if(m_Entries[i].Status == "occupied")
				std::cout << m_Entries[i].Data << ' ';
			//std::cout << m_Entries[i].Data << "(" << m_Entries[i].Status << ")" << std::endl;
		}
		std::cout << std::endl;
	}

	void Add(const std::string& entryString)
	{
		bool exists = Find(entryString);
		if (exists)
			return;

		int insertIndex = GetInsertIndex(entryString);
		m_Entries[insertIndex].Data = entryString;
		m_Entries[insertIndex].Status = "occupied";
	}

	void Delete(const std::string& entryString)
	{
		int index;
		bool exists = Find(entryString, &index);
		if (!exists)
			return;

		m_Entries[index].Status = "tombstone";

	}
private:
	int GetIndex(const std::string& entryString)
	{
		return entryString.back() - 'a'; // a - 97 ... a = 0, b = 1, c = 2 .... z = 25
	}

	bool Find(const std::string& entryString, int* outIndex = nullptr)
	{
		int index = GetIndex(entryString);
		while (true)
		{
			if (m_Entries[index].Data == entryString)
			{
				if(outIndex)
					*outIndex = index;
				return true;
			}
			if (m_Entries[index].Status == "nerver used")
				return false;

			index = (index + 1) % Size; // after 25 it comes to 0
		}

		return false;
	}

	int GetInsertIndex(const std::string& entryString)
	{
		int index = GetIndex(entryString);
		while (true)
		{
			if (m_Entries[index].Status == "nerver used" || m_Entries[index].Status == "tombstone")
				return index;

			index = (index + 1) % Size; // after 25 it comes to 0
		}

		return -1;
	}

private:
	Entry m_Entries[Size];
};

int main()
{
	// in- Aapple Aorange Dapple Astrawberry ... A - add  D - Delete
	// out- orange strawberry

	// in - Daa Daaa Aaa Aaaa Aaaaaa Daaa Daa Aa Daaaaaaa Aaaaaaa
	// out - aa aaa aaaaa a aaaaaa
	
	std::string input;
	getline(std::cin,input);
	
	HashTable hashTable;

	std::stringstream ss(input);


	while (ss.good())
	{
		std::string token;
		ss >> token;

		//std::string entryName = &token[1];
		std::string entryName = token.substr(1); 
		if (token[0] == 'A')
		{
			hashTable.Add(entryName);
			//std::cout << "Add -" << entryName << std::endl;
		}
		else if (token[0] == 'D')
		{
			hashTable.Delete(entryName);
			//std::cout << "Delete -" << entryName << std::endl;
		}
	}

	hashTable.Print();

	return 0;
}