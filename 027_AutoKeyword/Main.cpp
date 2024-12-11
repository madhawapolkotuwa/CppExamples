#include <iostream>
#include <string>

#include <vector>
#include <unordered_map>


class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Device;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevice() const
	{
		return m_Device;
	}
};

int main()
{
	int a = 5;
	auto b = a;


	std::vector<std::string> strings { "Apple", "Orange", "Mango" };

	for (std::vector<std::string>::iterator it = strings.begin();
		it != strings.end(); it++) 
	{

		std::cout << *it << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;

	for (auto it = strings.begin(); it != strings.end(); it++) 
	{

		std::cout << *it << std::endl;
	}

	DeviceManager dm;

	const auto& device = dm.GetDevice();

	std::cin.get();
}