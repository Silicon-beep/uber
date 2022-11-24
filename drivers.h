#ifndef DRIVERS_H
#define DRIVERS_H
#include "driver.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Drivers{
    
    public:
    
    Drivers() { drivcount = 0;}
    int getcount();

    void inccount();		//increment the counter +1
    void deccount();
    void addDrive();
   void editDrive();
  int findDrives(int id);
   void deleteDrive();
//find function
    void findDriver(); //driver based on id
    void clean(); //celan up the data

    void PrintEntries(); //list
     void PrintSingleDrive(); //details for a single entity



    void loadData();
    void storeData();
    vector<Driver>driverList;
    
    private:
    int drivcount;
};



#endif 