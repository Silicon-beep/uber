
#include "drivers.h"
#include "passengers.h"
#include "ride.h"
#include "rides.h"
#include "driver.h"
#include "passenger.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <ctime>


using namespace std;

//int Rides:: getcount(){ return int;}
void Rides :: inccount(){}
void Rides:: deccount(){}

void Rides::AddRide(Drivers &Drive, Passengers &Pass){
Ride newRide;
int id; 
string pickup; //pickup location dtring
time_t pickupTime;
int hours;
int minute;
string dropoff;
int size; //size of party
char pet;
bool pets;
time_t dropoffTime;
char status; //active
float rating;
    

cout << "Enter your ID:";
cin>>id;
cin.ignore();
cout<< "Pick up Location:";
cin.ignore();
getline(cin,pickup);
cout << "Enter Pick up time(Hours first,then next Line Minutes) "<<endl;
cin>>hours>>minute;
pickupTime= time(0);
cin.ignore();
cout << "Enter dropoff Location: " <<endl;
cin.ignore();
getline(cin,dropoff);

cout << "Enter Size of Party: "<<endl;
cin>>size;
cin.ignore();
do{
cout << "Pets included, Enter Y/N"<<endl;
cin>>pet;
cin.ignore();
}while(pet!= 'Y' & pet!='N' & pet!='y'& pet!='n');
if(pet == 'Y' & pet =='y'){
    pets = true;
}
else{
    pets= false;
}
//cout << "Enter Drop off Time " <<endl; //when user changes status to completed  if status = completed change to drop of time
//cin>>hours>>minute;
//dropoffTime = pickupTime + 900;
//cin.ignore();
cout<< "Enter Status:'A' Active,' C' Completed,'D' Cancelled" <<endl;
cin>>status;
cin.ignore();
if(status == 'C'){
dropoffTime = time(0);

}


cout << "Enter rating, from 1-5: " <<endl;
cin>>rating;
cin.ignore();
//Ride::Ride(int id,string pickup,time_t pickupTime,string dropoff,int size,bool pets,time_t dropoffTime,char status,float rating){

Ride myRide(id,pickup,pickupTime,dropoff,size,pets,dropoffTime,status,rating);
rideList.push_back(myRide);
cout << "Rides Info have been added" <<endl;
}




void Rides:: editRide(){
    int id;
    cout << "Enter your ID to edit :" <<endl;
    cin>>id;
    cin.ignore();
    int choice;
    int choice1;
    int choice2;
    string pickup; //pickup location dtring
    time_t pickupTime;
    string dropoff;
    int size; //size of party
    time_t dropoffTime = time(0);
    char status; //active
    
        cout << "  Select what to edit"<<endl;
        cout << " '1' pickup location" << endl;
	cout << " '2' DropOff Location" << endl;
	cout << " '3'  Size of Party" <<endl;
	cout << " '4' Status of the ride 'A'- active, 'C'- for complete, 'D' for cancelled"<< endl;
	cin>>choice;
	cin.ignore();
    switch(choice){
    case 1:
    cout << "Enter new Location for pickup" <<endl;
    cin.ignore();
    getline(cin,pickup);
    rideList.at(SearchID(id)).setPickup(pickup);
    break;
    
    case 2:
    cout << "Enter new Location for Drop off"<<endl;
    cin.ignore();
    getline(cin,dropoff);
    rideList.at(SearchID(id)).setDropOff(dropoff);
    break;
    case 3:
    cout << "Enter new size of Party" <<endl;
    cin>>size;
    rideList.at(SearchID(id)).setSize(size);
    cin.ignore();
    break;
    case 4:
    cout << "Enter new status for the ride" <<endl;
    cin>>status;
    rideList.at(SearchID(id)).setStatus(status);
    cin.ignore();
    if(status == 'C'){
    rideList.at(SearchID(id)).setDropOffTime(dropoffTime);
    char* current = ctime(&dropoffTime);
    cout << "The drop of time is " << current<<endl;
}
    break;

    default:
	cout << "Not avalable ....." << endl;
	break;        
        
    }
}

void Rides::printList(){ 
    for(int i=0;i<rideList.size();i++){
        rideList[i].PrintInfoRide();
    }
    if(rideList.size()==0){
        cout << "No rides" <<endl;
    }
}

