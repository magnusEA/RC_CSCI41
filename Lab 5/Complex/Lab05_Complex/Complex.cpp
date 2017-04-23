//Edgar Abundiz
//CSCI 41 Lab 5 COmplex numbers

#include<iostream>
#include<cstdlib>
#include "Complex.h"

using namespace std;


//----Overloaded > operator
bool Complex::operator > (const Complex &right)
{
	bool status;

	if (Real > right.Real)
		status = true;
	else if (Real == right.Real && Imaginary > right.Imaginary)
		status = true;

	else
		status = false;
	
	return status;
}


//-----Overloaded < operator
bool Complex::operator < (const Complex &right)
{
	bool status;

	if (Real < right.Real)
		status = true;
	else if (Real == right.Real && Imaginary < right.Imaginary)
		status = true;
	else
		status = false;

	return status;
}

//---Overloaded << operator

ostream &operator<<(ostream &strm, const Complex &obj)
{
	strm << "("<< obj.Real << " + " << obj.Imaginary << "i)";
	return strm;
}


//-----Overloaded >> operator
istream &operator >> (istream &strm, Complex &obj)
{
	//Prompt the user for Real number
	cout << "Real: ";
	strm >> obj.Real;

	//Prompt the user for Imaginary number
	cout << "Imaginary: ";
	strm >> obj.Imaginary;

	return strm;
} 

//--------Overloaded binary + operator
Complex Complex::operator + (const Complex &right)
{
	Complex sum;

	sum.Real = Real + right.Real;
	sum.Imaginary = Imaginary + right.Imaginary;

	return sum;
}

//--------Overloaded binary - operator
Complex Complex::operator - (const Complex &right)
{
	Complex sub;

	sub.Real = Real - right.Real;
	sub.Imaginary = Imaginary - right.Imaginary;
	return sub;
}

//-----Overloaded * operator
Complex Complex::operator * (const Complex &right)
{
	Complex mult;

	mult.Real = Real * right.Real;
	mult.Imaginary = Imaginary * right.Imaginary;
	return mult;
}

//-----Overloaded / operator 
Complex Complex::operator / (const Complex &right)
{
	Complex div;

	div.Real = Real / right.Real;
	div.Imaginary = Imaginary / right.Imaginary;
	return div;
}


//------Overloaded == operator
bool Complex::operator == (const Complex &right)
{
	bool status;

	if (Real == right.Real && Imaginary == right.Imaginary)
		status = true;
	else
		status = false;

	return status;
}

//-----Overloaded != operator
bool Complex::operator != (const Complex &right)
{
	bool status;

	if (Real != right.Real || Imaginary != right.Imaginary)
		status = true;
	else
		status = false;

	return status;
}
//---Overload * for double
Complex operator * (double factor, const Complex &right)
{
	Complex c;
	c.Real = factor * right.Real;
	c.Imaginary = factor * right.Imaginary;
	return c;
}

//---Absolute function
double Complex::Absolute(Complex &num)
{
	double x;
	x = sqrt(pow(num.Real, 2) + pow(num.Imaginary, 2));
	return x;
}