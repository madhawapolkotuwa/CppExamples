#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4 
{
	union  // occupying the same memory (same member) ; set the memory to largest valriable size;
	{
		struct 
		{
			float x, y, z, w;
		};

		struct
		{
			Vector2 a, b; // a=(x,y) b=(z,w)
		};
	};
};

void PrintVector2(const Vector2& vector) 
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}


int main()
{
	Vector4 vector{ 1.1f,2.2f,3.3f,5.5f };
	
	std::cout << vector.x << std::endl;

	PrintVector2(vector.a);
	PrintVector2(vector.b);

	vector.z = 500.1f;
	std::cout << "----------------------------" << std::endl;

	PrintVector2(vector.a);
	PrintVector2(vector.b);
	return 0;
}