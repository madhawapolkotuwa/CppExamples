#include <iostream>
#include <vector>

// https://youtu.be/HcESuwmlHEY?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z)
		: x(x), y(y), z(z){}

	Vertex(const Vertex& vertex) // copy constuctor
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!!" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> v1;

	v1.push_back(Vertex(1,2,1)); // first construct vertex then push pack to array creating new memory for array element (more coping)
	v1.push_back({ 4,5,6 });
	v1.push_back({ 7,8,9 });

	std::cout << "___________________________________________" << std::endl;

	std::vector<Vertex> v2;

	v2.reserve(3); // first we reserve the memory for array,
	v2.push_back({ 1,2,3 });
	v2.push_back({ 4,5,6 });
	v2.push_back({ 3,6,2 });

	std::cout << "___________________________________________" << std::endl;

	std::vector<Vertex> v3;

	v3.emplace_back(1, 2, 3); // pass the parameter list to constructor
	v3.emplace_back(4, 5, 6); // 
	v3.emplace_back(3, 6, 2);


	std::cout << "___________________________________________" << std::endl;
	
	std::vector<Vertex> v4;

	v4.reserve(3); // no more copies
	v4.emplace_back(1, 2, 3); // pass the parameter list to constructor
	v4.emplace_back(4, 5, 6); 
	v4.emplace_back(3, 6, 2);

	std::cout << "_________________END________________________" << std::endl;
}