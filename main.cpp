#include "driver.h"
#include "drivers.h"
#include "ride.h"
#include "rides.h"
#include "passenger.h"
#include "passengers.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	cout << "------------------------------------------------------" <<endl;
        cout << "|       Class::   CSCE 1040                           |" << endl;
	cout << "|      Name:  Naomi Unuane                            |" << endl;
        cout << "|     Email: neu0006@my.unt.edu                       |" << endl;
	cout << "|     Program: Uber Rides Service                     |" << endl;
	cout << "|-----------------------------------------------------|" << endl;



Rides Ride;
Drivers Drive;
Passengers Pass;



int inputDrive;
int inputPass;
int inputRide;
int input;
do{
	cout<< "Choose  Options" <<endl;
	cout << "1.Ride" <<endl;
	cout << "2.Drivers" <<endl;
	cout << "3.Passengers" <<endl;
        cout << "4. Exit" <<endl;

cout << "Enter choice:" <<endl;
cin>>input;

switch(input)
		{
			case 1:
        			do{ cout << "Rides Menu " <<endl;
                                cout << " Select Option '1' to add Ride" <<endl;
				cout << " Select Option '2' to edit Ride" <<endl;
				cout << " Select Option '3' to DELETE Ride" <<endl;
				cout << " Select Option '4' to FIND Ride" <<endl;
				cout << " Select Option '5' to List all entries in the Ride" <<endl;
				cout << " Select Option '6' to Print details of a single ride" <<endl;
				cout << " Select Option '7' to List Rides Status" <<endl;
				cout << " Select Option '8' to update  Ride" <<endl;
                                cout << " Select Option '9' to Print The Passenger Rides" <<endl;
				cout << " Select Option '10' to delete cancelled rides " <<endl;
				cout << " Select Option '11' to end program" <<endl;

					cin >> inputRide;
					switch(inputRide)
					{
						case 1:
							Ride.AddRide(Drive,Pass);
							break;
						case 2:
							Ride.editRide();
							break;
						case 3:
							Ride.Delete();
							break;
						case 4:
							Ride.findRide();
							break;
						case 5:
							Ride.printList();
							break;
						case 6:
							Ride.printDetails();
							break;
						case 7:
							Ride.printStatus();
							break;
						case 8:
							Ride.updateRides();
							break;
						case 9:
  						        Ride.printListRidesPasse();
							break;
						case 10:
							Ride.cancelRides();
							break;
						default: 
							cout << "Invalid Number" << endl;
							break;

					}
				}while(inputRide!= 11);
				break;
		
case 2:
do{
cout << "Drivers Menu " <<endl;
cout << " Select Option '1' to add Driver" <<endl;
cout << " Select Option '2' to edit Driver" <<endl;
cout << " Select Option '3' to DELETE Driver" <<endl;
cout << " Select Option '4' to FIND Driver" <<endl;
cout << " Select Option '5' to List all entries in the Driver" <<endl;
cout << " Select Option '6' to Print details of a Driver" <<endl;
cout << " Select Option '7' to end program" <<endl;

cin>>inputDrive;
switch(inputDrive){
case 1:
Drive.addDrive();
break;
case 2:
Drive.editDrive();
break;
case 3:
Drive.deleteDrive();
break;
case 4:
Drive.findDriver();
break;
case 5:
Drive.PrintEntries();
break;
case 6:
Drive.PrintSingleDrive();
break;
}
}while(inputDrive!=7);
break;


case 3:

do{
cout<< "Passengers Menu" <<endl;
cout << " Select Option '1' to add Passenger" <<endl;
cout << " Select Option '2' to edit Passenger" <<endl;
cout << " Select Option '3' to DELETE Passenger" <<endl;
cout << " Select Option '4' to FIND Passenger" <<endl;
cout << " Select Option '5' to List all entries in the Passengers" <<endl;
cout << " Select Option '6' to Print details of a single Passenger" <<endl;
cout << " Select Option '7' to quit " <<endl;
cin>>inputPass;
switch(inputPass){
case 1:
Pass.addPass();
break;
case 2:
Pass.editPass();
break;
case 3:
Pass.deletePass();
break;
case 4:
Pass.findpass();
break;
case 5:
Pass.PrintEntryList();
break;
case 6:
Pass.PrintRidesPass();
break;
}
}while(inputPass!=7);
break;


}
}while(input !=4);




Pass.passengerList.clear();
Drive.driverList.clear();
Ride.rideList.clear();




    return 0;
}
