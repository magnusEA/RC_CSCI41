//Edgar Abundiz
//CSCI 41
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

//-------------------create structure----------- has variables for everything that will be displayed at the end of the program
struct Student
{
	int studentID;
	string name;
	int *testScore;
	double average;
	char grade;
};

//--------------function prototype
int numStudents();
int *fiveScores(void);
double calcAverage(int *);
bool again();

int main()
{
	//------description-------
	cout << " This program will display a student's grade for 5 tests and the average " << endl << endl;


	//---------define variables
	Student *scorePtr;
	int SIZE = numStudents();
	cout << endl;
	scorePtr = new Student[SIZE];              //create dynamic array 
	
	

	//------get information for students 

	
	do
	{

		for (int i = 0; i < SIZE; i++)
		{

			cout << " Enter information for student " << i + 1 << endl << endl;

			cin.ignore();								  // prevent skip when asking for studnet names
			cout << "Enter student name: ";              // get name of student, number depends on how many entered earlier
			getline(cin, scorePtr[i].name);

			cout << "Enter student ID: ";
			cin >> scorePtr[i].studentID;               // get student Id, number depends on how many entered earlier
			cout << endl;

			scorePtr[i].testScore = fiveScores();       // put the 5 socres into *testScore
			cout << endl;
			scorePtr[i].average = calcAverage(scorePtr[i].testScore);  // calculate the average of the scores

			//------determine what letter grade student recieved depending on the average of the test scores
			if (scorePtr[i].average >= 90)
				scorePtr[i].grade = 'A';
			else if (scorePtr[i].average < 90 && scorePtr[i].average >= 80)
				scorePtr[i].grade = 'B';
			else if (scorePtr[i].average < 80 && scorePtr[i].average >= 70)
				scorePtr[i].grade = 'C';
			else if (scorePtr[i].average < 70 && scorePtr[i].average >= 60)
				scorePtr[i].grade = 'D';
			else
				scorePtr[i].grade = 'F';
			cout << endl;


		}
		//-----------From here on display the results from all data entered previously
		cout << "---------------------------------------Report-----------------------------------" << endl;

		cout << left << setw(21) << "Name" << setw(9) << " ID" << setw(29) << " Test Scores"
			<< setw(9) << "  Average" << "    Grade" << endl;
		cout << "------------------- | ------ | --------------------------- | -------- | -----" << endl;

		for (int x = 0; x < SIZE; x++)
		{
			cout << left << setw(16) << scorePtr[x].name << right << setw(10) << scorePtr[x].studentID << setw(6);

			for (int a = 0; a < 5; a++)
				cout << right << setw(6) << scorePtr[x].testScore[a];

			cout << right << setw(8) << scorePtr[x].average << setw(9) << scorePtr[x].grade << endl << endl;

			

		}

		
		//for (int j = 0; j < 5; j++)
			//delete scorePtr[j].testScore;
		

	} while (again());

	


	delete[] scorePtr;                                // delete data
	system("pause");
	return 0;
}


//------Function Definitions

int numStudents()
{
	int students;                                       
	cout << " Enter number of students: ";
	cin >> students;                                     // holds the number of students
	if (students < 1 || isalpha(students))				 // end program if invalid number or letter is entered
	{
		cout << " Invalid Entry, must be a positive number" << endl;   
		cout << " Start again." << endl;
		system("pause");
		exit (0);
	}

	return students;
}


int *fiveScores()                                      // ask for student's 5 test scores
{
	int i = 0;
	int *score;
	score = new int[5];
	
	cout << "Enter 5 test scores: " << endl;

	for (i = 0; i < 5; i++)
	{
		cout << "Test Score " << i + 1 << ": ";
		cin >> score[i];

		while (score[i] < 0)
		{
			cout << "Enter 0 or a positive number " << endl;
			cout << " Enter Again: ";
			cin >> score[i];
		}
	
	}

	
	return score;
	delete[] score;
}

double calcAverage(int *testScore)                    // calculate the average of the 5 scores that were inputted
{
	int x = 0;
	double avg;
	
	for (int i = 0; i < 5; i++)
	{
		x = x + testScore[i];
	}
	avg = x / 5.0;

	return avg;
}

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


//----------------------Test Cases-------------------
/*
This program will display a student's grade for 5 tests and the average

Enter number of students: 3

Enter information for student 1

Enter student name: Edgar Abundiz
Enter student ID: 545

Enter 5 test scores:
Test Score 1: 90
Test Score 2: 99
Test Score 3: 100
Test Score 4: 95
Test Score 5: 89


Enter information for student 2

Enter student name: Albert Que
Enter student ID: 891

Enter 5 test scores:
Test Score 1: 70
Test Score 2: 73
Test Score 3: 95
Test Score 4: 93
Test Score 5: 59


Enter information for student 3

Enter student name: Jon Doe
Enter student ID: 741

Enter 5 test scores:
Test Score 1: 85
Test Score 2: 54
Test Score 3: 96
Test Score 4: 41
Test Score 5: 99


---------------------------------------Report-----------------------------------

Name                  ID       Test Scores                   Average    Grade
------------------- | ------ | --------------------------- | -------- | -----
Edgar Abundiz          545    90    99   100    95    89    94.6        A

Albert Que             891    70    73    95    93    59      78        C

Jon Doe                741    85    54    96    41    99      75        C

Repeat? (y/n): n
Press any key to continue . . .
--------------------------------------------------------------------------------------------------------
This program will display a student's grade for 5 tests and the average

Enter number of students: 2

Enter information for student 1

Enter student name: Eddie Smalls
Enter student ID: 964

Enter 5 test scores:
Test Score 1: -9
Enter 0 or a positive number
Enter Again: 9
Test Score 2: 5
Test Score 3: 6
Test Score 4: 0
Test Score 5: 7


Enter information for student 2

Enter student name: Edea Smalls
Enter student ID: 842

Enter 5 test scores:
Test Score 1: -9
Enter 0 or a positive number
Enter Again: 54
Test Score 2: -8
Enter 0 or a positive number
Enter Again: 50
Test Score 3: -7
Enter 0 or a positive number
Enter Again: 63
Test Score 4: -8
Enter 0 or a positive number
Enter Again: 80
Test Score 5: -95
Enter 0 or a positive number
Enter Again: 50


---------------------------------------Report-----------------------------------

Name                  ID       Test Scores                   Average    Grade
------------------- | ------ | --------------------------- | -------- | -----
Eddie Smalls           964     9     5     6     0     7     5.4        F

Edea Smalls            842    54    50    63    80    50    59.4        F

Repeat? (y/n): n
Press any key to continue . . .
-------------------------------------------------------------------------------------------------
This program will display a student's grade for 5 tests and the average

Enter number of students: 0
Invalid Entry, must be a positive number
Start again.
Press any key to continue . . .
----------------------------------------------------------------------------------------------------
This program will display a student's grade for 5 tests and the average

Enter number of students: 1

Enter information for student 1

Enter student name: Edgar Abundiz
Enter student ID: 950

Enter 5 test scores:
Test Score 1: 50
Test Score 2: 50
Test Score 3: 60
Test Score 4: 30
Test Score 5: 40


---------------------------------------Report-----------------------------------

Name                  ID       Test Scores                   Average    Grade
------------------- | ------ | --------------------------- | -------- | -----
Edgar Abundiz          950    50    50    60    30    40      46        F

Repeat? (y/n): n
Press any key to continue . . .
*/