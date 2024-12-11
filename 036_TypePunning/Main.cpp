#include <iostream>

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50; // 32 00 00 00
	double value = *(double*)&a; // 32 00 00 00 cc cc cc cc 
								 // 4byte (integer) memory passed to 8bytes (double) memory

	std::cout << value << std::endl;

	Entity e{ 5, 8 };

	int* position = (int*)&e; // Entity converted to int array

	std::cout << position[0] << ", " << position[1] << std::endl;

	int y = *(int*)((char*)&e + 4); // get entity refrence(&e), convert it to char pointer (1 byte) 
									// jump to 4bytes convert it to integer pointer and dereference it.

	std::cout << y << std::endl;

	return 0;
}