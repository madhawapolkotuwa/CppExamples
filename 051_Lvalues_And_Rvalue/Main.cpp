#include <iostream>

// lvalue some storage backing them
// rvalue temporary 

int Get_rvalue()
{
	return 10;
}

int& Get_lvalue()
{
	static int value = 10;
	return value;
}

void SetValue(const int& value) // const & accept both lvalue and rvalue
{

}

void PrintName_only_lvalue(std::string& name) // l value
{
	std::cout << name << std::endl;
}

void PrintName_only_rvalue(std::string&& name) // && r value
{
	std::cout << name << std::endl;
}

void PrintName(const std::string& name) // lvalue and rvalue
{
	std::cout << name << std::endl;
}

int main()
{
	int i = 10; // i Left Value | 10 Right Value

	int a = Get_rvalue();

	// Get_rvalue() = 5; // rvalue can't assign

	Get_lvalue() = 3;

	SetValue(i); // lvalue
	SetValue(10); // rvalue

	std::string firstName = "Madhawa";  // lvalue = firstName, rvalue = "Madhawa"
	std::string lastName = "Polkotuwa"; // lvalue = lastName,  rvalue = "Polkotuwa"

	std::string fullname = firstName + lastName; // lvalue = fullname ,rvalue = firstName + lastName

	PrintName_only_lvalue(fullname);
	// PrintName_only_lvalue(firstName + lastName); //error only  lvalue
	// PrintName_only_lvalue("MAdhawa");  //error only  lvalue

	PrintName_only_rvalue(firstName + lastName);
	PrintName_only_rvalue("Madhawa");
	// PrintName_only_rvalue(fullname); // error only rvalue


	PrintName("Madhawa"); // rvalue
	PrintName(fullname);  // lvalue

	return 0;
}