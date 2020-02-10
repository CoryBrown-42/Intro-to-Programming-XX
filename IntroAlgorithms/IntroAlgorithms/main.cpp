#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>

#include "Timer.h"

using namespace std;

double Add(double num1, double num2)//1
{//function body
	return num1 + num2;
}

double Add2(double num1, double num2)//3
{
	int result;
	result = num1 + num2;
	return result;
}

int SearchVector(vector<int> vec, int value)
{
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == value)
			return i;
	return -1;
}

void DisplayArray(int arr[], int size)//4n + 1
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";

	}
	
	cout << endl;
}

void OutputGrid(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

//Passing by reference - add & in front of the parameter
//will be able to change the original variable
//Otherwise we are passing by value - so the function just has a 
//copy of the original value
void CapitalizeString(string &inputString)
{
	for (int i = 0; i < inputString.length(); i++)
		inputString[i] = toupper(inputString[i]);
}

int main()
{
	OutputGrid(100);

	srand(time(0));//Seed the random value

	Timer timer;

	cout << Add(3.14, 2.6) << endl;

	int n = 100000;
	cout << "Testing a vector with pushback" << endl;
	vector<int> intVector;
	timer.Start();
	for (int i = 0; i < n; i++)
		intVector.push_back(rand() % 1000);
	timer.Stop();
	timer.Report();
	
	cout << "Testing a vector without pushback" << endl;
	vector<int> intVector2(n); 
	timer.Start();
	for (int i = 0; i < n; i++)
		intVector2[i] = (rand() % 1000);
	timer.Stop();
	timer.Report();

	cout << endl << endl;
	//DisplayArray(intVector.data(), 1000);

	int numArray[100];
	numArray[0] = 3;

	timer.Start();
	for (int i = 0; i < 100; i++)
	{
		numArray[i] = rand() % 1000;
	}
	timer.Stop();
	timer.Report();

	timer.Start();
	DisplayArray(numArray, 100);
	timer.Stop();
	timer.Report();

	string name = "Joe Bob";
	cout << name << endl;
	CapitalizeString(name);
	cout << name << endl;

	return 0;
}