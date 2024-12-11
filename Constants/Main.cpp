#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
	int* m_ptrX;

	mutable int var;

public:
	int GetX() const // (Readonly)
	{
		// m_X = 2; // error canot modify the values of the class using const methods
		var = 2;    // mutable can be modify int the const methods
		return m_X;
	}

	int GetX_A() 
	{
		return m_X;
	}

	const int* const GetX_ptr() const
	{
		return m_ptrX; // Pointer can't modify, content of the pointer can't modify, method it self can't be modify the class content;
	}
};

void PrintEntity(const Entity& e)
{
	// int x = e.GetX_A(); // error reference only allows access to the const methods, 
						   // Because actually, reference means it's the original object not a copy of the object
	                       // the normal method can change the values of the object itself.
	std::cout << e.GetX() << std::endl;
}

int main() {

	const int MAX_AGE = 90;

	int a = MAX_AGE;

	const int* const_ptr_a = &MAX_AGE;

	// const_ptr_a = a; // error
	// *const_ptr_a = 2; // error

	int* const ptr_const_a = new int;

	*ptr_const_a = *const_ptr_a;

	std::cout << "ptr_const_a: " << *ptr_const_a << std::endl;

	const int* const const_ptr_const_a = new int(21);

	std::cout << "const_ptr_const_a: " << *const_ptr_const_a << std::endl;


	return 0;
}