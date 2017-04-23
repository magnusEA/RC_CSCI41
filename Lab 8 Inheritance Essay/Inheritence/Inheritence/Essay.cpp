//Edgar Abundiz
//CSCI 41 lab 08
#include "Essay.h"



// Member function Essay::setTotal
void Essay::setTotal(void)
{
	double total = 0.0;
	total += Grammar;
	total += Spelling;
	total += Length;
	total += Content;
	GradedActivity::setScore(total);
}