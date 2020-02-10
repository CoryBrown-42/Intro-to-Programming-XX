#include <iostream>

using namespace std;

void DisplayArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main()
{
	int myArray[1000];

	myArray[0] = 1;

	for (int i = 0; i < 1000; i++)
	{
		myArray[i] = i;
	}

	DisplayArray(myArray, 1000);

	system("pasue");

	return 0;
}