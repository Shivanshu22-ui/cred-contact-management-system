#include <fstream>
#include <string.h>
#include <iostream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;
    const int SIZE = 50;
    struct TrieNode
    {
        struct TrieNode *children[SIZE];
        string name;
        long phoneNumber;
        bool isEnd;
    };
    
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
    
        pNode->isEnd = false;
    
        for (int i = 0; i < SIZE; i++)
            pNode->children[i] = NULL;
    
        return pNode;
    }


    void insertName(struct TrieNode *root, string key,long phone)
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
        pCrawl->phoneNumber=phone;
        pCrawl->name="";
    }

    string LongToString(long long_num)
    {
        stack<char> stringStack;
        string signValue = "";
        if (long_num < 0) {
            signValue = "-";
            long_num = -long_num;
        }
    
        while (long_num > 0) {
            char convertedDigit = long_num % 10 + '0';
            stringStack.push(convertedDigit);
            long_num /= 10;
        }
    
        string long_to_string = "";
    
        while (!stringStack.empty()) {
            long_to_string += stringStack.top();
            stringStack.pop();
        }
    
        return signValue + long_to_string;
    }

    void insertPhoneNumber(struct TrieNode *root, long key,string fname,string lname)
    {
        struct TrieNode *pCrawl = root;
        string phoneNumber= LongToString(key);
    
        for (int i = 0; i < phoneNumber.length(); i++)
        {
            int index = phoneNumber[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
    
            pCrawl = pCrawl->children[index];
        }
    
        pCrawl->isEnd = true;
        pCrawl->name=fname+lname;
        // pCrawl->phoneNumber=NULL;
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
    
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return NULL;
    
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl);
    }
    
    bool isLeafNode(struct TrieNode* root)
    {
        return root->isEnd != false;
    }
    
    void display(struct TrieNode* root, char str[], int level)
    {
        if (isLeafNode(root)) 
        {
            str[level] = '\0';
            cout << str << root->phoneNumber<< endl;
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
    void partialSearch(struct TrieNode *root, string currPrefix)
    {
        if (root->isEnd)
            cout << currPrefix << endl;

        for (int i = 0; i < SIZE; i++)
            if (root->children[i])
            {
                char child = 'a' + i;
                partialSearch(root->children[i],
                            currPrefix + child);
            }
    }

    bool isLastNode(struct TrieNode *root)
    {
        for (int i = 0; i < SIZE; i++)
            if (root->children[i])
                return 0;
        return 1;
    }

    int printPartialSearch(TrieNode *root, const string query)
    {
        struct TrieNode *pCrawl = root;
        for (char c : query)
        {
            int ind = CHAR_TO_INDEX(c);

            if (!pCrawl->children[ind])
                return 0;

            pCrawl = pCrawl->children[ind];
        }

        if (isLastNode(pCrawl))
        {
            cout << query << endl;
            return -1;
        }
        partialSearch(pCrawl, query);
        return 1;
    }

