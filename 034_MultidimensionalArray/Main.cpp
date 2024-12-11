#include <iostream>

int main()
{
	int* array = new int[50];
	int** a2d = new int* [50]; // 50 pointers to point to arrays can contain the 50 integers
	// these two are the same memory 4byte * 50 = 200 bytes of memory
	// just allocation of the memory
	
	array[0] = 1;

	a2d[0] = nullptr;

	for (int i{ 0 }; i < 50; i++) 
		a2d[i] = new int[50]; // allocation of 50 integer arrays

	a2d[0][0] = 1;

	// 3 dementional array
	int*** a3d = new int** [50]; // *** pointer to pointer to pointer
	for (int i{ 0 }; i < 50; i++) 
	{
		a3d[i] = new int* [50];
		
		for (int j{ 0 }; j < 50; j++) 
		{
			a3d[i][j] = new int[50]; // int** ptr = a3d[i]; ptr[j] = new int[50];
		}
	}

	a3d[0][0][0] = 1;


	// free memory
	delete[] array;
	
	for (int i{ 0 }; i < 50; i++)
		delete[] a2d[i];
	delete[] a2d;

	for (int i{ 0 }; i < 50; i++)
	{
		for (int j{ 0 }; j < 50; j++)
		{
			delete[] a3d[i][j]; 
		}
		delete[] a3d[i];
	}
	delete[] a3d;

	return 0;
}