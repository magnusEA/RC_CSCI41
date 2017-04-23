//Edgar Abundiz
//CSCI 41 Lab 07 Inheritance checkpoint 14B

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

	   void twist()                //removed virtual
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

	   void twist()         //removed virtual
		{
			b *= 10;
		}

	   int getVal()           // added this function to get the value of 50 
	   {
		   twist(); return b;
	   }
};


int main()
{
	First object1;
	Second object2;

	cout << object1.getVal() << endl;        //displays 2
	cout << object2.getVal() << endl;	     //displays 50

	system("pause");
	return 0;
}

//------------Result-------
/*
2
50
Press any key to continue . . .
*/