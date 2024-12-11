#include <iostream>
#include <fstream>
#include <sstream>
#include <future>
#include <chrono>
#include <vector>

// https://youtu.be/5HWCsmE9DrE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

class Timer
{
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;

	void Stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;

		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms)\n";
	}
};

static std::mutex s_Mutex;
std::vector<std::future<void>> m_Futures;

class Entity
{
	std::vector<std::string> m_StringVector;
	
public:
	bool LoadFile(const std::string& filename)
	{
		std::ifstream stream(filename);

		if (!stream.is_open()) {
			std::cout << "Failed to open file: " << filename << std::endl;
			return false;
		}
#define ASYNC 1
#if ASYNC
		// parallel for loop
		for (int i{ 0 }; i < 1000; i++) // read multiple times same file with multi thread
		{
			m_Futures.push_back(std::async(std::launch::async, LoadStrings, &m_StringVector, filename));
		}
#else

		for (int i{ 0 }; i < 1000; i++) // read multiple times same file
		{
			std::ifstream file(filename);
			std::string line;
			std::stringstream tempBuffer;
			tempBuffer << file.rdbuf(); // Read the entire file into the buffer
			m_StringVector.push_back(tempBuffer.str());
		}
#endif
		return true;
	}

	std::vector<std::string> GetStrings()
	{
		return m_StringVector;
	}

	static void LoadStrings(std::vector<std::string> *strVector, std::string filename)
	{
		std::lock_guard<std::mutex> lock(s_Mutex);
		std::ifstream file(filename);
		std::string line;
		if (file.is_open())
		{
			std::stringstream tempBuffer;
			tempBuffer << file.rdbuf();
			strVector->push_back(tempBuffer.str());
		}
	}

};

int main()
{
	Entity entity;

	{
		Timer timer;
		if (entity.LoadFile("data.txt")) 
		{
			std::cout << "Loading Ok....." << std::endl;
		}
	}

	int keyPressed{0};
	while (true) 
	{
		keyPressed = std::cin.get();
		if (keyPressed == 10)
			break;
	}

	//for (auto str : entity.GetStrings())
	//{
	//	std::cout << str << std::endl;
	//}

	return 0;
}