#include <iostream>
#include "passenger.h"
#include "passengers.h"
#include <vector>
#include <string>
#include <iterator>
#include <iomanip>
#include <fstream>

using namespace std;


void Passengers:: addPass(){
    string passName;
    int ID;
    string Payment;
    char choice;
    bool Handicapped;
    float rating;
    char pchoice;
    bool pets;

cout << " Enter name of Passenger: "<<endl;
cin.ignore();
getline(cin,passName);

cout<< "Enter your ID:" <<endl;
cin>>ID;
cin.ignore();

cout <<"Enter your Payment Method: 'c'-credit; 'd'-debit;'m'-cash"<<endl;
cin>>Payment;
cin.ignore();

do{
cout <<"Are you Handicapped: Y/N"<<endl;
cin>>choice;
cin.ignore();
}while(choice!= 'Y' & choice!='N' & choice!='y'& choice!='n');
if(choice == 'Y' & choice =='y'){
    Handicapped = true;
}
else{
    Handicapped = false;
}

cout<< "Rating for Passengers " <<endl; 
cin>>rating;
cin.ignore();

do{
cout << "Any pets Y/N" <<endl;
cin>>pchoice;
cin.ignore();

}while(pchoice != 'Y'& pchoice!='y' & pchoice!='N'& pchoice!='n');
if(pchoice == 'Y' & pchoice == 'y'){
    pets =true;
}
else{
    pets =false;
}

//Passenger(string name,int id,string payment,bool handicaaped,float rating,bool pets); //second contrucotr
Passenger myPass(passName,ID,Payment,Handicapped,rating,pets);
passengerList.push_back(myPass);
storePassengers();
cout << "The passengers have been added " <<endl;
}

void Passengers::editPass(){

int id;
int i = findPass(id);
int passOption;
string passName;
int passID;
string passPay;
//bool passHandicap;
char passHandi;
float passRating;
char passPets;
//bool passPets;

cout << "Enter your ID:" <<endl;
cin>>passID;
cin.ignore();

do{
    cout << "SELECT THE NUMBER TO EDIT" <<endl;

	cout << "'1' to edit name" << endl;
	cout << "'2' to edit ID number" << endl;
	cout << "'3' to edit Payment Preference: " << endl;
	cout << "'4' to edit if handicapped" <<endl;
	cout << "'5' to edit rating" << endl;
	cout << "'6' to edit pets is allowed" <<endl;
	cout << "'7' to quit" << endl;
	
	cout << "Select an the number to Edit Passenger: " << endl;
	cin>>passOption;
	cin.ignore();

	switch(passOption){
	case 1:
	cout << "Please enter the name";
	cin.ignore();
	getline(cin,passName);
	passengerList.at(i).setName(passName);
	break;
	
	case 2:
	cout<< "edit your ID Number: "<<endl;
	cin>>passOption;
	passengerList.at(i).setID(passOption);
	cin.ignore();
	break;
	
	case 3:
	cout << "edit to edit Payment" <<endl;
	cin.ignore();
	getline(cin,passPay);
	passengerList.at(i).setPayment(passPay);
	break;
	
	case 4:
do{
	cout<< "edit Handicapped Y/N" <<endl;
	cin>>passHandi;
        cin.ignore();
}while(passHandi != 'Y' & passHandi !='N' & passHandi !='y'& passHandi !='n');
if(passHandi  == 'Y' & passHandi =='y'){

    passengerList.at(i).setHandicapped(true);
}
else{
    passengerList.at(i).setHandicapped(false);
}
	break;
	
	case 5:
	cout << "edit Rating " <<endl;
	cin>>passRating;
	passengerList.at(i).setRating(passRating);
	cin.ignore();
	break;
	
	case 6:
do{
	cout << "edit Pets allowed Y/N" <<endl;
	cin>>passPets;
        cin.ignore();
}while(passPets != 'Y' & passPets !='N' & passPets!='y'& passPets!='n');
if(passPets == 'Y' & passPets =='y'){

    passengerList.at(i).setPets(true);
}
else{
    passengerList.at(i).setPets(false);
}

	break;
	
    default:
    cout<< "option not available"<<endl;
    break;

	
	}
    
}while(passOption!=7);
//storePassengers();
}





