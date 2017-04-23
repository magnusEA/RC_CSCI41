//Edgar Abundiz
//CSCI 41 Lab 16

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;


int main()
{
	IntBinaryTree a;
	

	cout << "This program copies values from one tree to the other. " << endl;
	cout << "------------------------------------------------------ " << endl;

	//Inserting values into "a" tree
	a.insertNode(1);
	a.insertNode(2);
	a.insertNode(3);
	a.insertNode(4);
	a.insertNode(5);

	//Displaying "a" tree inorder
	cout << "Inorder traversal 'a' tree:\n";
	a.displayInOrder();

	//Making "b" tree have same as "a" tree
	IntBinaryTree b(a);

	//Displaying "b" tree inorder
	cout << "Inorder traversal 'b' tree:\n";
	b.displayInOrder();






	system("pause");
	return 0;
}