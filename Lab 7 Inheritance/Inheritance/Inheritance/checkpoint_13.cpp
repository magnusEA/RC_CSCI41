//Edgar Abundiz
//CSCI 41 Lab 07 Inheritance checkpoint 13

// Prediction: The program will display 2 and 50.


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

	void twist()
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

	void twist()
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



//Explation: My prediction was incorrect. The out of the program was 2 2. object1.getVal was 2 because a was equal to 2 after it was multiplied
//	         because of the twist() function. object2.getVal also displayed 2 because the second class had no getVal function of it's own. And since
//			 the Second class was a derived class from First it displayed the number 2 because of that getVal function.


//------------------Result------------------
/*
2
2
Press any key to continue . . .
*/