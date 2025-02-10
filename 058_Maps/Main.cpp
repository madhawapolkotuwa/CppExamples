#include <iostream>
#include <string>

#include <vector>
#include <map>

#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;

	// Define equality operator
	bool operator==(const CityRecord& other) const
	{
		return Name == other.Name;
	}
};

namespace std
{
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key) const noexcept
		{
			std::size_t h = hash<string>()(key.Name);
			return h;// let's use name (string)
		}
	};
}

// Custom specialization of std::hash can be injected in namespace std.
//template<>
//struct std::hash<S>
//{
//	std::size_t operator()(const S& s) const noexcept
//	{
//		std::size_t h1 = std::hash<std::string>{}(s.first_name);
//		std::size_t h2 = std::hash<std::string>{}(s.last_name);
//		return h1 ^ (h2 << 1); // or use boost::hash_combine
//	}
//};


int main()
{
	/*std::vector<CityRecord> cities;
	cities.emplace_back("Tokyo", 500000, 2.4, 9.4);
	cities.emplace_back("Osaka", 500000, 2.4, 9.4);
	cities.emplace_back("Kyoto", 500000, 2.4, 9.4);
	cities.emplace_back("Saitama", 500000, 2.4, 9.4);
	cities.emplace_back("Hokkaido", 500000, 2.4, 9.4);*/

	std::map<std::string, CityRecord> cityMap;
	cityMap["Tokyo"] = CityRecord{ "Tokyo", 500000, 2.4, 9.4 };
	cityMap["Osaka"] = CityRecord{ "Osaka", 1236594, 2.4, 9.4 };
	cityMap["Kyoto"] = CityRecord{ "Kyoto", 145875, 2.4, 9.4 };
	cityMap["Saitama"] = CityRecord{ "Saitama", 123695, 2.4, 9.4 };
	cityMap["Hokkaido"] = CityRecord{ "Hokkaido", 1458258, 2.4, 9.4 };

	CityRecord& tokyo = cityMap["Tokyo"];
	std::cout << tokyo.Name << " " << tokyo.Population << std::endl;

	std::cout << "-----------------------------------------\n";
	/////////////////////////////////////////////////////////////////////
	std::unordered_map<std::string, CityRecord> unCityMap;
	unCityMap["Tokyo"] = CityRecord{ "Tokyo", 500000, 2.4, 9.4 };
	unCityMap["Osaka"] = CityRecord{ "Osaka", 1236594, 2.4, 9.4 };
	unCityMap["Kyoto"] = CityRecord{ "Kyoto", 145875, 2.4, 9.4 };
	unCityMap["Saitama"] = CityRecord{ "Saitama", 123695, 2.4, 9.4 };
	unCityMap["Hokkaido"] = CityRecord{ "Hokkaido", 1458258, 2.4, 9.4 };

	CityRecord& citiesAdd = unCityMap["Fukushima"]; // this will add the fukushima to unCityMap

	if (unCityMap.find("Fukushima") != unCityMap.end())
	{
		std::cout << "Fukushima key in unCityMap" << std::endl;
	}

	const auto& cities = unCityMap;

	if (cities.find("Osaka") != cities.end())
	{
		const CityRecord& osaka = cities.at("Osaka");
		std::cout << osaka.Name << " " << osaka.Population << std::endl;
	}

	std::cout << "-----------------------------------------\n";
	//////////////////////////////////////////////////////////////////////
	// 
	//std::unordered_map<CityRecord*, uint32_t> foundedMap; // if we give the Pointer it's already hashable value 
															// no need to provide a custon hash method
	
	// Create an unordered_map with CityRecord as the key
	std::unordered_map<CityRecord, uint32_t> foundedMap; // need to provide the custom hash for CityRecord
	
	foundedMap[CityRecord{ "Melbourne", 584569, 3.36, 12.36 }] = 1290;

	// Access and print the data
	for (const auto& [city, year] : foundedMap)
	{
		std::cout << "City: " << city.Name
			<< ", Founded Year: " << year
			<< '\n';
	}


	

	return 0;
}
