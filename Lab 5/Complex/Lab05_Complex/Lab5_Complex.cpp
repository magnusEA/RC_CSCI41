//Edgar Abundiz
//CSCI 41 Lab 5 Complex numbers

/*
* Lab_complex_number_driver.cpp
* A driver program to test complex class member functions:
*      constructor
*      Arithmetic operators: +, -, *, /
*      i/o operators: >> and <<
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Complex.h"

enum choice { EXIT, ADD, SUBTRACT, MULTIPLY, MULT_FACTOR, DIVIDE,ABSOLUTE, NOTEQUAL };

//=======================================
//  FUNCTION PROTOTYPES
//=======================================
void instruction(void);
int  menu(void);
void do_option(enum choice option);

//=======================================
//  MAIN FUNCTION
//=======================================
int main()
{
	
	enum choice option;    // user's option of arithmetic operations

	instruction();
	option = (enum choice) menu();
	do
	{
		do_option(option);
		option = (enum choice) menu();
	} while (option != EXIT);
	
	


	system("pause");
	return 0;
}

//=======================================
//  DEFINE FUNCTIONS
//=======================================
void instruction(void)
// Precondition: none
// Postcondition: none
{
	cout << "+----------------------------------------------+" << endl;
	cout << "|  This program tests complex class operations |" << endl;
	cout << "+----------------------------------------------+" << endl;
}

int  menu(void)
// Precondition: none
// Postcondition: returns user's menu selection
{
	int option;

	do {
		cout << EXIT << ". exit" << endl;
		cout << ADD << ". addition" << endl;
		cout << SUBTRACT << ". subtraction" << endl;
		cout << MULTIPLY << ". multiplication" << endl;
		cout << MULT_FACTOR << ". multiply by a factor" << endl;
		cout << DIVIDE << ". division" << endl;
		cout << ABSOLUTE << ". absolute " << endl;
		cout << NOTEQUAL << ". compare" << endl;
		cout << " Selection: ";
		cin >> option;
	} while (option < EXIT || option > NOTEQUAL);

	return option;
}

void do_option(enum choice option)
{
	Complex c1, c2, c3;
	Complex zero(0, 0);    // a zero complex number
	double  factor;
	char division = 246;
	bool stat;

	switch (option)
	{
	case EXIT:
		break;
	case ADD:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter another complex number: ";
		cin >> c2;
		c3 = c1 + c2;
		cout << c1 << " + " << c2 << " = " << c3;
		cout << endl << endl;
		break;
	case SUBTRACT:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter another complex number: ";
		cin >> c2;
		c3 = c1 - c2;
		cout << c1 << " - " << c2 << " = " << c3;
		cout << endl << endl;
		break;
	case MULTIPLY:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter another complex number: ";
		cin >> c2;
		c3 = c1 * c2;
		cout << c1 << " * " << c2 << " = " << c3;
		cout << endl << endl;
		break;
		
	case MULT_FACTOR:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter a number: ";
		cin >> factor;
		c3 = factor * c1;
		cout << factor << " * " << c1 << " = " << c3 << endl;
		c3 = c1 * factor;
		cout << c1 << " * " << factor << " = " << c3;
		cout << endl << endl;
		break;
		
	case DIVIDE:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter another complex number: ";
		cin >> c2;
		while (c2 == zero)
		{
			cout << "Can not divide by a zero, ";
			cout << "enter a complex number again: ";
			cin >> c2;
		}
		c3 = c1 / c2;
		cout << c1 << " " << division << " " << c2 << " = " << c3;
		cout << endl << endl;
		break;

	case ABSOLUTE:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << c1 << " Absolute value of the complex number = " << c2.Absolute(c1);
		cout << endl << endl;
		break;

	case NOTEQUAL:
		cout << "Enter a complex number: ";
		cin >> c1;
		cout << "Enter another complex number: ";
		cin >> c2;
		if (c1 != c2)
			stat = true;
		else stat = false;
		cout << c1 << " and " << c2 << " are ";
		if (stat == true)
			cout << "not equal to each other.";
		else cout << "equal to each other.";
		cout << endl << endl;
		break;

	default:
		cout << "Illegal option, select between " << ADD
			<< " and " << DIVIDE;
		cout << endl << endl;
	}
}
//----Test Cases
/*
+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 7
Enter a complex number: Real: 1
Imaginary: 2
Enter another complex number: Real: 5
Imaginary: 4
(1 + 2i) and (5 + 4i) are not equal to each other.

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absoulte
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absoulte
7. compare
Selection: 1
Enter a complex number: Real: 2.3
Imaginary: 5
Enter another complex number: Real: 2.1
Imaginary: 6
(2.3 + 5i) + (2.1 + 6i) = (4.4 + 11i)

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 2
Enter a complex number: Real: 5
Imaginary: 4
Enter another complex number: Real: 6.3
Imaginary: 0
(5 + 4i) - (6.3 + 0i) = (-1.3 + 4i)

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 3
Enter a complex number: Real: 2
Imaginary: 2
Enter another complex number: Real: 4.2
Imaginary: 3.5
(2 + 2i) * (4.2 + 3.5i) = (8.4 + 7i)

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 4
Enter a complex number: Real: 2
Imaginary: 1
Enter a number: 9
9 * (2 + 1i) = (18 + 9i)
(2 + 1i) * 9 = (18 + 0i)

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 5
Enter a complex number: Real: 1
Imaginary: 5
Enter another complex number: Real: 0
Imaginary: 0
Can not divide by a zero, enter a complex number again: Real:

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 5
Enter a complex number: Real: 2.3
Imaginary: 4.1
Enter another complex number: Real: -2
Imaginary: 5.1
(2.3 + 4.1i) ÷ (-2 + 5.1i) = (-1.15 + 0.803922i)

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .

+----------------------------------------------+
|  This program tests complex class operations |
+----------------------------------------------+
0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 6
Enter a complex number: Real: -5
Imaginary: 1.2
(-5 + 1.2i) Absolute value of the complex number = 5.14198

0. exit
1. addition
2. subtraction
3. multiplication
4. multiply by a factor
5. division
6. absolute
7. compare
Selection: 0
Press any key to continue . . .
*/
