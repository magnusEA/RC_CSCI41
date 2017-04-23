#include <iostream>
#include <cstdlib>
#include<list>
using namespace std;

void display(list<int> &);

int main()
{
	list<int> x;
	list<int>::iterator it; // it is a pointer to an element of the list

	
	x.push_back(10);
	x.push_front(100);
	x.push_back(20);

	it = x.begin();
	x.insert(it, 200);    


	// display a list
	display(x);





	cout << endl;
	system("pause");
	return 0;
}

//------------------------------------
void display(list<int> &x)
{
	list<int>::iterator it;
	for (it = x.begin(); it != x.end(); ++it)
	{
		cout << *it << " ";
	}
}
