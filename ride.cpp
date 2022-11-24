
#include "ride.h"
#include "rides.h"
#include "driver.h"
#include "drivers.h"
#include "passenger.h"
#include "passengers.h"
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Ride::Ride(){
    id = 0;
    pickup = "";
    pickupTime = time(0);
    dropoff = "";
    size =0;
    pets = true;
    dropoffTime = time(0);
    status =' ';
    rating = 0;

}
Ride::Ride(int id,string pickup,time_t pickupTime,string dropoff,int size,bool pets,time_t dropoffTime,char status,float rating){
    this->id = id;
    this->pickup = pickup;
    this->pickupTime = pickupTime;
    this->dropoff;
    this->size = size;
    this->pets =pets;
    this->dropoffTime=dropoffTime;
    this->status =status;
    this->rating = rating;
}
int Ride :: getID(){
        return id;
    }
string Ride:: getPickup(){
        return pickup;
    }
time_t Ride :: getPickupTime(){
        return pickupTime;
    }
string Ride:: getDropOff(){
        return dropoff;
    }
int Ride :: getSize(){
        return size;
        
}
bool Ride :: getPets(){
        return pets;
    }
time_t Ride:: getDropoffTime(){
        return dropoffTime;
    }
char Ride:: getStatus(){
        return status;
    }
float Ride:: getRating(){
        return rating;
    }
    

    

void Ride :: PrintInfoRide(){
    cout << "Enter Ride ID: "<<id <<endl;
    cout << "Pickup Location: " << pickup<<endl;
    cout << "Pickup Time: " <<ctime(&pickupTime)<<endl;
    cout << "Drop-off location: " << dropoff<<endl;
    cout <<" Size of party :" <<size<<endl;//must include for loop
    cout << "Includes Pets: " ;
    if(pets == false){
        cout << "No pets" <<endl;
    }
    else if(pets == true){
        cout << "Pets are allowed:" <<endl;
    } 
    cout << "Drop off Time:" << ctime(&dropoffTime)<<endl;
    cout << "Status:" << status<<endl;
    if (status == 'A'){
        cout <<"Active"<<endl;
        }
    else if (status == 'C'){
        cout << "Completed" <<endl;
    }
    else if (status =='D'){
        cout << "Cancelled" <<endl;
    }
    cout <<"Rating by Customer:"<<rating <<endl;
    }
