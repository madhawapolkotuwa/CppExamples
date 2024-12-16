#include <iostream>
#include <memory>

// https://youtu.be/sLlGEUO_EGE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t Totalfreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - Totalfreed; }
};

static AllocationMetrics s_AllocatedMetrics;

void* operator new(size_t size) // overload new keyword
{
	//std::cout << "Allocating " << size << " Bytes\n";
	s_AllocatedMetrics.TotalAllocated += size;
	return malloc(size);
}

void PrintUsage()
{
	std::cout << "Memory Usage: " << s_AllocatedMetrics.CurrentUsage() << std::endl;
}

void operator delete(void* memory, size_t size)
{
	//std::cout << "Freeing " << size << " Bytes\n";
	s_AllocatedMetrics.Totalfreed += size;
	free(memory);
}

struct Object 
{
	int x, y, z;
};

int main()
{
	std::string name = "madhawa Heshan Polkotuwa";
	PrintUsage();

	Object* obj = new Object; // Heep allocation
	PrintUsage();

	delete obj;
	PrintUsage();

	{
		std::unique_ptr<Object> u_ptr = std::make_unique<Object>();
		PrintUsage();
	}

	PrintUsage();

	return 0;
}