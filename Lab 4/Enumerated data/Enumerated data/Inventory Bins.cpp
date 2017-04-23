//Edgar Abundiz
//CSCI 41
//Lab 4 Inventory Bins
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;



//-------------------define enumerated values
enum Objects{ Valve, Bearing, Bushing, Coupling, Flange, Gear, GearHousing, Vacuum, Cable, Rod };

//--------define structure Bin Info
struct BinInfo
{
	string partName;
	int partNum;
};

//-------------Function Prototype----------------------------
int Add_Parts();
int Sub_Parts();
bool again();

int main()
{
	//-------------------allocate part names and amounts/ other variables
	BinInfo bin[10] = { { "Valve", 10 }, { "Bearing", 5 }, {"Bushing", 15}, {"Coupling", 21}, {"Flange", 7}, {"Gear", 5}, 
	{"Gear Housing", 5}, {"Vacuum Gripper", 25}, {"Cable", 18}, {"Rod", 12} };
	int choice;
	string select;
	BinInfo x;

	//-------------------------initital description
	cout << " These are the parts with the current amount available in the bin." << endl;
	cout << "------------------------------------------------------------------" << endl << endl;
	
	

		
			//---------display initial quantities
			for (int i = 0; i < 10; i++)
			{
				cout << left << setw(20) << bin[i].partName << right << setw(20) << bin[i].partNum << endl;
				cout << endl;

			}
			cout << "--------------------------------------------------------------------" << endl << endl;
		do
		{
			//---------------------present bin choices
			cout << "Which bin would you like to choose?" << endl;

			cout << endl;
			for (int p = 0; p < 10; p++)
			{
				cout << endl;
				switch (p)
				{
				case Valve: cout << Valve + 1 << ". Valve" << endl;
					break;
				case Bearing: cout << Bearing + 1 << ". Bearing" << endl;
					break;
				case Bushing: cout << Bushing + 1 << ". Bushing" << endl;
					break;
				case Coupling: cout << Coupling + 1 << ". Coupling" << endl;
					break;
				case Flange: cout << Flange + 1 << ". Flange" << endl;
					break;
				case Gear: cout << Gear + 1 << ". Gear" << endl;
					break;
				case GearHousing: cout << GearHousing + 1 << ". Gear Housing" << endl;
					break;
				case Vacuum: cout << Vacuum + 1 << ". Vacuum Gripper" << endl;
					break;
				case Cable: cout << Cable + 1 << ". Cable" << endl;
					break;
				case Rod: cout << Rod + 1 << ". Rod" << endl;
					break;
				}
			}
			cout << endl;
			cout << "11. Quit" << endl;
			cout << " Choice: ";
			cin >> choice;

			//--------------------------associate choice with part

			if (choice == 1)
				cout << bin[0].partName << "     " << bin[0].partNum << endl;

			else if (choice == 2)
				cout << bin[1].partName << "     " << bin[1].partNum << endl;

			else if (choice == 3)
				cout << bin[2].partName << "     " << bin[2].partNum << endl;

			else if (choice == 4)
				cout << bin[3].partName << "     " << bin[3].partNum << endl;

			else if (choice == 5)
				cout << bin[4].partName << "     " << bin[4].partNum << endl;

			else if (choice == 6)
				cout << bin[5].partName << "     " << bin[5].partNum << endl;

			else if (choice == 7)
				cout << bin[6].partName << "     " << bin[6].partNum << endl;

			else if (choice == 8)
				cout << bin[7].partName << "     " << bin[7].partNum << endl;

			else if (choice == 9)
				cout << bin[8].partName << "     " << bin[8].partNum << endl;

			else if (choice == 10)
				cout << bin[9].partName << "     " << bin[9].partNum << endl;

			else
			{
				system("pause");
				return EXIT_SUCCESS;
			}
			

			//---------------add or subtract parts from choice made
			cin.ignore();
			cout << "Add or subtract parts from bin?(add/sub) " << endl;
			getline(cin, select);

			//---------------------change amount of parts added or subtracted and dont allow there to be more than 30 or less than 0 parts
			if (select == "ADD" || select == "add" || select == "Add")
			{
				x.partNum = bin[choice - 1].partNum;
				bin[choice - 1].partNum += Add_Parts();
				if (bin[choice - 1].partNum > 30)
				{
					cout << " Cannot change bin by that amount " << endl << endl;
					bin[choice - 1].partNum = x.partNum;
				}
			}

			if (select == "SUB" || select == "sub" || select == "Sub")
			{
				x.partNum = bin[choice - 1].partNum;
				bin[choice - 1].partNum += Sub_Parts();
				if (bin[choice - 1].partNum < 0)
				{
					cout << "Cannot change bin by that amount " << endl << endl;
					bin[choice - 1].partNum = x.partNum;
				}
			}

			else
				cout << bin[choice - 1].partName << " now has " << bin[choice - 1].partNum << " available. " << endl;

	//-----------------------------display updated quantities
			for (int i = 0; i < 10; i++)
			{
				cout << left << setw(20) << bin[i].partName << right << setw(20) << bin[i].partNum << endl;
				cout << endl;

			}
			cout << "--------------------------------------------------------------------" << endl << endl;
			
	} while (again());
		 

	system("pause");
	return 0;
}



