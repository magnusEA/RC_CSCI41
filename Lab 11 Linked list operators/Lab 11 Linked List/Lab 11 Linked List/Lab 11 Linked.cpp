//Edgar Abundiz
//CSCI 41 Lab 11 Linked List CH17


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct ListNode
{
	int value;	
	ListNode *next;	
};
ListNode *head = NULL;

//-----Function Prototypes-----

void insertNode(int value);				// function that inserts 
void deleteNode(int value);				// function that deletes 
void displayList(ListNode *head);		// function that displays 
bool again();							// function to repeat

//-----Main-----

int main()
{
	//-----Variables
	int c;	//Determines what action the user will do when prompted
	int n;	// Determines starting amount of nodes
	int n2 = 0;	//used with insert and delete
	int count;	//counter variable
	srand(time(NULL));	//allow random number generator


	// ---Program description
	cout << " ************************************************************* " << endl;
	cout << " * This program adds and deletes nodes from a generated list * " << endl;
	cout << " ************************************************************* " << endl;

	//--Prompt user how many numbers they want to start node list off with
	cout << "Start with how many nodes? (1 - 10): ";
	cin >> n;
	cout << endl;
	while (n < 0 || n > 10)
	{
		cout << "Number must be between 1 and 10: ";
		cin >> n;
		cout << endl;
	}

	//---Enters random numbers 
	for (count = 0; count < n; count++)
	{
		n2 = rand() % 500 + 1;
		insertNode(n2);
	}

	//----Display list
	displayList(head);

	//---begin user manipulation
	cout << " Please choose what to do next ";
	cout << "--------------------------------" << endl << endl;
		
	do
	{
		cout << "1. Insert " << endl;
		cout << "2. Delete " << endl;
		cout << "3. Exit " << endl << endl;
		cout << "What is your choice?: ";
		cin >> c;

		if (c == 1)
		{
			cout << "What number should the node be?: ";
			cin >> n2;
			insertNode(n2);
			cout << endl << endl;
			displayList(head);
		}

		else if (c == 2)
		{
			cout << "Which node do you want to delete?: ";
			cin >> n2;
			deleteNode(n2);
			cout << endl << endl;
			displayList(head);
			
		}

		else if (c == 3)
			cout << " Closing selection" << endl;

		else
			cout << "Please choose from the choice above." << endl << endl;
		
	} while (again());

	
	
	system("pause");
	return 0;
}

//------Function Definitions------

/*****************************
* Used to insert nodes to list
* in order
******************************/
void insertNode(int value)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *prevNode = NULL;

	//Allocate a new node and store value
	newNode = new ListNode;
	newNode->value = value;
	

	//If no node in list make newNode first
	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}

	//if there are then insert newNode
	else
	{
		//Places nodePtr at head
		nodePtr = head;

		//initialize prevNode to NULL
		prevNode = NULL;

		//Skip nodes less than node entered
		while (nodePtr != NULL && nodePtr->value < value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//if new node to be first, skip all others
		if (prevNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}

		//otherwise place after
		else
		{
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/******************************
* Used to delete a node from list
*********************************/
void deleteNode(int value)
{
	ListNode *nodePtr = NULL;	
	ListNode *prevNode = NULL;	

	//do nothing if list is empty
	if (!head)
		return;

	//Determines if the first node is the one
	if (head->value == value)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}

	
	else
	{
		//Initialize nodePtr to head
		nodePtr = head;

		//Skip all other nodes that arent the one desired
		while (nodePtr != NULL && nodePtr->value != value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If nodePtr is not at the end of the list, link the previous node to node after nodePtr,
		//then delete nodePtr
		if (nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**************************
//This function displays
//values of a linked list
//**************************
void displayList(ListNode *head)
{
	ListNode *current;

	current = head;
	while (current != NULL)
	{
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << " END ";
	cout << endl;
}

//----Repeat program if wanted
bool again()
{
	char y;
	cout << "Repeat? (y/n): ";
	cin >> y;
	if (y == 'y' || y == 'Y')
		return true;
	else
		return false;

}

//Test cases
/*
*************************************************************
* This program adds and deletes nodes from a generated list *
*************************************************************
Start with how many nodes? (1 - 10): 4

89 -> 105 -> 295 -> 482 ->  END
Please choose what to do next --------------------------------


1. Insert
2. Delete
3. Exit

What is your choice?: 1
What number should the node be?: 21


21 -> 89 -> 105 -> 295 -> 482 ->  END
Repeat? (y/n): n
Press any key to continue . . .
-----------------------------------------------------

*************************************************************
* This program adds and deletes nodes from a generated list *
*************************************************************
Start with how many nodes? (1 - 10): 5

104 -> 110 -> 304 -> 369 -> 490 ->  END
Please choose what to do next --------------------------------


1. Insert
2. Delete
3. Exit

What is your choice?: 2
Which node do you want to delete?: 490


104 -> 110 -> 304 -> 369 ->  END
Repeat? (y/n): n
Press any key to continue . . .
-----------------------------------------------------

*************************************************************
* This program adds and deletes nodes from a generated list *
*************************************************************
Start with how many nodes? (1 - 10): 10

11 -> 125 -> 133 -> 297 -> 410 -> 421 -> 441 -> 448 -> 455 -> 463 ->  END
Please choose what to do next --------------------------------

1. Insert
2. Delete
3. Exit

What is your choice?: 3
Closing selection
Repeat? (y/n): n
Press any key to continue . . .
-----------------------------------------------------

*************************************************************
* This program adds and deletes nodes from a generated list *
*************************************************************
Start with how many nodes? (1 - 10): 3

164 -> 281 -> 348 ->  END
Please choose what to do next --------------------------------

1. Insert
2. Delete
3. Exit

What is your choice?: 1
What number should the node be?: 170


164 -> 170 -> 281 -> 348 ->  END
Repeat? (y/n): y
1. Insert
2. Delete
3. Exit

What is your choice?: 2
Which node do you want to delete?: 164


170 -> 281 -> 348 ->  END
Repeat? (y/n): y
1. Insert
2. Delete
3. Exit

What is your choice?: 3
Closing selection
Repeat? (y/n): n
Press any key to continue . . .
*/