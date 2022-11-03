#include<fstream>
#include<string.h>
#include<iostream>

using namespace std;

class search
{
    char firstName[20],[20],email[30];
    long ph;

public:
    void searchFunc(char typeOfSearch[], char searchValue[], char searchField[]){
        if(typeOfSearch[0] == 'p' || typeOfSearch[0] == 'P'){
            if(searchField[0] == 'l' || searchField[0] == 'L'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getName())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField[0] == 'f' || searchField[0] == 'F'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getAddress())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField == '3'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getEmail())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField == '4'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getPhone())==0)
                    {
                        show_contact();
                    }
                }
            }
        }
            if(searchField == 'firstName'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getName())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField == '2'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getAddress())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField == '3'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getEmail())==0)
                    {
                        show_contact();
                    }
                }
            }
            else if(searchField == '4'){
                while(fp.read((char*)this,sizeof(contact)))
                {
                    if(strcmpi(searchValue,getPhone())==0)
                    {
                        show_contact();
                    }
                }
            }
        
    };    

        
        // void search_contact()
        // {
        //     char n[20];
        //     int flag=0;
        //     cout<<"Enter name to search: ";
        //     cin.ignore();
        //     cin>>n;
        //     fp.open("contact.txt",ios::in);
        //     while(fp)
        //     {
        //         fp>>name>>ph>>add>>email;
        //         if(strcmp(name,n)==0)
        //         {
        //             cout<<"Phone #: "<<ph<<endl;
        //             cout<<"Name: "<<name<<endl;
        //             cout<<"Address: "<<add<<endl;
        //             cout<<"Email Address : "<<email<<endl;
        //             flag=1;
        //         }
        //     }
        //     fp.close();
        //     if(flag==0)
        //         cout<<"Contact not found";
        // }
    };

int main()
{
    search s;
    s.search_contact();
    return 0;
}