void Passengers:: deletePass()
{
int id;
    char input;
    int i= findPass(id);
    do{
    cout << "Delete Passenger: Y/N: " <<endl;
    cin>>input;
    }while(input!='Y'&input!='N');
if(input == 'Y'){
    passengerList.erase(passengerList.begin()+i);
}

  else{
      cout << "Cancelled"<<endl;
  }     

}

int Passengers:: findPass(int id){

    for(int i=0;i<passengerList.size();i++){
        if(passengerList.at(i).getID()==id){
            //cout << "  Your ID is in the system"<<endl;
            return 1;
	    break;
        }
           // cout << "Your ID is not in the system " <<endl;
    }
     //cout << "Your ID is not in the system " <<endl;
	return 0;
}

void Passengers:: findpass(){
int id;
cout << "Enter your ID : " <<endl;
cin>>id;
cin.ignore();
for(int i=0;i<passengerList.size();i++){
 if(passengerList.at(i).getID()==id){
cout << "Your ID is in the system " <<endl;
 return;
	}
} 
cout << "ID is not in the system "<<endl;//find pass based on id
}

void Passengers::PrintEntryList(){
for(int i=0;i<passengerList.size();i++){
cout<< passengerList.at(i).getName()<<endl;
cout<< passengerList.at(i).getID()<<endl;
cout<< passengerList.at(i).getPayment()<<endl;
cout<< passengerList.at(i).getHandicapped()<<endl;
cout<< passengerList.at(i).getRating()<<endl;
cout<< passengerList.at(i).getPets()<<endl;
    //passengerList[i].PrintInfoPass()<<endl;
    }
if(passengerList.size()==0){
    cout << "No passengers. "<<endl;
}
}




void Passengers:: PrintRidesPass(){
int id;
int i;
cout << "Enter your ID" <<endl;
cin>>id;
cin.ignore();
i = findPass(id);


cout <<passengerList.at(i).getID();
//passengerList.at(i).PrintInfoPass();
cout << "Passengers Printed" <<endl;
    if(passengerList.size()==0){
        cout << "NO Passenger."<<endl;
	return;
    }
}

void Passengers:: loadPassengers(){
   ifstream fin;
    string name;
    int id;
    string payment; //payment prefernce
    bool handicapped;
    float rating;
    bool pets;
    fin.open("passengersOutput.dat");
    if(fin.fail()){
        cout << "Unable to open the file." <<endl;
    }
   fin>>passcount;
   for(int i=0;i<passcount;i++){
   getline(cin,name);
   fin>>id;
   cin.ignore();
   getline(cin,payment);
   fin>>handicapped;
   cin.ignore();
   fin>>rating;
   cin.ignore();
   fin>>pets;
   cin.ignore();
   //Passenger(string name,int id,string payment,bool handicaaped,float rating,bool pets); //second contrucotr
   Passenger myPassenger(name,id,payment,handicapped,rating,pets);
  passengerList.push_back(myPassenger);
}
fin.close();
}

void Passengers:: storePassengers(){
    ofstream fout;
    fout.open("passengersOutput.dat");
    fout<<passengerList.size()<<endl;
    for(int i=0;i<passengerList.size();i++){
    fout << passengerList[i].getName()<<endl;
    fout<<passengerList[i].getID()<<endl;
    fout<<passengerList[i].getPayment()<<endl;
    fout<<passengerList[i].getHandicapped()<<endl;
    fout<<passengerList[i].getRating()<<endl;
    fout<<passengerList[i].getPets()<<endl;  
    }
    fout.close();
}