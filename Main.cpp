#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "Array.h"

using namespace std;

int main()
{
	Array<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23);
	array.push(82);

	array[2] = 112;

	array.pop();
	array.remove(2);

	cout << "Unordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << "Search for 53 was found at index: ";
	cout << array.search(53);

	cout << endl << endl;


	return 0;
}

/*

int main()
{
	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23);
	array.push(83);

	array[2] = 112;

	array.pop();
	array.remove(2);

	cout << "Ordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << "Search for 53 was found at index: ";
	cout << array.search(53);

	cout << endl << endl;


	return 0;
}

*/