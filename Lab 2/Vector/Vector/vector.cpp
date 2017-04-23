// CSCI 41
// Edgar Abundiz
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


//
// lab02_vecotrs.cpp
//
//	name list: 	  "Collins, Bill", "Smith, Bart",   "Allen, Jim",
//                "Griffin, Jim",  "Stamey, Marty", "Rose, Geri",
//                "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
//                "Looney, Joe",   "Wolfe, Bill",   "James, Jean",
//                "Weaver, Jim",   "Pore, Bob",     "Rutherford, Greg",
//                "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
//                "Pike, Gordon",  "Holland, Beth"
//  



//--- function prototypes ---
void init_names(vector<string> &);
void display_names(vector<string>);
void sort_names(vector<string> &);

int main()
{
	vector<string> nameList;
	
	//-------program description
	cout << " This program displays unsorted names and then sorts them." << endl;
	cout << "-----------------------------------------------------------" << endl << endl;
	//------function to initialize the names
	init_names(nameList);

	//-------funciton to display names, unsorted first
	display_names(nameList);

	//------sorts and then displays the names again
	cout << endl << endl<< "Sorted names:" << endl <<"--------------" << endl;
	sort_names(nameList);
	display_names(nameList);

	//--- end of program ---
	cout << endl;
	system("pause");
	return 0;
}

//---DEFINE FUNCTIONS ----------------------------------


void init_names(vector<string> &nameList)             // initialize name to vector
{
	nameList.push_back("Collins, Bill");
	nameList.push_back("Smith, Bart");
	nameList.push_back("Allen, Jim");
	nameList.push_back("Griffin, Jim");
	nameList.push_back("Stamey, Marty");
	nameList.push_back("Rose, Geri");
	nameList.push_back("Taylor, Terri");
	nameList.push_back("Johnson, Jill");
	nameList.push_back("Allison, Jeff");
	nameList.push_back("Looney, Joe");
	nameList.push_back("Wolfe, Bill");
	nameList.push_back("James, Jean");
	nameList.push_back("Weaver, Jim");
	nameList.push_back("Pore, Bob");
	nameList.push_back("Rutherford, Greg");
	nameList.push_back("Javens, Renee");
	nameList.push_back("Harrison, Rose");
	nameList.push_back("Setzer, Cathy");
	nameList.push_back("Pike, Gordon");
	nameList.push_back("Holland, Beth");
}

void sort_names(vector<string> &nameList)                //sort the names through selection sort
{
	int startScan, minIndex;
	string minValue;
	int size = nameList.size();

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = nameList[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (nameList[index] < minValue)
			{
				minValue = nameList[index];
				minIndex = index;
			}
		}
		nameList[minIndex] = nameList[startScan];
		nameList[startScan] = minValue;
	}
}

void display_names(vector<string> name)                  //display the names
{
	for (int i = 0; i < name.size(); i++)
	{
		cout << setw(6) << name[i] << endl;
	}
}