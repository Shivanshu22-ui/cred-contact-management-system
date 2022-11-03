#include <fstream>
#include <string.h>
#include <iostream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

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

const int SIZE = 50;

struct TrieNode
{
    struct TrieNode *children[SIZE];
    string firstName;
    string lastName;
    string phoneNumber;
    bool isEnd;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEnd = false;

    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insertName(struct TrieNode *root, string key, string phone)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEnd = true;
    pCrawl->phoneNumber = phone;
    pCrawl->firstName = "";
    pCrawl->lastName = "";
}

string LongToString(long long_num)
{
    stack<char> stringStack;
    string signValue = "";
    if (long_num < 0)
    {
        signValue = "-";
        long_num = -long_num;
    }

    while (long_num > 0)
    {
        char convertedDigit = long_num % 10 + '0';
        stringStack.push(convertedDigit);
        long_num /= 10;
    }

    string long_to_string = "";

    while (!stringStack.empty())
    {
        long_to_string += stringStack.top();
        stringStack.pop();
    }

    return signValue + long_to_string;
}

void insertPhoneNumber(struct TrieNode *root, string key, string fname, string lname)
{
    struct TrieNode *pCrawl = root;
    // string phoneNumber= LongToString(key);

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEnd = true;
    pCrawl->firstName = fname;
    pCrawl->lastName = lname;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEnd);
}
TrieNode *search1(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    string arr[100];

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return NULL;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl);
}

bool isLeafNode(struct TrieNode *root)
{
    return root->isEnd != false;
}

void display(struct TrieNode *root, char str[], int level)
{
    if (isLeafNode(root))
    {
        str[level] = '\0';
        cout << str << root->phoneNumber << endl;
    }

    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

fstream fp;
contact cont;

void save_contact(string ph, string fname, string lname)
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
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = getNode();
    struct TrieNode *root1 = getNode();
    long arr[] = {11122, 12, 111, 1};
    struct TrieNode *phoneRoot = getNode();

    string name[] = {"hello", "hi", "apple", "app"};
    long ph[] = {12313, 1321, 32, 135156};

    for (int i = 0; i < 4; i++)
    {
        string number = LongToString(ph[i]);
        insertPhoneNumber(root1, LongToString(ph[i]), name[i], "");
    }
    char output[][32] = {"Not present in trie", "Present in trie"};

    int level = 0;
    char str[20];
    cout << "Content of Trie: " << endl;
    display(root1, str, level);
    cout << search1(root1, "32")->firstName << "  done" << endl;

    return 0;
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
            save_contact(ph, fname, lname);
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
