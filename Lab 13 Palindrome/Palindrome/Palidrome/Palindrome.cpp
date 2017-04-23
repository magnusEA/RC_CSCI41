// This program display a binary tree with indentation
//
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
	IntBinaryTree tree;
	int num;
	char again;

	do
	{

		// Insert some values into the tree.
		cout << "Inserting nodes.\n";
		do
		{
			cout << "Enter a number: ";
			cin >> num;
			if (num != -1)
			{
				tree.insertNode(num);
				tree.printTree();
				cout << endl;
			}
		} while (num != -1);

		// Display the values.
		cout << "Here are the values in the tree:\n\n";
		tree.printTree();
		cout << endl;

		cout << endl;
		cout << "There are " << tree.treeSize() << " nodes." << endl;
		cout << endl;
		cout << "Tree level is " << tree.treeLevel() << endl;

		tree.~IntBinaryTree();
		cout << "=================" << endl;

		cout << "\t Again (y/n)? ";
		cin >> again;

	} while (toupper(again) != 'N');

	system("pause");
	return 0;
}