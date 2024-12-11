#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;

}

void PrintA(int a) 
{
	std::cout << "A = " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}	

int main()
{
	HelloWorld();

	auto function = HelloWorld; // void(*function)()
	function();

	typedef void(*HwFun)();
	HwFun fun = HelloWorld;
	fun();

	typedef void(*A)(int);
	A A1 = PrintA;
	A1(2);

	std::cout << "-----------------------------------" << std::endl;

	std::vector<int> values = { 1,2,3,4,5 };

	ForEach(values, PrintValue);

	std::cout << "-----------------------------------" << std::endl;

	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; }); // Lambda function;

	return 0;
}