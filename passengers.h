#ifndef PASSENGERS_H
#define PASSENGERS_H
#include "passenger.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Passengers{
    
    public:
    
    int  getCount();
    void inCount();
    void decCount();
    
    void addPass();
    void editPass();
    void deletePass();
    int findPass(int id); //find pass based on id
    void findpass(); //find pass based on id
    void PrintEntryList(); //print all passengers
    //void PrintDetails();  //prints the detailes for a single entity
    void PrintRidesPass();//list of rides for a particular passenger
    //it also gets a passenger based on ID

    void loadPassengers();
    void storePassengers();
    vector<Passenger>passengerList;
   
    private:
    int passcount; 

};
#endif