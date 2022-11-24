#ifndef RIDES_H
#define RIDES_H
#include "drivers.h"
#include "passengers.h"
#include "ride.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Rides{
    
    public:
    
    //Rides();
    
    void inccount();
    void deccount();
    
    void AddRide(Drivers &Drive, Passengers &Pass);
    void editRide();
    void Delete(); //deletes the Rides
    void findRide();
    int SearchID(int id); //find ride based based on ID
    void printList();//prints the list of all ride entrie
    void printDetails(); //drtails for a singe  ride
    void printListRidesPasse(); // list of rides in a particular passenger
    void printListRidesDriver(); //particulardriver

    void updateRides(); //updateRides
    void cancelRides(); //delete cancelled rides
    
    void printStatus(); //print status
    
    vector<Ride>rideList;
    
    void loadRide();
    void storeRide();
    
    private: 
int ridecount;
};


#endif