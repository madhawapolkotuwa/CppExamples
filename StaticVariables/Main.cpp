#include <iostream>

struct Entity
{
	static int s_x; // shared over every Entity
	static int s_y;

	static void ExactPosition()
	{
		std::cout << "(" << s_x << "," << s_y << ")" << std::endl;
	}

	int x, y;

	Entity(int x_pos, int y_pos)
	{
		x = x_pos;
		y = y_pos;
		s_x += x;
		s_y += y;
	}

	void Position()
	{
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}

};

int Entity::s_x;
int Entity::s_y;

int main()
{

	Entity pos1(1, 2);
	pos1.Position();
	Entity::ExactPosition();

	Entity pos2(3, 4);
	pos2.Position();
	Entity::ExactPosition();


	std::cin.get();

	return 0;
}