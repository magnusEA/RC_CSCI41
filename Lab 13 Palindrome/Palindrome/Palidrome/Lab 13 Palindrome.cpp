//CSCI 41 Lab 13 Palindrome
//Edgar Abundiz

#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>
#include<queue>
using namespace std;

//Function prototype
bool again();			//asks user if they want to repeat the program


int main()
{
	
	string c;					//varible for word entered
	int length;					//for length of word

	queue<char> myQ;		//create a queue
	stack<char> myS;		//create a stack
	
	//Description
	cout << "******************************************************************************" << endl;
	cout << "This program is used to determine if the word or words entered is a palindrome  " << endl;
	cout << "******************************************************************************" << endl;

	do
	{
		cout << "Enter word/words: ";
		getline(cin, c);
		length = c.length();

		for (int i = 0; i < length; i++)		//loops dependent on length of word entered
		{

			if (isalpha(c[i]))		//ignores anything that isn't a character
			{
				myQ.push(toupper(c[i]));	//pushes characters into the queue and makes all uppercase for easier comparison
				myS.push(toupper(c[i]));	//pushes characters into stack

			}
		}

		bool pal = true;		// boolean value used to determine end result

		while (!myQ.empty() && !myS.empty() && pal)	//runs loops if stack and queue aren't empty and pal remains true
		{
			if (myQ.front() != myS.top())			//checks elements being accessed
			{
				pal = false;						// if the characters being compared aren't the same pal becomes false
			}
			myQ.pop();
			myS.pop();

		}

		// display result
		if (pal == 1)
		{
			cout << "This is a palindrome " << endl;
		}
		else
			cout << "This is not a palindrome " << endl;

		// clear myQ & myS
		while (!myS.empty())
		{
			myS.pop();
		}

		while (!myQ.empty())
		{
			myQ.pop();
		}

		
	} while (again());

	cout << endl;
	system("pause");
	return 0;
}

//Function definitions

// Repeat program again
bool again()
{
	char y;
	cout << "Repeat? (y/n): ";
	cin >> y;
	cin.ignore();
	cout << endl;
	if (y == 'y' || y == 'Y')
		return true;
	else
		return false;

}
// Test Cases
/*
******************************************************************************
This program is used to determine if the word or words entered is a palindrome

******************************************************************************
Enter word/words: racecar
This is a palindrome
Repeat? (y/n): y

Enter word/words: taco cat
This is a palindrome
Repeat? (y/n): y

Enter word/words: was
This is not a palindrome
Repeat? (y/n): n


Press any key to continue . . .

----------------------------------------------------------------------------------------

******************************************************************************
This program is used to determine if the word or words entered is a palindrome

******************************************************************************
Enter word/words: If I had a Hi-Fi.
This is a palindrome
Repeat? (y/n): y

Enter word/words: Never odd or even.
This is a palindrome
Repeat? (y/n): n


Press any key to continue . . .

----------------------------------------------------------------------------------------

******************************************************************************
This program is used to determine if the word or words entered is a palindrome

******************************************************************************
Enter word/words: level!
This is a palindrome
Repeat? (y/n): y

Enter word/words: This isn't very fun.
This is not a palindrome
Repeat? (y/n): n


Press any key to continue . . .
*/