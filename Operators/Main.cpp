#include <iostream>
#include <string>

struct Vector2
{
	float x, y;
	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y); // *this + other
	}

	Vector2 operator + (const Vector2& other) const
	{
		return Add(other); // Vector2(x + other.x, y + other.y)
	}

	Vector2 operator * (const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	bool operator == (const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator != (const Vector2& other) const
	{
		return !(*this == other);
	}

	friend std::ostream& operator << (std::ostream& os,const Vector2& v) {
		os << "(" << v.x << "," << v.y << ")" << std::endl;
		return os;
	}
		 
};

int main()
{
	Vector2 p0(3.0f, 4.0f);
	Vector2 p1(2.0f, 4.0f);

	Vector2 speed(0.5f, 1.5f);

	Vector2 result = p0 + p1;
	result = result * speed;

	if (p0 != p1) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}

	std::cout << result << std::endl;
	std::cin.get();
	return 0;
}
