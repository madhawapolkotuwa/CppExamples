#include <iostream>
#include <memory>

class Entity
{
public:
	Entity() {
		std::cout << "Ctreated Entity!" << std::endl;
	}

	~Entity() {
		std::cout << "destroyed Entity!" << std::endl;
	}

	void Print() { std::cout << "Hello world!" << std::endl; }
};

int main()
{
	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // smart pointer stack allocated object
		//std::unique_ptr<Entity> e0 = entity // error can't copy unique pointers
		entity->Print();

	}

	std::cout << "================================" << std::endl;

	{
		std::shared_ptr<Entity> e0; 
		std::cout << "==============e0 start===============" << std::endl;
		{
			std::shared_ptr<Entity> entity = std::make_shared<Entity>(); 
			e0 = entity; // this will increse the ref count

			std::weak_ptr<Entity> weekPtr = entity; // this will not increase the ref count (just ref to original the shared pointer) if it's precent can be call, if destoyed can't be call
		}
		std::cout << "==============e0 end===============" << std::endl; // all the shared pointers gone, shared_ptr will destroy
	}

	return 0;
}