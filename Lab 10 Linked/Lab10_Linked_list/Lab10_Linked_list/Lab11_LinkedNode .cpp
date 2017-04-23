//Edgar Abundiz
//CSCI 41 Lab 11 Linked List CH17

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct ListNode
{
	int value;
	struct ListNode *next;
};

ListNode *head = NULL;

//---Function prototype
void displayList(ListNode *);						  // used to display
void insertNode( int value);		  // used to insert nodes	
void deleteNode( int newvalue);		  // used to delte nodes

int main()
{
	//--Variables
	ListNode *h = NULL;
	ListNode *tail = NULL;
	ListNode *newNode = NULL;

	if (head == NULL)
	{
		// insert first node
		head = new ListNode;
		head->value = 3;
		head->next = NULL;
		tail = head;
	}
	
	system("pause");
	return 0;
}


//----------------Function Definitions---------------

//**************************
//This function displays
//values of a linked list
//**************************
void displayList(ListNode *head)
{
	ListNode *current;

	current = head;
	while (current)
	{
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << "END";
	cout << endl;
}

/*************************************
* This function is used to add
* nodes in order
**************************************/
void insertNode( int value)
{
	ListNode *newNode = NULL;
	ListNode *nodePtr = NULL;
	ListNode *prevNode = NULL;
	//ListNode *head = NULL;

	//Allocate a new node and store newValue there
	newNode = new ListNode;
	newNode->value = value;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		//----Make nodePtr front of list
		nodePtr = head;

		//-----Initialize prevNode
		prevNode = NULL;

		//-----Skip all nodes whose value is less than newValue
		while (nodePtr != NULL && nodePtr->value < value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//----make new node 1st by putting it before all others
		if (prevNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		//---place node after previous node
		else
		{
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}
	}

}

/********************************
* This function deletes nodes
*********************************/
void deleteNode(int value)
{
	ListNode *nodePtr = NULL;
	ListNode *prevNode = NULL;
	

	//----if empty list do nothing
	if (!head)
		return;

	//---determine if the first node is the one
	if (head->value == value)
	{
		nodePtr = head->next;
		head = nodePtr;
	}

	else
	{
		//---Make nodePtr first
		nodePtr = head;

		//---skip all nodes whose value isnt equal to number entered by user
		while (nodePtr != NULL && nodePtr->value != value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

