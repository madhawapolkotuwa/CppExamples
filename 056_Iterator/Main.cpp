#include <iostream>

#include <vector>

#include <unordered_map>

int main()
{
	std::vector<int> intVector = { 1,2,3,4,5 };

	std::cout << "-------------------------------------------\n";

	for (int i = 0; i < intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << "-------------------------------------------\n";

	for(int val : intVector)
		std::cout << val << std::endl;

	std::cout << "-------------------------------------------\n";

	for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
	{
		*it = *it * 2;
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	for (int val : intVector)
		std::cout << val << std::endl;

	std::cout << "-------------------------------------------\n";


	 using ScoreMap = std::unordered_map<std::string, int>; 
	 ScoreMap map;

	 map["Key01"] = 10;
	 map["Madhawa"] = 2;
	 map["Key02"] = 1;

	 for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
	 {
		 auto& key = it->first;
		 auto& value = it->second;

		 std::cout << key << " = " << value << std::endl;

	 }

	 std::cout << "-------------------------------------------\n";

	 for( auto kv : map)
		 std::cout << kv.first << " = " << kv.second << std::endl;

	 std::cout << "-------------------------------------------\n";

	 // C++ 17
	 for (auto [key,value] : map)
		 std::cout << key << " = " << value << std::endl;

	return 0;
}