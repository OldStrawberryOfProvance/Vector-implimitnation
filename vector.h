#pragma once

template <typename T>
class Vector
{
	int capacity;
	int size;
	T buffer;
	T *pArray;

public:
	Vector()
		: capacity(1),
		  size(0),
	  	  buffer(0),
		  pArray(nullptr)
	{
	}

	Vector(const Vector& a)
	{
		capacity = a.capacity;
		size = a.size;
		buffer = a.buffer;
		pArray = a.pArray;
	}

	Vector& operator=(const Vector& a)
	{
		capacity = a.capacity;
		size = a.size;
		buffer = a.buffer;
		pArray = a.pArray;
		return this;
	}

	Vector(Vector&& a)
	{
		capacity = std::move(a.capacity);
		size = std::move(a.size);
		buffer = std::move(a.buffer);
		pArray = std::move(a.pArray);
	}

	Vector& operator=(Vector&& a)
	{
		capacity = std::move(a.capacity);
		size = std::move(a.size);
		buffer = std::move(a.buffer);
		pArray = std::move(a.pArray);
		return *this;
	}

	~Vector()
	{
		delete[] pArray;
	}

	void CreateVector()
	{
		pArray = new T[capacity];
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
			T* pArrayCopy = new T[capañity];

			for (int i = 0; i < size; ++i)
			{
				pArrayCopy[i] = pArray[i];
			}
			size++;

			delete[] pArray;
			pArray = pArrayCopy;
		}

		pArray[size] = value;
		size++;
	}


	void pop_back()
	{
		T* pArrayCopy = new T[capacity];

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

	int capasity()
	{
		return capacity;
	}

	int size()
	{
		return size;
	}

	T data()
	{
		return pArray;
	}

	T& operator[](T i)
	{
		return pArray[i];
	}
};

