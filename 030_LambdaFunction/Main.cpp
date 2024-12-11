#include <iostream>
#include <string>
#include <vector>
#include <functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	std::vector<int> values = { 1,2,4,3,5,7,9 };

	auto lambda = [](int value) { std::cout << "Values: " << value << std::endl; };

	ForEach(values, lambda);

	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });

	std::cout << *it << std::endl; // 4

	return 0;
}