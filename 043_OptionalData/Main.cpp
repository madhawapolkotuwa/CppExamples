#include <iostream>
#include <fstream> // for file read write

#include <optional> // 

// std::optional c++ 17
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		
		// read file

		stream.close();
		return result;
	}

	return { }; // std::string();
}

int main()
{
	std::optional<std::string> data = ReadFileAsString("data.txt");

	std::string value = data.value_or("Not present");

	if (data.has_value())
	{
		// for open case
		std::cout << "File opend successfully\n";
		std::cout << value << std::endl;
	}
	else 
	{
		// for not open case
		std::cout << "File not opend\n";
		std::cout << value << std::endl;
	}
	return 0;
}