int Add_Parts()
{
	
	int num;
	cout << "Add how many parts? (Bin max = 30): ";
	cin >> num;
	if (num < 0)
	{
		cout << "Please enter a number equal to or above 0: ";
		cin >> num;
	}
	return num;
}

int Sub_Parts()
{
	
	int num1;
	cout << "Subtract how many parts? (Bin min = 0): ";
	cin >> num1;
	if (num1 < 0)
	{
		cout << "Please enter a number equal to 0 or above: ";
		cin >> num1;
	}
	return num1;
}


bool again()
{
	char y;
	cout << "Repeat? (y/n): ";
	cin >> y;
	cout << endl;
	if (y == 'y' || y == 'Y')
		return true;
	else
		return false;

}

//------------------Test Cases---------------------
/*
These are the parts with the current amount available in the bin.
------------------------------------------------------------------

Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Which bin would you like to choose?


1. Valve

2. Bearing

3. Bushing

4. Coupling

5. Flange

6. Gear

7. Gear Housing

8. Vacuum Gripper

9. Cable

10. Rod

11. Quit
Choice: 8
Vacuum Gripper     25
Add or subtract parts from bin?(add/sub)
add
Add how many parts? (Bin max = 30): 6
Cannot change bin by that amount

Vacuum Gripper now has 25 available.
Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Repeat? (y/n): n

Press any key to continue . . .
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

These are the parts with the current amount available in the bin.
------------------------------------------------------------------

Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Which bin would you like to choose?


1. Valve

2. Bearing

3. Bushing

4. Coupling

5. Flange

6. Gear

7. Gear Housing

8. Vacuum Gripper

9. Cable

10. Rod

11. Quit
Choice: 1
Valve     10
Add or subtract parts from bin?(add/sub)
add
Add how many parts? (Bin max = 30): 10
Valve now has 20 available.
Valve                                 20

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Repeat? (y/n): n

Press any key to continue . . .
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

These are the parts with the current amount available in the bin.
------------------------------------------------------------------

Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Which bin would you like to choose?


1. Valve

2. Bearing

3. Bushing

4. Coupling

5. Flange

6. Gear

7. Gear Housing

8. Vacuum Gripper

9. Cable

10. Rod

11. Quit
Choice: 11
Press any key to continue . . .
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

These are the parts with the current amount available in the bin.
------------------------------------------------------------------

Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Which bin would you like to choose?


1. Valve

2. Bearing

3. Bushing

4. Coupling

5. Flange

6. Gear

7. Gear Housing

8. Vacuum Gripper

9. Cable

10. Rod

11. Quit
Choice: 3
Bushing     15
Add or subtract parts from bin?(add/sub)
sub
Subtract how many parts? (Bin min = 0): -100
Please enter a number equal to 0 or above: 0
Valve                                 10

Bearing                                5

Bushing                               15

Coupling                              21

Flange                                 7

Gear                                   5

Gear Housing                           5

Vacuum Gripper                        25

Cable                                 18

Rod                                   12

--------------------------------------------------------------------

Repeat? (y/n): n

Press any key to continue . . .






*/