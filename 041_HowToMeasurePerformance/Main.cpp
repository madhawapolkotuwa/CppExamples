#include <iostream>

#include <chrono>
#include <array>

// https://youtu.be/YG4jexlSAjc?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

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

// check the perfromance always with release mode 
int main()
{
	int value = 0;
	{
		Timer timer;
		for (int i{ 0 }; i < 100000; i++)
			value += 2;
	}

	std::cout << value << std::endl;

	std::cout << "^------------------------------------^" << std::endl;

	struct Vectoer2
	{
		float x, y;
	};

	std::cout << "^---------Make Shard pointers--------------^" << std::endl;
	{
		std::array<std::shared_ptr<Vectoer2>, 1000> sharedPtrs;
		Timer timer;
		for (int i{ 0 }; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vectoer2>();
	}

	std::cout << "^---------New Shard pointers--------------^" << std::endl;
	{
		std::array<std::shared_ptr<Vectoer2>, 1000> sharedPtrs;
		Timer timer;
		for (int i{ 0 }; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vectoer2>(new Vectoer2());
	}

	std::cout << "^---------Make unique pointers--------------^" << std::endl;
	{
		std::array<std::unique_ptr<Vectoer2>, 1000> sharedPtrs;
		Timer timer;
		for (int i{ 0 }; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vectoer2>();
	}

	return 0;
}