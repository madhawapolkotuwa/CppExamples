#include <iostream>
#include <string>


template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}

template<typename T, int N> // this is similar to the standard library of C++ array
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

int main()
{
	Print("Madhawa");
	Print(30);
	Print(1.3f);
	Print<float>(1.5f);

	Array<std::string, 10> array;
	std::cout << array.GetSize() << std::endl;

	return 0;
}