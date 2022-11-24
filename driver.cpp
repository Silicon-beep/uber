#include "driver.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//  Define default constructor
Driver::Driver() {
   id = 0;
   name = "NO Name";
   numOfPassenger = 0;
   handiCapp = " ";
   rating = 0;
   type = "";
   pets = true;
   available=true;
}
Driver::Driver(int id, string name, int numOfPassenger,bool handiCapp,string type, float rating,bool pets,bool available) {
   this->id= id;
   this->name = name;
   this->numOfPassenger = numOfPassenger;
   this->handiCapp = handiCapp;
   this->rating = rating;
   this->pets=pets;
   this->type = type;
   this->available=available;
}
int Driver :: GetId(){
    return id;
}
string Driver :: GetName() {
    return name;
}
int Driver:: GetPasseger(){
    return numOfPassenger;
}

bool Driver:: GetHandicapp(){
        return handiCapp;
}
float Driver :: GetRating(){
    return rating;
}

string Driver:: GetType(){
return type;
}

bool Driver::  GetAvailable(){
return available;
}

bool Driver:: GetPets(){
return pets;
}


void Driver :: PrintInfo(){ //print method
    cout << "ID :" <<id <<endl;
    cout << "Name :" <<name<<endl;
    cout << "Vehicle capacity: " << numOfPassenger <<endl;
    cout << "Handicapped Capable: " << handiCapp<<endl;
    cout << "Vehicle Type: " <<type<<endl;
    cout << "The rating :" <<fixed<<setprecision(2)<<rating <<endl;
    cout << "Pets allowed :" << pets <<endl;
    cout << "Avalability:" << available<<endl;
}