//Edgar Abundiz
// CSCI 41 lab 09

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

#include "Bag.h"


//Function Prototype
void IntBag(Bag<int> &b);
void DoubleBag(Bag<double> &b);
void StringBag(Bag<string> &b);
bool Decision(void);

template <class T>
void DisplayItems(Bag<T> &);

template <class T>
void Remove(Bag<T> &);

int main()
{
	srand(time(NULL));

	Bag<int> b1;             // Template class for int
	Bag<double> b2;			 // Template class for double
	Bag<string> b3;			 // Template class for string

	//Description of program
	cout << "This program will demonstrate the usage of a template class. " << endl;
	cout << "************************************************************" << endl;

	//-----------------------Frist bag (int)---------------------------------------
	IntBag(b1);
	cout << " In this bag, there are " << b1.size() << " items" << endl;
	DisplayItems(b1);
	Remove(b1);
	cout << endl;

	//-----------------------Second bag (double)-----------------------------------
	DoubleBag(b2);
	cout << " In this bag, there are " << b2.size() << " items" << endl;
	DisplayItems(b2);
	Remove(b2);
	cout << endl;

	//-----------------------Third bag (string)-----------------------------------
	StringBag(b3);
	cout << " In this bag, there are " << b3.size() << " items" << endl;
	DisplayItems(b3);
	Remove(b3);
	cout << endl;

	system("pause");
	return 0;
}

//Function definitions
//Make a function  for int usage
void IntBag(Bag<int> &b)
{
	int num;
	int num2=0;
	cout << "How many bags? ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		/*
		cout << "Enter amount of items in bag: ";
		cin >> num2;
		b.insert(num2);
		*/
		num2 = rand() % 100;
		b.insert(num2);
	}
}

//Make a function  for double usage
void DoubleBag(Bag<double> &b)
{
	int num;
	double num2 = 0;
	cout << "How many bags? ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		/*
		cout << "Enter amount of items in bag: ";
		cin >> num2;
		b.insert(num2);
		*/
		num2 = rand() % (200) / 1.154379;
		b.insert(num2);
	}
}

//Function for string usage
void StringBag(Bag<string> &b)
{
	int num;
	string word;
	cout << "How many words to enter?: ";
	cin >> num;
	cout << endl;

	cout << "Enter words " << endl;
	cin.ignore();
	for (int i = 0; i < num; i++)
	{
		cin.ignore(0);
		cout << "Word: ";
		getline(cin, word);
		b.insert(word);
	}
}

//Template function to display what is in the bag
template <class T>
void DisplayItems(Bag<T> &b)
{
	for (int i = 0; i < b.size(); i++)
		cout << i + 1 << setprecision(2) << fixed << " - " << b[i] << endl;
}

// Function to determine what choice is made
bool Decision(void)
{
	int c;
	cin >> c;

	if (c == 1)
		return true;

	else
		return false;
}

//Template function to allow the removal of an item
template <class T>
void Remove(Bag<T> &b)
{
	int c;
	bool stat;

	cout << "Do you want to remove an item?(1 = yes, 0 = no): ";
	stat = Decision();
	cout << endl;

	while (stat == true)
	{
		cout << "Choose item to remove from 1 - " << b.size() << ": ";
		cin >> c;
		c -= 1;

		b.erase(c);
		cout << endl;

		DisplayItems(b);
		cout << "Remove something again?(1 = yes, 0 = no): ";
		stat = Decision();
	}

}

//--------Test Cases-----------------
/*
This program will demonstrate the usage of a template class.
************************************************************
How many bags? 5
In this bag, there are 5 items
1 - 45
2 - 8
3 - 41
4 - 45
5 - 70
Do you want to remove an item?(1 = yes, 0 = no): 0


How many bags? 5
In this bag, there are 5 items
1 - 155.06
2 - 51.11
3 - 84.03
4 - 37.25
5 - 164.59
Do you want to remove an item?(1 = yes, 0 = no): 0


How many words to enter?: 2

Enter words
Word: Computer
Word: Science
In this bag, there are 2 items
1 - Computer
2 - Science
Do you want to remove an item?(1 = yes, 0 = no): 0


Press any key to continue . . .
--------------------------------------------------------------------

This program will demonstrate the usage of a template class.
************************************************************
How many bags? 3
In this bag, there are 3 items
1 - 2
2 - 43
3 - 85
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 3: 2

1 - 2
2 - 85
Remove something again?(1 = yes, 0 = no): 0

How many bags? 3
In this bag, there are 3 items
1 - 90.09
2 - 129.07
3 - 46.78
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 3: 2

1 - 90.09
2 - 46.78
Remove something again?(1 = yes, 0 = no): 0

How many words to enter?: 3

Enter words
Word: Super
Word: boring
Word: Awesome
In this bag, there are 3 items
1 - Super
2 - boring
3 - Awesome
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 3: 2

1 - Super
2 - Awesome
Remove something again?(1 = yes, 0 = no): 0

Press any key to continue . . .
--------------------------------------------------------------------

This program will demonstrate the usage of a template class.
************************************************************
How many bags? 5
In this bag, there are 5 items
1 - 14
2 - 62
3 - 76
4 - 56
5 - 36
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 5: 1

1 - 62
2 - 76
3 - 56
4 - 36
Remove something again?(1 = yes, 0 = no): 1
Choose item to remove from 1 - 4: 2

1 - 62
2 - 56
3 - 36
Remove something again?(1 = yes, 0 = no): 0

How many bags? 6
In this bag, there are 6 items
1 - 127.34
2 - 102.22
3 - 168.92
4 - 66.70
5 - 161.13
6 - 170.65
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 6: 4

1 - 127.34
2 - 102.22
3 - 168.92
4 - 161.13
5 - 170.65
Remove something again?(1 = yes, 0 = no): 1
Choose item to remove from 1 - 5: 4

1 - 127.34
2 - 102.22
3 - 168.92
4 - 170.65
Remove something again?(1 = yes, 0 = no): 0

How many words to enter?: 4

Enter words
Word: Fun
Word: Times
Word: Dumb
Word: Meh
In this bag, there are 4 items
1 - Fun
2 - Times
3 - Dumb
4 - Meh
Do you want to remove an item?(1 = yes, 0 = no): 1

Choose item to remove from 1 - 4: 3

1 - Fun
2 - Times
3 - Meh
Remove something again?(1 = yes, 0 = no): 1
Choose item to remove from 1 - 3: 1

1 - Times
2 - Meh
Remove something again?(1 = yes, 0 = no): 0

Press any key to continue . . .

*/