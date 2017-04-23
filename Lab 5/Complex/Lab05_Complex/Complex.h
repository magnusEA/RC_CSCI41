// Edgar Abundiz
// CSCI 41 Lab 5 Complex numbers

#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;


class Complex
{
private:
	double Real;
	double Imaginary; 

public:

	Complex(double r=0, double i=0)
	{
		Real = r, Imaginary = i;
	}
	void set_Real(double r);
	void set_Imaginary(double i);
	double get_Real();
	double get_Imaginary();
	double Absolute(Complex &);

	//---Overloaded operator functions
	Complex operator + (const Complex &); // Overloaded +
	Complex operator - (const Complex&); // Overloaded -
	Complex operator * (const Complex &); // Overloaded *
	Complex operator / (const Complex &); // Overloaded /
	bool operator > (const Complex &);  // Overloaded >
	bool operator < (const Complex &);  // Overloaded <
	bool operator == (const Complex &); // Overloaded ==
	bool operator != (const Complex &); // Overload !=
	

	//-- Friends
	friend ostream &operator << (ostream &, const Complex &);
	friend istream &operator >> (istream &, Complex &);
	friend Complex operator * (double, const Complex &); // Overloaded * to work with double

};

//-------Function Protoype
ostream &operator << (ostream &, const Complex &);
istream &operator >> (istream &, Complex &);
Complex operator * (double, const Complex &); // Overloaded *


#endif