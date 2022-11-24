

#ifndef DRIVERH
#define DRIVERH
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class Driver{
    private:
        int id;
        string name;
        int numOfPassenger; //capacity
        bool handiCapp;
	string type; //vehicel type
        float rating;
        bool pets;
        bool available;

    public:
    Driver();
    Driver(int id, string name, int numOfPassenger,bool handiCapp,string type, float rating,bool pets,bool available);
    void SetId(int userId){id=id;}  //mutator
    void SetName(string userName){name=name;}
    void SetPassenger(int thePassenger){numOfPassenger=numOfPassenger;}
    void SetHandicapp(bool thehandiCapp){handiCapp=handiCapp;}
    void SetType(string usertype){type=type;}
    void SetRating(float userRating){rating=rating;}
    void Setpets(bool userpets){pets =pets;}
    void Setavailable(bool useravailable){available=available;}

  
    int GetId(); //accessor
    string GetName();
    int GetPasseger();
    bool GetHandicapp();
    float GetRating();
    string GetType();
    bool GetAvailable();
    bool GetPets();

    

void PrintInfo();
    
};

#endif