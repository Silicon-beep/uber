#include "drivers.h"
//#include "driver.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int Drivers ::getcount(){return drivcount;}
void Drivers:: inccount() {drivcount++;}
void Drivers:: deccount() {drivcount--;}

void Drivers ::addDrive(){ //add function
int id;
string name;
int capacity;
bool handi;
string type; //vehicle type
float rating;
char avail;
bool available;
bool pets;
char choice;

cout << "Enter Driver ID:" <<endl;
cin>>id;
cin.ignore();

cout << "Enter Name of Driver: " <<endl;
cin.ignore();
getline(cin,name);

cout << "Enter the driver capacity:" <<endl;
cin>>capacity;
cin.ignore();
  
do{
cout << "Accepts handicapped T/F? " <<endl;
cin>>choice;
cin.ignore();
}while(choice!= 'T' & choice!='t' & choice!='f'& choice!='F');

if(choice == 'T' & choice =='t'){
handi = true;}
else{
handi= false;
}

  
 cout << "Enter rating from 1-5" <<endl;
 cin>>rating;
cin.ignore();

do{
cout << "Are you available: Y/N " <<endl;
cin>>avail;
cin.ignore();
}while(avail!= 'Y' & avail!= 'y' & avail != 'N' & avail!='n');
if(available == 'Y' & available =='y'){
available = true;}
else{
available = false;
}
//Driver(int id, string name, int numOfPassenger,bool handiCapp,string type, float rating,bool pets,bool available);

Driver Drive(id,name,capacity, handi,type,rating,available,pets);
driverList.push_back(Drive);
cout << "The driver has been added" <<endl;
}


void Drivers:: editDrive(){
int id;
int i = findDrives(id);
int option;
char avail;
char petChoice;
string userName; //driver name
int thePassenger; //the capacity of driver
char thehandiCapp; //handicapp choice
float userRating; //the rating 
string type;
cout << "Enter your ID:" <<endl;
cin>>id;
cin.ignore();

do{
    cout << "SELECT THE NUMBER TO EDIT" <<endl;

	cout << "'1' to edit name" << endl;
	cout << "'2' to edit vehicle capacity" << endl;
	cout << "'3' to edit handicapp" << endl;
	cout << "'4' to edit vehicle type" <<endl;
	cout << "'5' to edit driver Rating" << endl;
	cout << "'6' to edit the avalabilty" <<endl;
	cout << "'7' to edit pets is allowed" <<endl;
	cout << "'8' to quit" << endl;
	
	cout << "Select an option: " << endl;
	cin>>option;
	cin.ignore();
	
	switch(option){
	case 1:
	cout << "please enter the name";
        cin.ignore();
	getline(cin,userName);
	driverList.at(i).SetName(userName);
	break;
	
	case 2:
	cout<< "edit vehicle capacity "<<endl;
	cin>>thePassenger;
	driverList.at(i).SetPassenger(thePassenger);
	cin.ignore();
	break;
	
	case 3:
	do{
	cout<< "Edit Handicapped Y/N" <<endl;
	cin>>thehandiCapp;
	driverList.at(i).SetHandicapp(thehandiCapp);
        cin.ignore();
  }while(thehandiCapp!= 'Y' & thehandiCapp!='N' & thehandiCapp!='y'& thehandiCapp !='n');
if(thehandiCapp == 'Y' & thehandiCapp =='y'){

    driverList.at(i).GetHandicapp();
}
else{
    driverList.at(i).GetHandicapp();
}



	break;
	
	case 4:
	cout<< " edit driver vehicle type " <<endl;
	cin.ignore();
	getline(cin,type);
	driverList.at(i).SetType(type);
	break;
	
	case 5:
	cout << "driver rating to " <<endl;
        cin>>userRating;
        driverList.at(i).SetRating(userRating);
        cin.ignore();
	break;
	
	case 6:
do{
	cout<< "Edit Avalability Y/N" <<endl;
	cin>>avail;
}while(avail!= 'Y' & avail!='N' & avail !='y'& avail!='n');
if(avail == 'Y' || avail =='y'){
	driverList.at(i).Setavailable(true);
    

}
else{
    	driverList.at(i).Setavailable(false);

}
	break;
	

	case 7:
	
do{
	cout << "Edit Pets allowed Y/N: " <<endl;
	cin>>petChoice;
	//driverList.at(i).Setpets(petChoice);
        cin.ignore();
}while(petChoice != 'Y' & petChoice !='N' & petChoice!='y' & petChoice!='n');
if(petChoice== 'Y' & petChoice =='y'){

    driverList.at(i).Setpets(true);
}
else{
   driverList.at(i).Setpets(false);
}

	break;
	
	case 8:
	cout << "'8' to quit" << endl;
	break;

    default:
    cout<< "option not available"<<endl;
    break;

	
	}
    
}while(option!=8);

}

    
void Drivers:: deleteDrive(){ //delete
int index;
int id;
cout << "Enter the Driver ID to delete: " <<endl;
cin>>id;
index = findDrives(id);
if (index == -1){ 
cout << "Driver is not here." <<endl; 
return;}
else{
driverList.erase(driverList.begin()+index);}
cout << "The Driver has been deleted" <<endl;
}




