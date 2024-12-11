#include <iostream>

class Base
{
public:
	Base() {  }
	virtual ~Base() {  }
};

class Derived : public Base
{
public:
	Derived() { }
	~Derived() { }
};

class AnotherClass : public Base
{
public:
	AnotherClass() {};
	~AnotherClass() {};
};


int main()
{

	double value = 5.43;
	double a = (int)value + 5.3;

	std::cout << a << std::endl;
	std::cout << "-------------------------" << std::endl;

	a = static_cast<int>(value) + 5.3;
	std::cout << a << std::endl;
	std::cout << "-------------------------" << std::endl;


	Derived* derived = new Derived();
	Base* base = derived;

	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
	// AnotherClass* ac = static_cast<AnotherClass*>(base); // static cast not allowd do this kind of cast
	if (!ac) 
	{
		std::cout << "Not correct convertion...!" << std::endl;
	}
	else {
		std::cout << "correct convertion" << std::endl;
	}

	std::cout << "-------------------------" << std::endl;
	Derived* dr = dynamic_cast<Derived*>(base); // dynamic cast is good for, check converion works or not
	if (!dr)
	{
		std::cout << "Not correct convertion...!" << std::endl;
	}
	else {
		std::cout << "correct convertion" << std::endl;
	}

	delete derived;

	return 0;
}