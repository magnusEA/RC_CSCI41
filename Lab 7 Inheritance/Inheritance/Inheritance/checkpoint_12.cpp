//Edgar Abundiz
//CSCI 41 Lab 07 Inheritance checkpoint 12

// Prediction: The program will display 1 for the first object and 5 for the second object.


#include <iostream>
using namespace std;

class First
{
protected:
	int a;

public:
	First(int x = 1)
	{a = x;}

	int getVal()
	{return a;}
};

class Second : public First
{
private:
	int b;

public:
	Second(int y = 5)
	{b = y;}

	int getVal()
	{return b;}
};


int main()
{
	First object1;
	Second object2;

	cout << object1.getVal() << endl;
	cout << object2.getVal() << endl;

	system("pause");
	return 0;
}

// Explation: My prediction is the same as the program output. object1.getVal gets the value of a which was equal to x which then was 
//			  equal to 1. object2.getVal() does the same but gets the value of b which was equal to y which then was equal to 5.



//------------------Result------------------
/*
1
5
Press any key to continue . . .
*/