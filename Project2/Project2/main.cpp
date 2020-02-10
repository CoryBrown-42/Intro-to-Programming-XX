#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "Timer.h"
#include <vector>

using namespace std;

double Add(double num1, double num2)
{
	return num1 + num2;
}

void DisplayArray(int arr[], int size)

{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
		cout << endl;

	}
}

//Passing by a reference - add & in front of the parameter
//will be able to cange the original variable 
//otherwise we are passing by value - so the function just has a
//copy of the original
void CapitalizeString(string &inputString)
{
	for (int i = 0; i < inputString.length(); i++)
	{
		inputString[1] = toupper(inputString[i]);
	}
}

int main()
{

	Timer timer;
	srand(time(0)); //seed the random value

	//Creating a vector
	timer.Start;
	vector<int> intVector(1000);
	for (int i = 0; i < 1000; i++)
	{
		intVector.push_back(rand() % 1000);
		DisplayArray(intVector.data(), 1000);
	}
	timer.Stop;
		timer.Report;
	for (int i = 0; i < 100; i++)
	{
		//numArray[i] = rand() % 10000;
	}

	cout << Add(3.14, 2.6) << endl;

	int numArray[100];
	numArray[0] = 3;

	for (int i = 0; i < 100; i++)
	{
		numArray[i] = i;
	}

	DisplayArray(numArray, 100);

	//set string as 'Cory Brown'
	string name = "Cory Brown";
	cout << name << endl;
	CapitalizeString(name);
	cout << name << endl;

	return 0;
}