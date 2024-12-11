#include <iostream>

// https://youtu.be/4NYC-VU-svE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// https://youtu.be/ts1Eek5w7ZA?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// https://en.cppreference.com/w/cpp/language/namespace


namespace apple {

	void print(const char* name) {
		std::cout << name << std::endl;
	}

	namespace function {
		void print_again(const char* name) {
			std::cout << "Print Again: " << name << std::endl;
		}
	}
}


int main()
{
	namespace a = apple;

	a::print("Madhawa");
	a::function::print_again("Heshan");



	std::cin.get();
}