#include <iostream>

#include <variant> 

// with c++ 17
int main()
{
	std::variant<std::string, int> data;
	
	data = "Madhawa";
	std::cout << std::get<std::string>(data) << "\n";

	data = 30;
	std::cout << std::get<int>(data) << "\n";

	data = "Set to String";
	// data = 12; // set to integer;

	if (auto value = std::get_if<std::string>(&data))
	{
		std::string& v = *value;
		std::cout << v << std::endl;
	}
	else {
		std::cout << "data variant, is not string\n";
	}

	std::cout << sizeof(int) << "\n";
	std::cout << sizeof(std::string) << "\n";
	std::cout << sizeof(data) << "\n";


	return 0;
}