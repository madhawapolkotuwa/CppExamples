#include <iostream>

#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator << (std::ostream& os, const Vertex& vertex)
{
	os << "(" << vertex.x << "," << vertex.y << "," << vertex.z << ")";
	return os;
}

void Function(const std::vector<Vertex>& vertices) // make sure to pass as the reference, not the coping (std::vector<Vertex>)
{

}

int main()
{
	std::vector<Vertex> vertices;

	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });

	for (int i{ 0 }; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	std::cout << "__________________________________" << std::endl;

	for (const Vertex& v : vertices)
		std::cout << v << std::endl;
	
	std::cout << "__________________________________" << std::endl;

	vertices.erase(vertices.begin() + 1); // erase 2nd element of vertices

	for (const Vertex& v : vertices)
		std::cout << v << std::endl;

	Function(vertices);

	std::cin.get();

}