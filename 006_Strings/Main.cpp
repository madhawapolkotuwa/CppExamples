#include <iostream>
#include <string>

#include <stdlib.h>

int main()
{
    const char* name = "Madhawa";

	std::string message = "MP Coding";

	std::cout << message << std::endl;
	message[2] = '_';
	std::cout << message << std::endl;

	bool contains = message.find("MP") != std::string::npos;
	std::cout << contains << std::endl;

	//////////////////////////////////////////////////////////

	const char* name1 = u8"Madhawa";  // 8 bit character strings (1 byte)

	const char16_t* name3 = u"Madhawa"; // 16 bit character strings (2 byte)

	const char32_t* name4 = U"Madhawa"; // 32 bit character strings (4 byte)

	const wchar_t* name2 = L"Madhawa";  // (compiler depends)  wchar_t are all referred to as wide strings

	//////////////////////////////////////////////////////////


	std::string text01 = "Madhawa ";
	std::string text02 = "Heshan ";

	std::string text03 = text01 + text02;

	std::string text04 = std::string("Madhawa ") + "Heshan";

	const char* text05 = R"(Line1
Line2
Line3
Line4)";

	const char* text06 = "Line1\nLine2\nLine3\nLine4";


	std::cout << text05 << std::endl;
	std::cout << text06 << std::endl;



	std::cin.get();
	return 0;
}