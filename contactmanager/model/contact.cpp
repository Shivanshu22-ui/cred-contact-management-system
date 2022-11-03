#include <iostream>
using namespace std;

class contact {
    long contactNo;
    char fname[20],lname[20];

    public:
    contact(char firstname, char lastname,long contactNo){
        this->contactNo=contactNo;
        fname=firstname;
        lname=lname;
    }
};