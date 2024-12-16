#include <iostream>

// https://youtu.be/PPup1yeU45I?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

class Singleton
{
public:
	static Singleton& get() // one instance of the entire application.
	{
		return s_Instance;
	}

	Singleton(const Singleton&) = delete; // copy constructor disabled.

	void Function() {}

private:

	Singleton() {}

	static Singleton s_Instance;
};

class Random
{
public:
	static Random& get() // one instance of the entire application.
	{
		static Random instance;
		return instance;
	}

	Random(const Random&) = delete; // copy constructor disabled.

	static float Float() { return get().IFloat(); }

private:
	Random() {}

	float IFloat() { return m_RandomGenerator; }
	float m_RandomGenerator = 0.5f;

	
};

Singleton Singleton::s_Instance;

int main()
{
	// Singleton instance = Singleton::Get(); // coping is disabled.
	
	Singleton& instance = Singleton::get();

	float number = Random::Float();
	std::cout << number << std::endl;
}