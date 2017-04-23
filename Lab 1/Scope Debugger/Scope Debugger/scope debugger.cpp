// ch3_10_pr3_26_trace.cpp
// This program asks for three numbers, then
// displays the average of the numbers.
// Edgar Abundiz
// CSCI 41
#include <iostream>
using namespace std;

double find_avg(double, double, double);


int main()
{													//line 1
	double num1, num2, num3, avg;

	cout << "Enter the first number: ";             // line 2
	cin >> num1;									// line 3
	cout << "Enter the second number: ";			// line 4
	cin >> num2;									// line 5
	cout << "Enter the third number: ";				// line 6
	cin >> num3;									// line 7
	avg = find_avg(num1, num2, num3);					// line 8
	cout << "The average is " << avg << endl;		// line 9

	system("pause");
	return 0;
}

double find_avg(double n1, double n2, double n3)
{                                                 // line 10
	double avg = (n1 + n2 + n3) / 3;			//line 11
	return avg;									//line 12
}												// line 13