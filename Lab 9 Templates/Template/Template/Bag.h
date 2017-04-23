//Edgar Abundiz
//CSCI 41 Lab 09 Template Class - Bag

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Bag
{
	public: 
		static const int SIZE = 20;

	private:
		T data[SIZE];  //Represents various data types, in this program it is used for string, int, and double
		int used;	   // Keeps track 

	public:
		Bag()          // constructor 
		{used = 0;};
		
		~Bag() {};     //destructor

		void insert(T &); // Inserts value for any data type
			
		bool erase_one(int &); //erase the index
			
		int erase(int &); //used as a check to allow erase_one to work
			
		int size(void) const { return used; } // used with array space

		int count(T &); // Keep track of the items in bag
			
		T operator[](int idx); // allow use of [] in main

		int find(int &); // locate appropriate index
};
//----Define member functions
/*******************************************
*used to instert values
********************************************/
template <class T>
void Bag<T>::insert(T &item)
{
	data[used] = item;
	used++;
}
/*******************************************
* Erase an item from the bag
********************************************/
template <class T>
bool Bag<T>::erase_one(int &item)
{
	int idx;
	idx = find(item);
	if (idx == -1)
		return false;

	// found item at idx, delete it
	for (int i = idx; i < used - 1; i++)
	{
		if (idx == used - 1)
			break;
		data[i] = data[i + 1];
	}
	used--;
	return true;
}
/*******************************************
*Used as a check to allow erase_one to work
********************************************/
template <class T>
int Bag<T>::erase(int &item)
{
	int count = 0;
	bool good;

	good = erase_one(item);
	return count;
}

/*******************************************
Keep track of the items in bag
********************************************/
template <class T>
int Bag<T>::count(T &item)
{
	int c = 0;

	for (int i = 0; i < used - 1; i++)
	{
		if (data[i] == item)
			c++;
	}
	return c;
}

/*******************************************
*Overload bracket operator
********************************************/
template <class T>
T   Bag<T>::operator[](int idx)
{
	if (idx >= 0 && idx < used )
		return data[idx];
	
}

/*******************************************
*seach for item in bag
********************************************/
template <class T>
int Bag<T>::find(int &item)
{
	int i;
	int idx = -1;  // -1 is not found

	for (i = 0; i < used - 1; i++)
	{
		if (i == item)
		{
			idx = i;
			break;
		}
	}

	return idx;
}

#endif;