//Edgar Abundiz
//CSCI 41 lab 08

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"


//--Derived class 
class Essay : public GradedActivity
{
	private:
		double Grammar;
		double Spelling;
		double Length;
		double Content;

	public:
		// Default Constructor
		Essay() : GradedActivity()
		{ Grammar = 0.0, Spelling = 0.0, Length = 0.0, Content = 0.0; }

		// Constructor
		Essay(double g, double sp, double l, double c)
		{
			Grammar = g, Spelling = sp, Length = l, Content = c; 
		}

		//Get values for each variable
		double getGrammar() const
		{ return Grammar; }

		double getSpelling() const
		{ return Spelling; }

		double getLength() const
		{ return Length; }
		
		double getContent() const
		{ return Content; }

		// Set values for each variable
		void setGrammar(double g)
		{ Grammar = g; }

		void setSpelling(double sp)
		{ Spelling = sp; }

		void setLength(double l)
		{ Length = l; }

		void setContent(double c)
		{ Content = c; }

		void setTotal();           // set the total

};
#endif