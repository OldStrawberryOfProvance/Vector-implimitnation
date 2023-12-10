#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	Vector<int> MyVector;

	MyVector.push_back(3);
	MyVector.push_back(5);
	MyVector.push_back(7);

	for (int i = 0; i < MyVector.Size(); ++i)
	{
		cout << MyVector[i];
	}

	MyVector.clear();

	return 0;
}