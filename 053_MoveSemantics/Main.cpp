#include <iostream>

// https://youtu.be/ehMg6zvXuMY?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
// 
// https://youtu.be/OWNeCTd7yQE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other) // copy constuctor
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept // move constructor (rvalue reference)
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator = (String&& other) noexcept
	{
		if (this != &other)
		{
			printf("Assign Move!\n");

			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}

		return *this;
	}

	~String()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i{ 0 }; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name) : m_Name(name)
	{
	}

	Entity(String&& name) : m_Name(std::move(name)) // rvalue constructor ( std::move(name) -> (String&&) name )
	{
	}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};

int main()
{
	{
		Entity entity(String("Madhawa"));
		entity.PrintName();

		std::cout << "---------------------------------\n";

		Entity en("Polkotuwa");
		
		std::cout << "---------------------------------\n";

	}
	std::cout << "---------------------------------\n";

	{
		std::cout << "-----------Copy-----------------\n";
		String string = "Hello";
		String dest = string; // coping
	}

	std::cout << "---------------------------------\n";

	{
		std::cout << "-----------Move-----------------\n";
		String string = "Apple";
		String dest = std::move(string); // (String&&)string
		// String dest(std::move(string)); // same as above
	}
	std::cout << "---------------------------------\n";

	{ // assign operator
		std::cout << "-----------Assign-----------------\n";
		String apple = "Apple";
		String dest;

		std::cout << "apple: ";
		apple.Print();
		std::cout << "dest: ";
		dest.Print();

		dest = std::move(apple);
		
		std::cout << "apple: ";
		apple.Print();
		std::cout << "dest: ";
		dest.Print();

	}



	return 0;
}