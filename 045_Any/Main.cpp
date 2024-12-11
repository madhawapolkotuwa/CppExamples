#include <iostream>

#include <any>

// https://youtu.be/7nPrUBNGRAk?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// with c++ 17
int main()
{
	std::any data; // std::variant is better than this,

	data = 2;
	data = "Madhawa";
	data = 2.2;

	data = std::string("test string");

	auto value = std::any_cast<std::string>(data); // if not throw the expection

	return 0;
}