//============================================================================
// Name        : Lab4Pointers.cpp
// Author      : Nicholas Requena
// Version     : 0.1
// Description : An input driven dynamic array, that prints the numbers put
//				 into the array. It also prints the min, max, and average.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

float FindMin(float Array[], int counter);
float FindMax(float Array[], int counter);
float FindAverage(float Array[], int counter);

int main() {
	float *UsrInputPtr = new float[100];
	float *NumStartPtr = new float[100];
	int counter = 0;

	cout << "Dynamic Array:\n Type a number, and then press ENTER" << endl;
	cout << "(Type 999999 to finish)" << endl;
	cin >> *UsrInputPtr;
	NumStartPtr = UsrInputPtr;

	while (*UsrInputPtr != 999999)
	{
		counter++;
		UsrInputPtr++;
		cin >> *UsrInputPtr;
	}

	cout << "# of Numbers entered: " << counter << endl;
	cout << "Entered number (and address): " << endl;

	for(int i=0; i<counter; i++)
	{
		cout << *(NumStartPtr+i) << " | " << (NumStartPtr+i)
				<< endl;
	}

	float myMin = FindMin(NumStartPtr, counter);
	float myMax = FindMax(NumStartPtr, counter);
	float myAverage = FindAverage(NumStartPtr, counter);

	cout << "Max: " << myMax << endl;
	cout << "Min: " << myMin << endl;
	cout << "Average: " << myAverage << endl;

	cout << "\nDone!";
	return 0;
}



float FindMax(float Array[], int counter)
{	//Function to find the maximum #, in a 5 digit array.
	float MyMax = Array[0];
	for(int j=1; j<counter; j++)
	{
		if(MyMax < Array[j])
			MyMax = Array[j];
	}

	return MyMax;
}



float FindMin(float Array[], int counter)
{	//Function to find the minimum #, in a 5 digit array.
	float MyMin = Array[0];
	for(int j=1; j<counter; j++)
	{
		if(Array[j] < MyMin)
			MyMin = Array[j];
	}

	return MyMin;
}

float FindAverage(float Array[], int counter)
{	//Function to find average of all numbers in dynamic array.
	float MyTotal = 0;
	float MyAverage;
	for(int j=1; j<counter; j++)
		MyTotal += Array[j];

	MyAverage = MyTotal / 2;

	return MyAverage;

}
