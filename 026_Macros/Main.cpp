#include <iostream>
#include <string>

// https://youtu.be/j3mYki1SrKE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

#define WAIT std::cin.get()

#define OPEN_CURLY {

#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

int main()
{
	if (true)OPEN_CURLY	}

	LOG("Hello");
	
	WAIT;
	return 0;
}