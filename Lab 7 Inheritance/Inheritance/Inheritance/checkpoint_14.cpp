//Edgar Abundiz
//CSCI 41 Lab 07 Inheritance checkpoint 14

// Prediction: The program will display 2 2.


#include <iostream>
using namespace std;

class First
{
protected:
	int a;

public:
	First(int x = 1)
	{
		a = x;
	}

	virtual void twist()
	{
		a *= 2;
	}

	int getVal()
	{
		twist(); return a;
	}
};

class Second : public First
{
private:
	int b;

public:
	Second(int y = 5)
	{
		b = y;
	}

	virtual void twist()
	{
		b *= 10;
	}
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



//Explation: My prediction was wrong. The program displayed 2 1 and not 2 2. object1.getVal function displays 2 because 2 was the number that 
//	         was the number the getVal function returned. The second number was 1 because of the pure virtual function. Pure virtual functions
//			 have no body in the base class and must be overridden in the derived class. object2.getVal outputs 1 because that was overridden 
//			 into the function.


//------------------Result------------------
/*
2
1
Press any key to continue . . .
*/