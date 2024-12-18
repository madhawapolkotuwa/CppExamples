#include <iostream>
#include <vector>

// https://youtu.be/ryRf4Jh_YC0?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

template<typename T>
class Vector
{
public:
	Vector()
	{
		// allocate 2 elements
		ReAlloc(2);
	}

	~Vector()
	{
		Clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}

	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size] = value;
		m_Size++; 
	}

	void PushBack(T&& value) // rvalue reference
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size] = std::move(value);
		m_Size++;
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		new(&m_Data[m_Size]) T(std::forward<Args>(args)...); 
		return m_Data[m_Size++];
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T(); 

		m_Size = 0;
	}

	T& operator[](size_t index) 
	{ 
		return m_Data[index];
	} 

	const T& operator[](size_t index) const
	{
		if (index >= m_Size)
		{
			// assert
		}
		return m_Data[index];
	}

	size_t Size() const { return m_Size; }

private:
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy/move old elements into new block 
		// 3. delete

		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_t i = 0; i < m_Size; i++)
			newBlock[i] = std::move(m_Data[i]);

		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
	for (int i{ 0 }; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}


struct Cordinates
{
	float x{ 0 }, y{ 0 }, z{ 0 };

	Cordinates(){ }

	Cordinates(float x, float y, float z) : x(x), y(y), z(z) {  }

	Cordinates(float scalar) : x(scalar), y(scalar), z(scalar){  }

	Cordinates(const Cordinates& other) : x(other.x), y(other.y), z(other.z) { printf("Copy!\n"); }

	Cordinates(Cordinates&& other) : x(other.x), y(other.y), z(other.z) { printf("Move!\n"); }

	~Cordinates() { printf("Destroy!\n"); }

	Cordinates& operator=(const Cordinates& other) // copy
	{
		printf("Copy!\n");
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Cordinates& operator=(Cordinates&& other) // Move
	{
		printf("Move!\n");
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

};

void PrintVector(const Vector<Cordinates>& vector)
{
	for (int i{ 0 }; i < vector.Size(); i++)
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ", " << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

int main()
{
	//Vector<std::string> vector;

	//vector.PushBack("MP");
	//vector.PushBack("Coding");
	//vector.PushBack("Vector");

	//PrintVector(vector);

	std::cout << "------------------------------------\n";

	Vector<Cordinates> spaceVector;

	spaceVector.PushBack(Cordinates(1.0f, 2.0f, 3.0f));
	spaceVector.PushBack(Cordinates(4.0f));
	spaceVector.PushBack(Cordinates());
	spaceVector.PushBack(Cordinates(2.0f));
	spaceVector.PushBack(Cordinates(1.3f));
	spaceVector.PopBack();
	PrintVector(spaceVector);

	spaceVector.PushBack(Cordinates(1.3f,3.4f,5.6f));
	spaceVector.PushBack(Cordinates(1.7f));
	spaceVector.PopBack();
	PrintVector(spaceVector);


	spaceVector.Clear();


	PrintVector(spaceVector);

	std::cout << "------------------------------------\n";

	return 0;
}