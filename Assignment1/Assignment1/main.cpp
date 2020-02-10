#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

void VerifySort(const vector<int> &vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
		if (vec[i] > vec[i + 1])
		{
			cout << "Not Sorted" << endl;
			return;
			//break;//would leave the loop, not the function
		}

	cout << "Sorted! Yay!" << endl;
}

void Swap(int &num1, int &num2)//O(1)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void BubbleSort(vector<int> &vec)//O(n^2)
{
	for (int k = 0; k < vec.size(); ++k)
		for (int i = 0; i < vec.size() - 1; ++i)
			if (vec[i] > vec[i + 1])
				Swap(vec[i], vec[i + 1]);
}

void SelectionSort(vector<int> &vec)//O(n^2)
{
	for (int k = 0; k < vec.size(); ++k)
	{
		int maxIndex = 0;
		for (int i = 1; i < vec.size() - k; ++i)
		{
			if (vec[i] > vec[maxIndex])
				maxIndex = i;
		}
		Swap(vec[maxIndex], vec[vec.size() - k - 1]);
	}
}


void InsertionSort(vector<int> &vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		int j = i;
		while (j > 0 && vec[j] < vec[j - 1])
		{
			Swap(vec[j], vec[j - 1]);
			j--;
		}
	}
}

void DisplayArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int SearchVector(vector<int> vec, int value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void FindTheFirstAndThird(int arr[], int size)
{
	for (int i = 0; i< size; i++)
	{
		int picked;
		for (picked = 0; picked < i; picked++)
		{
			if (arr[i] == arr[picked])
			{
				break;
			}
		}
	}
	//finding the first largest value
	int firstHigh = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > firstHigh)
		{
			firstHigh = arr[i];
		}
	}
	int secondHigh = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > secondHigh && arr[i] < firstHigh)
		{
			secondHigh = arr[i];
		}
	}
	// Find third largest
	int thirdHigh = INT_MIN; //macro
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > thirdHigh && arr[i] < secondHigh)
		{
			thirdHigh = arr[i];
		}
	}
	cout << endl;
	cout << "The first largest value in the Array: " << firstHigh << endl;
	cout << endl;
	cout << "The third largest value in the Array: " << thirdHigh << endl;
	cout << endl;

}

void QuickSort(vector<int> &vec)
{
	
}

void MergeSort(vector<int> & vec)
{

}

int main()
{

	cout << "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "*************************Assinment 1****************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl;


	/********* 1. Vector ***********/

	vector<int> myVector(1000);
	myVector[0] = 1;
	for (int i = 0; i < 1000; i++)
	{
		myVector[i] = rand() % 2018;
	}
	DisplayArray(myVector.data(), 1000);
	cout << endl;
	cout << "This is an example of a vector containing 1000 random numbers" << endl;
	cout << endl;

	/********** 1. Array ************/

	srand(time(0));
	int myArray[1000];
	myArray[0] = 0;
	for (int i = 0; i < 1000; i++)
	{
		myArray[i] = rand() % 2018;
	}
	DisplayArray(myArray, 1000);
	cout << endl;
	cout << "This is an example of an array containing 1000 random numbers" << endl;
	cout << endl;


	/********* 2. Search the Array ***********/

	int largest = myArray[1000];
	SearchVector(myVector, 1000);

	int g = sizeof(myArray) / sizeof(myArray[0]);
	FindTheFirstAndThird(myArray, g);

	/********* 4. Sort the original Array ***********/

	size_t size = sizeof(myArray) / sizeof(myArray[0]);
	sort(myArray, myArray + size);
	for (size_t i = 0; i < size; ++i)
	{
		//display the sorted array
		cout << myArray[i] << ", ";
	}
	cout << endl << endl << "This is the same Array sorted" << endl;

	/********* 4. Third Largest of the sorted ***********/

	/********* 5. Which  ***********/


	FindTheFirstAndThird(myArray, g);
	cout << endl;
	/*

	I don't think sorting it really matters in this case because when looking at the individual values
	the third largest is always going to be the third largest no matter which order they are in.
	I think the function that finds the third value could also be used to describe the highest value.

	*/

	cout << "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "*************************Assinment 2****************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl
		<< "****************************************************************" << endl;

	int n = 1000;
	vector<int> numSet;

	for (int i = 0; i < n; i++)
	{
		numSet.push_back(rand() % 1000);
	}

	vector<int> vecToSort = numSet;
	VerifySort(vecToSort);
	cout << endl << "Bubble Sort: " << endl;
	BubbleSort(vecToSort);
	cout << "Selection Sort: " << endl;
	vecToSort = numSet;
	SelectionSort(vecToSort);
	VerifySort(vecToSort);

	return 0;

}
