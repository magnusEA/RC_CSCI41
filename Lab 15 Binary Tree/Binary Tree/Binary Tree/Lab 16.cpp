//Edgar Abundiz
//CSCI 41 Lab 15

#include <iostream>
#include <cstdlib>
#include "IntBinaryTree.h"
using namespace std;

//Function Prototypes
bool MenuSelect(int);

int main()
{
	int ch;    //variable for choice made
	bool selection; //useed in switch statement function 

	cout << " Binary Search Tree " << endl;
	cout << "******************** " << endl << endl;
	MenuSelect(0);

	do
	{
		cout << "Choice: ";
		cin >> ch;
		cout << endl;
		selection = MenuSelect(ch);

	} while (selection);


	cout << endl;
	system("pause");
	return 0;
}

//Funciton Definitions
//Used to allow user to make a choice and then follow through with that choice
bool MenuSelect(int ch)
{
	int n;
	bool search;
	static IntBinaryTree x;
	
	//begin switch statement for menu
	switch(ch)
	{
		case 0:
		{
			  cout << "0. Menu" << endl;
			  cout << "1. Insert a value" << endl;
			  cout << "2. Delete a value" << endl;
			  cout << "3. Search for a value" << endl;
			  cout << "4. Display the tree in-order" << endl;
			  cout << "5. Display the tree pre-order" << endl;
			  cout << "6. Display the tree post-order" << endl;
			  cout << "9. Exit" << endl << endl;
				 
			  return true;
		}

		case 1: 	//Insert a value
		{
		      cout << "Enter an integer to add: ";
		   	  cin >> n;
			  x.insertNode(n);
			  cout << endl;
			  return true;
		}

		case 2: 	//remove a value
		{
			  cout << "Enter an integer to remove: ";
			  cin >> n;
			  x.remove(n);
			  cout << endl;
			  return true;
		}

		case 3: 	//search for a value
		{
			  cout << "Enter an integer to search for: ";
			  cin >> n;
			  search = x.searchNode(n);		//retruns true if value is found otherwise false
			  //Determines what is done depending on previous function
			  if (search == true)
				  cout << n << " was found in the tree. ";
			  else
				  cout << n << " was nowhere to be found. ";
			  cout << endl;
			  return true;
		}

		case 4: //display tree in order
		{
			   cout << "The tree is (in-order):" << endl;
			   x.displayInOrder();
			   return true;
		}

		case 5://displays in order of numbers entered
		{
			   cout << "The tree is (pre-order):" << endl;
			   x.displayPreOrder();
			   return true;
		}

		case 6://display in post order
		{
			   cout << "The tree is (post-order):" << endl;
			   x.displayPostOrder();
			   return true;
		}

		case 9: //quit program
		
				return false;
		default:
		{
				   cout << "Invalid choice " << endl;
				   return true;
		
		}

	}

}

// Test Cases
