#include <iostream>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0; // set last byte to zero, end of the string
	}

	// String(const String& other) = delete; // if do not want to copy,

	// if want to copy need to create new memory allocation for copy
	String(const String& other) 
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	char& operator[] (unsigned int index)
	{
		return m_Buffer[index];
	}

	~String()
	{
		delete[] m_Buffer;
	}

	friend std::ostream& operator << (std::ostream& os, const String& string) {
		os << string.m_Buffer;
		return os;
	}
};

int main()
{
	String string = "Madhawa";
	String second = string; 

	second[2] = 'D';

	std::cout << string << std::endl;
	std::cout << second << std::endl;

	std::cin.get();
	return 0;
}