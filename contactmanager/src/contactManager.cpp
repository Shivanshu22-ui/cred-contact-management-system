#include "../service/contactManagerLibrary.h"


using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

const int SIZE = 50;

class contact
{
    string ph;
    string firstName, lastName;

public:
    void create_contact(string ph, string fname, string lname)
    {
        this->ph = ph;
        this->firstName = fname;
        this->lastName = lname;
    }
    void show_contact()
    {
        cout << endl
             << "Phone #: " << ph;
        cout << endl
             << "Name " << firstName << " " << lastName;
    }

    string getPhone()
    {
        return ph;
    }

    string getFirstName()
    {
        return firstName;
    }

    string getLastName()
    {
        return lastName;
    }
};


fstream fp;
contact cont;

void save_contact(TrieNode *root, string ph, string fname, string lname)
{
    fp.open("contactBook.txt", ios::out | ios::app);
    cout << "Creating Contadtc" << endl;
    cont.create_contact(ph, fname, lname);
    cout << "Created Contact" << ph << endl;
    cout << "Created Contact" << lname << endl;
    fp.write((char *)&cont, sizeof(contact));
    fp.close();
    cout << endl
         << endl
         << "Contact Has Been Sucessfully Created...";
    getchar();
}

void show_all_contacts()
{
    cout << "LIST OF CONTACTS" << endl;
    fp.open("contactBook.txt", ios::in);
    while (fp.read((char *)&cont, sizeof(contact)))
    {
        cont.show_contact();
        cout << endl
             << "=================================================\n"
             << endl;
    }
    fp.close();
}



void display_contact(string typeOfSearch, string searchField, string searchValue)
{
    bool found = false;
    int ch;

    fp.open("contactBook.txt", ios::in);
    while (fp.read((char *)&cont, sizeof(contact)))
    {

        if (typeOfSearch == "Partial")
        {
            cont.show_contact();
        }
        else
        {
            if (searchField == "Phone")
            {
                if (cont.getPhone() == searchValue)
                {
                    cont.show_contact();
                }
                {
                    cont.show_contact();
                    found = true;
                }
            }
            else if (searchField == "FName")
            {
                if (cont.getFirstName() == searchValue)
                {
                    cont.show_contact();
                    found = true;
                }
            }
            else
            {
                if (cont.getLastName() == searchValue)
                {
                    cont.show_contact();
                    found = true;
                }
            }
        }
    }
    fp.close();
    if (found == false)
    {
        cout << "\n\nNo Contact found";
    }
    getchar();
}

int main(int argc, char *argv[])
{
    for (;;)
    {
        int ch;
        cout << "\n\t **** Welcome to Contact Management System ****";
        cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
        cout << "Enter the choice:";
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\n\n\t\tThank you for using our Library";
            break;

        case 1:
        {
            string ph;
            string fname, lname;
            cout << "Phone: ";
            cin >> ph;
            cout << "First Name: ";
            cin.ignore();
            cin >> fname;
            cout << "Last Name: ";
            cin.ignore();
            cin >> lname;
            save_contact(, ph, fname, lname);
            break;
        }

        case 2:
            show_all_contacts();
            break;
        case 3:
        {
            string searchField, typeOfSearch, searchValue;
            cout << "\n\n\tSearch Input ";
            cin >> searchValue;
            display_contact(typeOfSearch, searchField, searchValue);
            break;
        }

        default:
            break;
        }

        int opt;
        cout << "\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            continue;

        case 0:
            break;
        }
    }
    return 0;
}