void Drivers::findDriver(){ //find driver based on ID
    int id;
    cout << "Enter Driver ID: " <<endl;
    cin>>id;
    cin.ignore();
    for(int i=0;i<driverList.size();i++){
    if(driverList[i].GetId()==id){
        cout << "Passenger ID is in the system"<<endl;
        return;
    }
    cout << "Driver is not in the systems"<<endl;
    
}
}


int Drivers:: findDrives(int id){
int i;
for(int i=0;i<driverList.size();i++){
if(driverList.at(i).GetId()==id){
    return i;
}
}
return -1;
}



void Drivers:: PrintEntries(){ //list
    for(int i =0;i<driverList.size();i++){
    cout << "ID:" <<driverList.at(i).GetId();
    cout << "Name :" <<driverList.at(i).GetName();
    cout << "Number of Passengers: " <<driverList.at(i).GetPasseger();
    cout << "Handicapped Capable: " << driverList.at(i).GetHandicapp();
    cout << "Vehicle Type: " <<driverList.at(i).GetType();
    cout << "The rating :" <<fixed<<setprecision(2)<<driverList.at(i).GetRating();
    cout << "The Availability: "<<driverList.at(i).GetAvailable();
    cout << "The Pets allowed:"<<driverList.at(i).GetType();
    }
    if(driverList.size() ==0){
        cout << "No drivers in the system."<<endl;
    }
}


void Drivers:: PrintSingleDrive(){
    int id;
    cout << "Enter your Passenger ID " <<endl;
    cin>>id;
    cin.ignore();
    for(int i=0;i<driverList.size();i++){
        if(driverList.at(i).GetId()==id){
            driverList.at(i).PrintInfo();
        }
} //details for a single entity

}


void Drivers::loadData(){
    ifstream fin;
    int yourID;
    string yourName;
    int yourcapacity;
    bool yourHandicapp;
    string yourType;
    float yourRating;
    bool yourPets;
    bool youravailable;
    
    fin.open("drivers.dat");
    if(fin.fail()){
        cout << "No Data...." <<endl;
        return;
    }
    
    
for(int i=0;i<drivcount;i++){
    fin>>yourID;
    fin.ignore();
    getline(cin,yourName);
    fin>>yourcapacity;
    fin.ignore();
    fin>>yourHandicapp;
    fin.ignore();
    fin>>yourType;
    fin.ignore();
    fin>>yourRating;
    fin.ignore();
    fin>>yourPets;
    fin.ignore();
    fin>>youravailable;
    fin.ignore();
Driver Drive = Driver(yourID,yourName,yourcapacity,yourHandicapp,yourType,yourRating,yourPets,youravailable);
driverList.push_back(Drive);
    
 }
 fin.close();
}


void Drivers:: storeData(){
    ofstream fout;
    fout.open("drivers.dat");
fout << driverList.size() <<endl;
    for(int i =0;driverList.size();i++){
    fout<<driverList.at(i).GetId()<<endl;
    fout<<driverList.at(i).GetName()<<endl;
    fout<<driverList.at(i).GetPasseger()<<endl; //capacity
    fout<<driverList.at(i).GetHandicapp()<<endl;
    fout<<driverList.at(i).GetRating()<<endl;
    fout<<driverList.at(i).GetType()<<endl;
    fout<<driverList.at(i).GetAvailable()<<endl;
    fout<<driverList.at(i).GetPets()<<endl;
    }
    fout.close();

}


