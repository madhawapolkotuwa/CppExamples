#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() 
{
	using namespace std::literals::chrono_literals;

	while (!s_Finished) {
		std::cout << "Working....\n";
		std::this_thread::sleep_for(1s);
	}
}

int main() {

	std::thread worker(DoWork);

	std::cin.get();
	s_Finished = true;

	worker.join(); // like C# wait (ayncy functions)

	std::cout << "Finished!!" << std::endl;
	std::cin.get();
}
