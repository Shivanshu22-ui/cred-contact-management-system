#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;

class contact
{
    long phoneNumber;
    string fname,lname;

    public :
    
    contact(string firstname,string lastname,long phoneNumber){
        fname=firstname;
        lname=lastname;
        this->phoneNumber=phoneNumber;
    }

    long getPhoneNumber(){
        return phoneNumber;
    }
    string getfname(){
        return fname;
    }
    string getlname(){
        return lname;
    }
};

fstream  fp;
contact cont;

void save_contact(){
    fp.open("contactBook.txt",ios::out|ios::app);
	// cont.create_contact();
	fp.write((char*)&cont,sizeof(contact));
	fp.close();
	cout<<endl<<endl<<"Contact Has Been Sucessfully Created...";
	getchar();
}