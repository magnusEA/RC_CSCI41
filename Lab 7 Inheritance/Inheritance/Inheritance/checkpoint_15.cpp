//Edgar Abundiz
//CSCI 41 Lab 7 Inheritance checkpoint 15

//Prediction: the output will be 2


#include <iostream>
using namespace std;

class Base
{
	protected:
		int baseVar;

	public:
		Base(int val = 2)
		{
			baseVar = val;
		}

		int getVar()
		{
			return baseVar;
		}
};

class Derived : public Base
{
	private:
		int derivedVar;

	public:
		Derived(int val = 100)
		{
			derivedVar = val;
		}

		int getVar()
		{
			return derivedVar;
		}
};

int main()
{
	Base *optr;
	Derived object;

	optr = &object;
	cout << optr->getVar() << endl;

	system("pause");
	return 0;
}


//Explation: My prediction was correct. getVar was used to get the value of baseVar which was 2. The pointer pointed to the getVar function in the
//			 base class. That caused 2 to be displayed.




//------Result-------
/*
2
Press any key to continue . . .
*/