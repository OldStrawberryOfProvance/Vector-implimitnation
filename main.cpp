#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	Vector<int> MyVector;

	cout << MyVector.push_back(3);
	cout << MyVector.push_back(5);
	cout << MyVector.push_back(7);

	MyVector.clear();

	return 0;
}