#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
 
class contact
{
	long ph;
	char firstName[20],lastName[20];

	public:

	void create_contact()
	{
		cout<<"Phone: ";
		cin>>ph;
		cout<<"Name: ";
		cin.ignore();
		cin>>firstName;
		cout<<"Last: ";
		cin.ignore();
		cin>>lastName; 
		cout<<"\n";
	}
    void create_contact(long ph,char fname[],char lname[]){
        this->ph=ph;
        this->firstName[20]=fname[20];
        this->lastName[20]=lname[20];
    }

	void show_contact()
	{
		cout<<endl<<"Phone #: "<<ph;
		cout<<endl<<"Name: "<<firstName <<" "<<lastName;
		cout<<endl<<"Address: "<<lastName;
	}

	long getPhone()
	{
		return ph;
	}

	char* getFirstName()
	{
		return firstName;
	}

	char* getLastName()
	{
		return lastName;
	}
};

fstream fp;
contact cont;

void save_contact()
{
	fp.open("contactBook.txt",ios::out|ios::app);
	cont.create_contact();
	fp.write((char*)&cont,sizeof(contact));
	fp.close();
	cout<<endl<<endl<<"Contact Has Been Sucessfully Created...";
	getchar();
}

void show_all_contacts()
{
	cout<<"LIST OF CONTACTS"<<endl;
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		cont.show_contact();
		cout<<endl<<"=================================================\n"<<endl;
	}
	fp.close();
}

void display_contact(char typeOfSearch[], char searchField[], char searchValue[])
{
	bool found=false;
	int ch;
    
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{

        if(strcmpi(typeOfSearch,"Partial")==0)
        {
            cont.show_contact();
        }
        else{
            if(strcmpi(searchField,"Phone")==0){
                
            }
            else if(strcmpi(searchField,"FName")==0){

            }
            else{
                		// if(cont.getPhone()==num)
		// {
		// cont.show_contact();
		// found=true;
		// }
            }
        }
	}
	fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";}
	getchar();
}
  

  

  
int main(int argc, char *argv[])
{
	for(;;)
	{	
		int ch;
		cout<<"\n\t **** Welcome to Contact Management System ****";
		cout<<"\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
		cout<<"Enter the choice:"; 
		cin>>ch;
 
		switch(ch)
		{
			case 0: cout<<"\n\n\t\tThank you for using CMS...";
				break;

			case 1:save_contact();
				break;

			case 2:show_all_contacts();
				break;
			case 3:
				char searchField[20], typeOfSearch[20], searchValue[20];
				cout<<"\n\n\tSearch Input ";
				cin>>searchValue;
				display_contact(typeOfSearch, searchField, searchValue);
				break;
			default:
				break;
		}
 
		int opt;
		cout<<"\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";
		cin>>opt;
 
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