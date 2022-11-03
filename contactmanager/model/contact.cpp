#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

class contact
{
    long contactNumber;
    char firstName[20], lastName[20];

public:
    void create_contact()
    {
        cout << "Phone: ";
        cin >> contactNumber;
        cout << "Name: ";
        cin.ignore();
        cin >> firstName;
        cout << "Address: ";
        cin.ignore();
        cin >> lastName;

        cout << "\n";
    }
};
}