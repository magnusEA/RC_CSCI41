//Edgar Abundiz
//CSCI 41 Lab 08

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Essay.h"
#include "GradedActivity.h"

using namespace std;

//function prototype
bool again();


int main()
{
	// Declare variables used
	Essay input;
	double g = 0.0, sp = 0.0, l = 0.0, c = 0.0;

	//---Provide descrption
	cout << " This program will take a students score values \n and display the appropriate letter grade. " << endl << endl;
	do
	{
		//---Ask user for input and have input validation
		cout << " Please enter score for each area " << endl;

		cout << "Enter grammar score (0-30 only): ";
		cin >> g;
		cout << endl << endl;
		if (g < 0.0 || g > 30.0 || isalpha(g))
		{
			cout << "Please enter a valid score: ";
			cin >> g;
		}

		cout << "Enter spelling score (0 - 20 only): ";
		cin >> sp;
		cout << endl << endl;
		if (sp < 0.0 || sp > 20.0 || isalpha(sp))
		{
			cout << "Please enter a valid score: ";
			cin >> sp;
		}

		cout << "Enter length score (0 - 20 only): ";
		cin >> l;
		cout << endl << endl;
		if (l < 0.0 || l > 20.0 || isalpha(l))
		{
			cout << "Please enter a valid score: ";
			cin >> l;
		}

		cout << "Enter content score (0 - 30 only): ";
		cin >> c;
		cout << endl << endl;
		if (c < 0.0 || c > 30.0 || isalpha(c))
		{
			cout << "Please enter a valid score: ";
			cin >> c;
		}

		//Use class functions to set values
		input.setGrammar(g);
		input.setSpelling(sp);
		input.setLength(l);
		input.setContent(c);
		input.setTotal();

		//----Displays final results
		cout << "Student's total essay score is: " << input.getScore() << endl;					// display the sum
		cout << "Student letter grade on essay: " << input.getLetterGrade() << endl << endl;    // display the letter grade
	} while (again());

	system("pause");
	return 0;
}


//-----Function definitons
bool again()
{
	char y;
	cout << "Repeat? (y/n): ";
	cin >> y;
	cout << endl;
	if (y == 'y' || y == 'Y')
		return true;
	else
		return false;

}

//--------------Test Cases--------------
/*
This program will take a students score values
and display the appropriate letter grade.

Please enter score for each area
Enter grammar score (0-30 only): 30


Enter spelling score (0 - 20 only): 20


Enter length score (0 - 20 only): 20


Enter content score (0 - 30 only): 15


Student's total essay score is: 85
Student letter grade on essay: B

Repeat? (y/n): n

Press any key to continue . . .

---------------------------------------------------

This program will take a students score values
and display the appropriate letter grade.

Please enter score for each area
Enter grammar score (0-30 only): 21.3


Enter spelling score (0 - 20 only): 12.3


Enter length score (0 - 20 only): 15.9


Enter content score (0 - 30 only): 16.7


Student's total essay score is: 66.2
Student letter grade on essay: D

Repeat? (y/n): n

Press any key to continue . . .

----------------------------------------------

This program will take a students score values
and display the appropriate letter grade.

Please enter score for each area
Enter grammar score (0-30 only): 33


Please enter a valid score: 21
Enter spelling score (0 - 20 only): 99


Please enter a valid score: 10
Enter length score (0 - 20 only): -88


Please enter a valid score: 15
Enter content score (0 - 30 only): -99


Please enter a valid score: 0
Student's total essay score is: 46
Student letter grade on essay: F

Repeat? (y/n): n

Press any key to continue . . .
*/