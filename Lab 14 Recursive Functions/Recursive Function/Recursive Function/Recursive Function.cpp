//CSCI 41 Lab 14 Recursive Function
//Edgar Abundiz

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
using namespace std;

//Function Prototype
int multiply(int , int);
bool Palindrome(string &, int, int);

int main()
{
	int a;									//for first number entered
	int b;									//for second number entered
	int result;								//for result
	string c;								//used in palindrome
	string d;								//used in palindrome
	bool good;								//used when determining if word is palindrome or not

	cout << "****************************************************************************" << endl;
	cout << "This program will test recursive function with multiplication and palindrome" << endl;
	cout << "****************************************************************************" << endl << endl;

	cout << "Enter two positive integers." << endl;
	cout << "Enter first number: ";
	cin >> a;
	if (a < 0)					//input validation
	{
		cout << "Must be a positive integer enter again: ";
		cin >> a;
	}

	cout << "Enter second number: ";
	cin >> b;
	cin.ignore();
	if (b < 0)					//input validation
	{
		cout << "Must be a positive integer enter again: ";
		cin >> b;
		cin.ignore();
	}
	cout << endl;

	cout << "Result " << endl;
	cout << "------ " << endl;
	
	result = multiply(a, b);					//calls recursive function to multiply variables
	cout << result << endl << endl;				//display result
	
	//Begin plaindrome check
	cout << "Enter a word to see if it is a plaindrome: ";
	getline(cin, c);

	//loop to take in word and convert to uppercase
	for (int i = 0; i < c.length(); ++i)
	{
		if (isalpha(c[i]))				//used to ignore anything that isnt a letter
		{
			d += toupper(c[i]);			//convert letter to uppercase and put them in new variable
		}

	}

	good = Palindrome(d, 0, d.length() -1);  //enters the uppercase word, the start point, and the length - 1 for the end
	

	if (good == true)						//displays if word is palin drome or not depending on function above
		cout << "This is a palindrome! " << endl;
	else
		cout << "This isn't a palindrome. " << endl;

	cout << endl;
	system("pause");
	return 0;
}


//Function Definitions
//Multiplies numbers in recursive function
int multiply(int x, int y)
{
	if (y <= 1)
		return x;
	else
		return x + multiply(x, y-1);
}

//Palindrome recursive funtion
bool Palindrome(string &s, int begin, int end)
{
	if (begin >= end)
		return true;

	if (s.front() != s.back())	
		return false;

	if (s[begin] != s[end])	
		return false;

	return Palindrome(s, ++begin, --end);	//runs function again
}


//Test Cases
/*
****************************************************************************
This program will test recursive function with multiplication and palindrome
****************************************************************************

Enter two positive integers.
Enter first number: 7
Enter second number: 6

Result
------
42

Enter a word to see if it is a plaindrome: Taco cat
This is a palindrome!

Press any key to continue . . .

****************************************************************************
This program will test recursive function with multiplication and palindrome
****************************************************************************

Enter two positive integers.
Enter first number: 5
Enter second number: 5

Result
------
25

Enter a word to see if it is a plaindrome: Able was I ere I saw Elba.
This is a palindrome!

Press any key to continue . . .

****************************************************************************
This program will test recursive function with multiplication and palindrome
****************************************************************************

Enter two positive integers.
Enter first number: -5
Must be a positive integer enter again: 5
Enter second number: -3
Must be a positive integer enter again: 1

Result
------
5

Enter a word to see if it is a plaindrome: oops this is not one
This isn't a palindrome.

Press any key to continue . . .

*/