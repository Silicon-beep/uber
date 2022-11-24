#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
using namespace std;

class Passenger{
    
    
    public:
    Passenger(); // default contruictor
    Passenger(string name,int id,string payment,bool handicaaped,float rating,bool pets); //second contrucotr
    
    //mutator
    void setName(string name){name =name;}
    void setID(int id){id =id;}
    void setPayment(string payment){payment=payment;}
    void setHandicapped(bool handicapped){handicapped=handicapped;}
    void setRating(float rating){rating=rating;}
    void setPets(bool pets){pets=pets;}

    //accessors
    string getName();
    int getID();
    string getPayment();
    bool getHandicapped();
    float getRating();
    bool getPets();
    


    void PrintInfoPass();
    
    private:
    string name;
    int id;
    string payment;
    bool handicapped;
    float rating;
    bool pets;
    
    
    
};

#endif
