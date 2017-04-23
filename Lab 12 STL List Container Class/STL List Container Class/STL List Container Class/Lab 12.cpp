//Edgar Abundiz
// lab 12- STL list
//CSCI 41
#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iomanip>
using namespace std;


void create_list(list<int> &);			// fucntion to created randomly generated list
void display(list<int> &);				// function to show created list
void display_1st_element(list<int> &);  // function to display first element
void display_last_element(list<int> &); // function to display last element
void display_nth_element(list<int> &);  // function to display element chosen by user
void remove_3_element(list<int> &);     // function to remove first 3 elements in list
void sort_list(list<int> &);			// function to sort list
bool again();							// function to repeat

int main()
{
	
	list <int> number;
	list<int>::iterator iter;
	

	srand(time(NULL));

	//----Creat list of number in container
	create_list(number);

	//----displays the list created by user
	cout << "There are " << number.size() << " elements in the list. " << endl << endl;
	display(number);
	cout << endl << endl;
	
	//----displays the first element
	cout << "1st element in list is : ";
	display_1st_element(number);
	cout << endl << endl;

	//displays the last element
	cout << "Last element in list is: ";
	display_last_element(number);
	cout << endl << endl;

	//---display element chose by user
	display_nth_element(number);

	
	//---removing elements
	cout << endl << endl;
	cout << "--- removed 1st 3 elements ---\n";
	remove_3_element(number);
	cout << "There are " << number.size() << " elements in the list. " << endl << endl;
	display(number);

	//---sort the list
	cout << endl << endl << "-- Sorted List ---\n\n";
	sort_list(number);
	display(number);


	//--- end of program -------
	cout << endl;
	system("pause");
	return 0;
}

///////////// DEFINE FUNCTIONS ///////////////////
/***********************************************
* repition loop used in display_nth_element
************************************************/
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

/***********************************************
* Creates a list of randomly generated number
* based on how many the user enters
************************************************/
void create_list(list<int> &number)
{
	int c;
	int i;

	cout << "How many numbers do you want?: ";
	cin >> c;
	if (c <= 0)
	{
		cout << "Enter a number greater than zero: ";
		cin >> c;
	}
	cout  << endl << endl;
	for (int x = 0; x < c; x++)
	{
		i = rand() % 500 + 1;
		number.push_back(i);
	}
}

/***********************************************
* displays the first element
************************************************/
void display_1st_element(list<int> &number)
{
	cout << number.front();
}

/***********************************************
* displays the last element
************************************************/
void display_last_element(list<int> &number)
{
	cout << number.back();
}

/***********************************************
* displays all elements
************************************************/
void display(list<int> &lst)
{
	
	list<int>::iterator it;
	int x = 0;
	
	for (it = lst.begin(); it != lst.end(); ++it)
	{
			cout << setw(7) << *it << " ";
			x++;
			if (x %5 ==0)
			{
				cout << endl;
			}
	}
}

/***********************************************
* displays the element chosen by user
************************************************/
void display_nth_element(list<int> &number)
{
	int c;
	do
	{
		cout << "Which element to display? (choose the index): ";
		cin >> c;
		if (c < 0)
		{
			cout << "Index can't be less than zero: ";
			cin >> c;
		}
		list<int>::iterator iter = number.begin();
		cout << "The number at [" << c << "] is: ";
		advance(iter, c);
		cout << *iter << endl;
		
	} while (again());
}

/***********************************************
* Removes the first 3 elements
************************************************/
void remove_3_element(list<int> &number)
{
	number.pop_front();
	number.pop_front();
	number.pop_front();
}

/***********************************************
* sorts the list
************************************************/
void sort_list(list<int> &number)
{
	number.sort();
}

//---------TEST CASES---------
/*
How many numbers do you want?: 32


There are 32 elements in the list.

105     335      22     152     224
127     457      45     325     411
391     437     372     128     479
480     281     110      69      41
335     390      36     448     318
463     343     273     181     245
291     133

1st element in list is : 105

Last element in list is: 133

Which element to display? (choose the index): 1
The number at [1] is: 335
Repeat? (y/n): y
Which element to display? (choose the index): 12
The number at [12] is: 372
Repeat? (y/n): n


--- removed 1st 3 elements ---
There are 29 elements in the list.

152     224     127     457      45
325     411     391     437     372
128     479     480     281     110
69      41     335     390      36
448     318     463     343     273
181     245     291     133

-- Sorted List ---

36      41      45      69     110
127     128     133     152     181
224     245     273     281     291
318     325     335     343     372
390     391     411     437     448
457     463     479     480
Press any key to continue . . .

===========================================================

How many numbers do you want?: 12


There are 12 elements in the list.

101     220     228     201     237
12     190     312     276     206
410       5

1st element in list is : 101

Last element in list is: 5

Which element to display? (choose the index): 11
The number at [11] is: 5
Repeat? (y/n): n


--- removed 1st 3 elements ---
There are 9 elements in the list.

201     237      12     190     312
276     206     410       5

-- Sorted List ---

5      12     190     201     206
237     276     312     410
Press any key to continue . . .

===========================================================

How many numbers do you want?: -2
Enter a number greater than zero: 10


There are 10 elements in the list.

415     259     484      19     396
31     305     437      25     315


1st element in list is : 415

Last element in list is: 315

Which element to display? (choose the index): 0
The number at [0] is: 415
Repeat? (y/n): y
Which element to display? (choose the index): 9
The number at [9] is: 315
Repeat? (y/n): n


--- removed 1st 3 elements ---
There are 7 elements in the list.

19     396      31     305     437
25     315

-- Sorted List ---

19      25      31     305     315
396     437
Press any key to continue . . .

===========================================================

How many numbers do you want?: 15


There are 15 elements in the list.

244      55     180     327     390
275      74      63     439      37
188     132     259      74     371


1st element in list is : 244

Last element in list is: 371

Which element to display? (choose the index): -5
Index can't be less than zero: 0
The number at [0] is: 244
Repeat? (y/n): n


--- removed 1st 3 elements ---
There are 12 elements in the list.

327     390     275      74      63
439      37     188     132     259
74     371

-- Sorted List ---

37      63      74      74     132
188     259     275     327     371
390     439
Press any key to continue . . .
*/