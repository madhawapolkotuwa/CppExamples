#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> values = { 1,3,6,2,7,9,4,0,5 };

	std::sort(values.begin(), values.end());

	for (auto value : values)
	{
		std::cout << value << std::endl;
	}

	std::cout << "----------------------------------" << std::endl;
	std::sort(values.begin(), values.end(), std::greater<int>());

	for (auto value : values)
	{
		std::cout << value << std::endl;
	}

	std::cout << "----------------------------------" << std::endl;

	std::sort(values.begin(), values.end(), [](int a, int b) {
		if (a == 1)
			return false;
		if (b == 1)
			return true;
		return a < b;
		});

	for (auto value : values)
	{
		std::cout << value << std::endl;
	}

	return 0;
}

