#include <iostream>
#include <array>

// https://youtu.be/TzB5ZeKQIHM?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
// 
// Stack Allocation Array

template<typename T,size_t S>
class Array
{
public:
	constexpr int Size() const { return S; }

	T& operator[](size_t index) { return m_Data[index]; }

	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }

private:
	T m_Data[S];
};

// int* m_Data;
// m_Data = (int*)alloca(size * sizeof(int)); // alloca is the function allow us to allocate memory on the stack

int main()
{
	int array[5]; // Stack Allocation Array

	int size = 5;
	int* heapArray = new int[size]; // heap array

	delete[] heapArray;

	// std::array

	std::array<int, 5> collection;

	for (auto value : collection)
	{
		// std::cout << value << std::endl;
	}

	////////////////////////////////////////////////////////

	Array<int,5> data;

	// static_assert(data.Size() < 10, "Size is too large!");

	for (int i{ 0 }; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	// set all of the memory to zero
	memset(data.Data(), 0, data.Size() * sizeof(int));
	// memset(&data[0], 0, data.Size() * sizeof(int)); // same as above

	for (int i{ 0 }; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	const auto& arrayReference = data;
	for (int i{ 0 }; i < data.Size(); i++)
	{
		std::cout << arrayReference[i] << std::endl;
	}

	
	return 0;
}