void Rides:: findRide(){
int id;
cout << "Enter your Ride ID; " <<endl;
cin>>id;
cin.ignore();
for(int i =0; i<rideList.size();i++){
if(rideList[i].getID()==id){
cout << "Rider is present" <<endl;
return;
}
cout << "Ride is unavailable" <<endl;
}
}


int Rides::SearchID(int id){ 
int i;
for(int i=0;i<rideList.size();i++){
if(rideList.at(i).getID()==id){
return i;
}
}
return -1;
}




void Rides:: printDetails(){ //details of ride
int i = 0;
int id;
time_t myTime;
cout << "Enter ID of Rides "<<endl;
cin>>id;
if(SearchID(id)==-1){
cout << "The ID is not in the system" <<endl;
}
cout << rideList.at(i).getID()<<endl;
cout << rideList.at(i).getPickup()<<endl;
cout << "The Pick-up time: ";	
myTime = rideList.at(i).getPickupTime();
cout << asctime(gmtime(&myTime));
cout << rideList.at(i).getDropOff();
cout << rideList.at(i).getSize();
cout << rideList.at(i).getPets()<<endl;
cout << "The drop-off time: ";
myTime = rideList.at(i).getDropoffTime();
cout << asctime(gmtime(&myTime));
cout << rideList.at(i).getStatus()<<endl;
cout << rideList.at(i).getRating()<<endl;
}
    

void Rides::printStatus(){ // 
        time_t myTime;
	char choice;
        //char * current = ctime(&myTime);
        
	cout << "Select option to Print " <<endl;
	cout << "'A' for Active" << endl;
	cout << "'C' for Completed" << endl;
	cout << "'D' for Cancelled" << endl;
	cin >> choice;
	switch(choice){
		case 'A':
			for( int i = 0; i < rideList.size(); i++){
				if(rideList.at(i).getStatus() == 'A'){
					cout << rideList.at(i).getID() <<endl;
					cout << rideList.at(i).getPickup()<<endl;
					cout << "The Pick-up time";	
					myTime = rideList.at(i).getPickupTime();
					cout << asctime(gmtime(&myTime));
					cout << rideList.at(i).getDropOff();
					cout << rideList.at(i).getSize()<<endl;
					cout << rideList.at(i).getPets()<<endl;
					cout << "The drop-off time";
					myTime = rideList.at(i).getDropoffTime();
					cout << asctime(gmtime(&myTime)) << endl;	
					cout << rideList.at(i).getStatus()<<endl;
					cout << rideList.at(i).getRating()<<endl;
                                        cout << "ACTIVE RIDES" <<endl;
				}
			}
			break;
		case 'C':
			for( int i = 0; i < rideList.size(); i++){
				if(rideList.at(i).getStatus() == 'C'){
					cout << rideList.at(i).getID()<<endl;
					cout << rideList.at(i).getPickup()<<endl;
					cout<< "The Pick-up time"  << endl;	
					myTime = rideList.at(i).getPickupTime();
					cout << asctime(gmtime(&myTime));
					cout << rideList.at(i).getDropOff();
					cout << rideList.at(i).getSize();
					cout << rideList.at(i).getPets();
					cout << "The drop-off time" << endl;
					myTime = rideList.at(i).getDropoffTime();
					cout << asctime(gmtime(&myTime)) << endl;	
					cout << rideList.at(i).getStatus()<<endl;
					cout << rideList.at(i).getRating()<<endl;	
  					cout << "Cancelled Rides " <<endl;		
				}
			}
			break;
		case 'D':
			for( int i = 0; i < rideList.size(); i++){
				if(rideList.at(i).getStatus() == 'D'){
					cout << rideList.at(i).getID()<<endl;
					cout << rideList.at(i).getPickup()<<endl;
					cout << "The Pick-up time: ";	
					myTime = rideList.at(i).getPickupTime();
					cout << asctime(gmtime(&myTime));
					cout << rideList.at(i).getDropOff()<<endl;
					cout << rideList.at(i).getSize()<<endl;
					cout << rideList.at(i).getPets()<<endl;
					cout << "The drop-off time"<<endl;
					myTime = rideList.at(i).getDropoffTime();
					cout << asctime(gmtime(&myTime)) << endl;	
					cout << rideList.at(i).getStatus();
					cout << rideList.at(i).getRating()<<endl;
					cout << "Deleted Rides" <<endl;
				}
			}
			break;
		default:
			cout << "Option not available" << endl;
			break;
	}
}




