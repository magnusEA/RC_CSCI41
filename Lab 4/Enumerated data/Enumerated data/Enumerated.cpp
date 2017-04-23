//Edgar Abundiz
//CSCI 41
//Lab 4 Structure & Enumerated Data Type
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;




enum Objects{ Valve, Bearing, Bushing, Coupling, Flange, Gear, GearHousing, Vacuum, Cable, Rod };

struct BinInfo
{
	Objects partName;
	int *partNum;
};

//-------------Function Prototype----------------------------
void DisplayPartsName(Objects);


int main()
{
	BinInfo Ptr;													
	BinInfo *bin;
	bin = &Ptr;

	bin->partNum = new int[10];
	int ObjectNum[] = { 10, 5, 15, 21, 7, 5, 5, 25, 18, 12 };   //initialize array
	
	Objects parts;
	for (int i = 0; i < 10; i++)
		bin->partNum[i] = ObjectNum[i];



	//for (parts = Valve; parts <= Rod; parts = static_cast<Objects>(parts + 1))
		 

	
	


	system("pause");
	return 0;
}









void DisplayPartsName(Objects p)
{

	switch (p)
	{
		case Valve: cout << "Valve";
			break;
		case Bearing: cout << "Bearing";
			break;
		case Bushing: cout << "Bushing";
			break;
		case Coupling: cout << "Coupling";
			break;
		case Flange: cout << "Flange";
			break;
		case Gear: cout << "Gear";
			break;
		case GearHousing: cout << "Gear Housing";
			break;
		case Vacuum: cout << "Vacuum Gripper";
			break;
		case Cable: cout << "Cable";
			break;
		case Rod: cout << "Rod";
			break;

	}
}
