#include <iostream>
#include <stack>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
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
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEnd = false;
 
    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insertName(struct TrieNode *root, string key,string phone)
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
    pCrawl->firstName="";
    pCrawl->lastName="";
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

void insertPhoneNumber(struct TrieNode *root, string key,string fname,string lname)
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
    pCrawl->firstName=fname;
    pCrawl->lastName=lname;
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
 
 bool isLeafNode(struct TrieNode* root)
{
    return root->isEnd != false;
}

bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
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


void partialSearch(struct TrieNode* root,
                    string currPrefix)
{
    if (root->isEnd)
        cout << currPrefix << endl;
 
    for (int i = 0; i < SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            partialSearch(root->children[i],
                           currPrefix + child);
        }
}
 
int printPartialSearch(TrieNode* root, const string query)
{
    struct TrieNode* pCrawl = root;
    for (char c : query) {
        int ind = CHAR_TO_INDEX(c);
 
        if (!pCrawl->children[ind])
            return 0;
 
        pCrawl = pCrawl->children[ind];
    }

    if (isLastNode(pCrawl)) {
        cout << query << endl;
        return -1;
    }
    partialSearch(pCrawl, query);
    return 1;
}

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
    struct TrieNode *root1 = getNode();
    long arr[] = {11122,12,111,1};
    struct TrieNode *phoneRoot = getNode();

    // pair<string,int> data;
    string name[] = {"hello","hi","apple","app","helll"};
    long ph[]={12313,1321,32,135156,445};


    // for(int i =0;i<4;i++){
    //     string number = LongToString(ph[i]);
    //     insertName(root1,name[i],ph[i]);
    // }
    for(int i =0;i<4;i++){
        string number = LongToString(ph[i]);
        insertPhoneNumber(root1, LongToString(ph[i]),name[i],"");
    }
    struct TrieNode* root2 = getNode();
    insertName(root2, "hello","");
    insertName(root2, "dog","");
    insertName(root2, "hell","");
    insertName(root2, "cat","");
    insertName(root2, "a","");
    insertName(root2, "hel","");
    insertName(root2, "help","");
    insertName(root2, "helps","");
    insertName(root2, "helping","");
    int comp = printPartialSearch(root2, "hel");
    if (comp == -1)
        cout << "No other strings found with this prefix\n";
 
    else if (comp == 0)
        cout << "No string found with this prefix\n";



    char output[][32] = {"Not present in trie", "Present in trie"};
 
    int level = 0;
    char str[20];
  
    // Displaying content of Trie
    cout << "Content of Trie: " << endl;
    display(root1, str, level);
    cout<<search1(root1,"32")->firstName<<"  done"<<endl;
    // Search for different keys
    // cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
    // cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
    // cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;

    // cout<<"11---"<<output[search(phoneRoot,"1")];
    return 0;
}