void Rides::cancelRides() // cancell rides
{
 	int index;
	for (int i =0; i <rideList.size(); ++i)
	{
		if (rideList.at(i).getStatus() == 'C' || rideList.at(i).getStatus()=='D')
		{ index = SearchID(rideList.at(i).getID());
		    
		}
	}
	rideList.erase(rideList.begin() +index);
}


void Rides::printListRidesPasse(){
    int id;
    cout << "Enter your ID for Passengers"<<endl;
    cin>>id;
    cin.ignore();
    int index;
     index =SearchID(id);
    if(index == -1){
cout << "Passenger doesn't have any Rides" <<endl;
}
    cout<< "The List for Passenger  Rides" <<endl;
	for (int i =0; i < rideList.size(); ++i)
	{
		if (rideList[i].getID() == id)
		{
			rideList[i].PrintInfoRide();
		}
	}
}



void Rides::printListRidesDriver(){
int index;
int id;
cout << "Enter your ID:" <<endl;
cin>>id;
cin.ignore();
index =SearchID(id);
if(index ==-1){
cout << "The driver doesn't have any rides" <<endl;
}
	cout<< "The List for Driver Rides" <<endl;
	for (int i =0; i < rideList.size(); ++i)
	{
		if (rideList[i].getID() == id)
		{
			rideList[i].PrintInfoRide();
		}
	}
}



void Rides::Delete(){
int index;
int id;
cout << "Enter the Ride ID to delete: " <<endl;
cin>>id;
index=SearchID(id);
if(index == -1){
cout << "Rides is unavailable. "<<endl;
return;}
else{
rideList.erase(rideList.begin()+index);}
cout << "The Rides has been deleted" <<endl;
}
    
void Rides:: loadRide(){
    ifstream fin;
    int Myid;
    int MygetID;
    string MygetPickup;
    time_t MygetPickupTime;
    string MygetDropOff;
    int MygetSize;
    bool MygetPets;
    time_t MygetDropoffTime;
    int MygetStatus;
    float MygetRating;
    
    
    fin.open("Rides.dat");
    if(fin.fail()){
        cout << "Error." <<endl;
        return;
    }
fin>>ridecount;
fin.ignore();
 for(int i=0;i < ridecount;i++){
    fin>>MygetID;
    fin.ignore();
    getline(fin,MygetPickup);
    fin>>MygetPickupTime;
    fin.ignore();
    getline(fin,MygetDropOff);
    fin>> MygetSize;
    fin.ignore();
    fin>> MygetPets;
    fin.ignore();
    fin>> MygetDropoffTime;
    fin.ignore();
    fin>> MygetStatus;
    fin.ignore();
    fin>> MygetRating;
    fin.ignore();
    

Ride myRide(MygetID,MygetPickup,MygetPickupTime,MygetDropOff,MygetSize,
    MygetPets,MygetDropoffTime,MygetStatus,MygetRating);
rideList.push_back(myRide);
}
fin.close();
}


void Rides::updateRides(){
time_t current;
	current = time(0);
	for(int i = 0; i < rideList.size(); i++){
		if(current > rideList.at(i).getDropoffTime()){
			rideList.at(i).setStatus('C');
		}
	}
}

void Rides:: storeRide(){
    ofstream fout;
    fout.open("Rides.dat");
    fout << rideList.size()<<endl;
    
    for(int i=0;i<rideList.size();i++){
    fout<<rideList[i].getID()<<endl;
    fout<<rideList[i].getPickup()<<endl;
    fout<<rideList[i].getPickupTime()<<endl;
    fout<<rideList[i].getDropOff()<<endl;
    fout<<rideList[i].getSize()<<endl;
    fout<<rideList[i].getPets()<<endl;
    fout<<rideList[i].getDropoffTime()<<endl;
    fout <<rideList[i].getStatus()<<endl;
    fout<<rideList[i].getRating()<<endl;
    }
    fout.close();
}