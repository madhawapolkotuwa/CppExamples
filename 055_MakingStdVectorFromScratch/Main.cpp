#include <iostream>

// https://youtu.be/ryRf4Jh_YC0?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
// https://youtu.be/F9eDv-YIOQ0

template<typename V>
class VectorIterator
{
public:
	using ValueType = typename V::ValueType; // if V -- Vector<int>, ValueType -- int
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType ptr) : m_Ptr(ptr){}

	VectorIterator& operator++()
	{
		m_Ptr++; // increment correct amount of bytes
		return *this;
	}

	VectorIterator operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	VectorIterator& operator--()
	{
		m_Ptr--; // increment correct amount of bytes
		return *this;
	}

	VectorIterator operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	ReferenceType operator[] (int index)
	{
		// return *(m_Ptr[index]);
		return *(m_Ptr + index); // same as above jump to correct amount of bytes
	}

	PointerType operator->()
	{
		return m_Ptr;
	}

	ReferenceType operator*()
	{
		return *m_Ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}

private:
	PointerType m_Ptr;
};

template<typename T>
class Vector
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;

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

	Iterator begin()
	{
		return Iterator(m_Data); // begging of the m_Data memory block
	}

	Iterator end()
	{
		return Iterator(m_Data + m_Size); // 1st byte of memory outside of the m_Data allocation
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
			new(&newBlock[i]) T(std::move(m_Data[i]));

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
#if 0
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
#endif


#if 1

	std::cout << "---------------Iterator------------------\n";

	Vector<std::string> values;

	values.EmplaceBack("1");
	values.EmplaceBack("2");
	values.EmplaceBack("3");
	values.EmplaceBack("madhawa");
	values.EmplaceBack("5");

	std::cout << "Not using iterators:\n";
	for (int i = 0; i < values.Size(); i++)
		std::cout << values[i] << std::endl;


	std::cout << "Iterator:\n"; 
	for (Vector<std::string>::Iterator it = values.begin(); it != values.end(); it++) 
		std::cout << *it << std::endl; 

	std::cout << "Range-base for loop:\n"; 
	for (auto value : values)
	{ 
		std::cout << value << std::endl;
	}


#endif

	return 0;
}