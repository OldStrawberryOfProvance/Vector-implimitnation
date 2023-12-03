#pragma once

template <typename T>
class vector
{
	int capacity;
	int size;
	T buffer;
	T *pArray;

public:
	vector()
	{
		capacity = { 1 };
		size = { 0 };
		buffer = { 0 };
		*pArray = { nullptr };
	}

	vector(const vector& a)
	{

	}

	vector& operator=(const vector& a)
	{

	}

	vector(vector&& a)
	{

	}

	vector& operator=(vector&& a)
	{

	}

	~vector()
	{
		delete[] pArray;
	}

	void push_back(T value)
	{
		if (pArray)
		{
			pArray = new T[capacity];
			pArray[size] = value;
			size++;
		}
		else if (size == capacity)
		{
			capacity *= 2;
			T* pArrayCopy = new T[capasity];

			for (int i = 0; i < size; ++i)
			{
				pArrayCopy[i] = pArray[i];
			}
			pArrayCopy[size + 1] = value;
			delete[] pArray;

			pArray = new T[capacity];
			for (int i = 0; i < size; ++i)
			{
				pArray[i] = pArrayCopy[i];
			}

			size++
			delete[] pArrayCopy;
		}
		else if (size < capacity)
		{
			pArray[size + 1] = value;
			size++;
		}
	}

	void pop_back()
	{
		T* pArrayCopy = new T[capascity];

		for (int i = 0; i < (size - 1); ++i)
		{
			pArrayCopy[i] = pArray[i];
		}
		delete[] pArray;


		pArray = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			pArray[i] = pArrayCopy[i];
		}

		delete[] pArrayCopy;
		}

	void empty()
	{
		bool check = {false};
		if (!pArray)
		{
			check = true;
			cout << check << endl;
		}
		else
		{
			cout << check << endl;
		}
	}

	void clear()
	{
		~vector();
		pArray = { nullptr };
	}

	void capasity()
	{
		cout << "capacity is " << capacity << endl;
	}

	void size()
	{
		cout << "size is " << size << endl;
	}

	void data()
	{
		return *pArray;
	}

	T& operator[](T i)
	{
		return pArray[i];
	}
};

