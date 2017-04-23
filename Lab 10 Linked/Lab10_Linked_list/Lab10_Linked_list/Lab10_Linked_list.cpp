//Edgar Abundiz
//CSCI 41 Lab 10 Linked List CH17

#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	double value;
	node *next;

};

//---Function prototype
void displayList(node *);


int main()
{
	node *head = NULL;
	node *tail = NULL;
	node *newNode = NULL;
	//node *newNode2 = NULL;

	
	//---create a linked list---
	//	 3 -> 10 -> 13 -> 4.5
	if (head == NULL)
	{
		// insert first node
		head = new node;
		head->value = 3;
		head->next = NULL;
		tail = head;
	}

	//---Insert 10 to end of list-----
	newNode = new node;
	newNode->value = 10;
	newNode->next = NULL;

	tail->next = newNode;
	tail = newNode;
	

	//---Insert 13 to end of list---
	newNode = new node;
	newNode->value = 13;
	newNode->next = NULL;

	tail->next = newNode;
	tail = newNode;


	//--Insert 4.5 to end of list---
	newNode = new node;
	newNode->value = 4.5;
	newNode->next = NULL;

	tail->next = newNode;
	tail = newNode;

	//----Display the linked list
	displayList(head);

	system("pause");
	return 0;
}


//----------------Function Definitions---------------

//**************************
//This function displays
//values of a linked list
//**************************
void displayList(node *head)
{
	node *current;

	current = head;
	while (current != NULL)
	{
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << " END ";
	cout << endl;
}


//-----Test Case----
/*
3 -> 10 -> 13 -> 4.5 ->  END
Press any key to continue . . .
*/