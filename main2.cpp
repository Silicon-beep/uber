/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Driver{
    public:
    void SetRating(int userRating);
    void SetName(string userName);
    void SetCapacity(int userCapacity);
    void Print();
    
    private:
    string name;
    int capacity;
    bool acapability;
    bool allowed; //pet
    int rating;
    int days;
    
    
};
//set drivers's namevoid
void Driver::SetName(string userName){
    name = userName;
}
void Driver::SetRating(int userRating){
    rating = userRating;
}
void Driver::SetCapacity(int userCapacity){
    capacity = userCapacity;
}

void Driver::Print(){
    cout << name<< "----" <<rating<<"---"<<capacity <<endl;
}

int main()
{
    Driver p1;
    Driver p2;
    
    p1.SetName("Naomi");
    p1.SetRating(5);
    p1.SetCapacity(10);
    
    p2.SetName("Dave");
    p2.SetRating(4);
    p2.SetCapacity(5);
    
    cout << "Drivers info: " <<endl;
    p1.Print();
    p2.Print();
    

    return 0;
}
