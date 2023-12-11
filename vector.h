#pragma once
#include <utility>

template <typename T>
class Vector
{
	unsigned int capacity;
	unsigned int size;
	T *pArray;

public:
	Vector()
		: capacity(1),
		  size(0),
		  pArray(nullptr)
	{
	}

	Vector(const Vector& a)
	{
		capacity = a.capacity;
		size = a.size;
		pArray = a.pArray;
	}

	Vector& operator=(const Vector& a)
	{
		capacity = a.capacity;
		size = a.size;
		pArray = a.pArray;
		return this;
	}

	Vector(Vector&& a)
	{
		capacity = std::move(a.capacity);
		size = std::move(a.size);
		pArray = std::move(a.pArray);
	}

	Vector& operator=(Vector&& a)
	{
		capacity = std::move(a.capacity);
		size = std::move(a.size);
		pArray = std::move(a.pArray);
		return *this;
	}

	~Vector()
	{
		delete[] pArray;
	}

	void CreateVector()
	{
		const unsigned int newCapacity = capacity;
		pArray = new T[newCapacity];
	}

	void push_back(const T& value)
	{
		if (!pArray)
		{
			CreateVector();
		}
		else if (size == capacity)
		{
			capacity *= 2;
			const unsigned int newCapacity = capacity;
			T* pArrayCopy = new T[newCapacity];

			for (int i = 0; i < size; ++i)
			{
				pArrayCopy[i] = pArray[i];
			}

			delete[] pArray;
			pArray = pArrayCopy;
		}

		pArray[size] = value;
		size++;
	}


	void pop_back()
	{
		const unsigned int newCapacity = capacity;
		T* pArrayCopy = new T[newCapacity];

		for (int i = 0; i < (size - 1); ++i)
		{
			pArrayCopy[i] = pArray[i];
		}

		delete[] pArray;
		pArray = pArrayCopy;
		}

	bool empty()
	{
		bool check = false;

		return pArray ? check = true : check;
	}

	void clear()
	{
		delete[] pArray;
		pArray = { nullptr };
	}

	int Capasity()
	{
		return capacity;
	}

	int Size()
	{
		return size;
	}

	T Data()
	{
		return pArray;
	}

	T& operator[](T i)
	{
		return pArray[i];
	}
};

