#include <iostream>
#include <thread>
#include <chrono>

void Function(int& i, bool& isRun)
{
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(1s);

	i++;
	// debug break point with condition, log in the Debug output console

	if (i > 10) {
		isRun = false;
	}

}

int main()
{
	bool isRun{ true };
	int i{ 0 };

	while (isRun)
	{
		Function(i, isRun);
		std::cout << "i = " << i << std::endl;
	}
	
	return 0;
}