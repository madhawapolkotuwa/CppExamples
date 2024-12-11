#include <iostream>
#include <array>

class MyClass
{
public:
	static const int exSize = 5;

	std::array<int, exSize> ex;
};

int main()
{
	int example[5];
	int* ptr = example; // Array is actualy a pointer

	example[2] = 5; //   
	*(ptr + 2) = 5; // both are same (Jump to positons of sizeof(int) = 8 bytes  )
	*(int*)((char*)ptr + 8) = 5; // char size = one Byte 
	// (char*)ptr convert to char pointers, (+ 8) add 8 bytes, (int*) convert to int pointer, * and dereferenced and set value 5 

	for (int i{ 0 }; i < 5; i++)
	{
		example[i] = i;
	}

	int* onother = new int[5]; // This memory for 5 integers is allocated on heap memory.

	delete[] onother;
	onother = NULL; // free heap

	MyClass myClass;

	for (int i{ 0 }; i < myClass.ex.size(); i++)
		myClass.ex[i] = 1;

	for (int i{0}; i < MyClass::exSize; i++)
		myClass.ex[i] = 1;


	return 0;
}