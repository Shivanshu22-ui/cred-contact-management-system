#include <iostream>
#include <stack>
using namespace std;

const int SIZE = 50;
 
struct TrieNode
{
    struct TrieNode *children[SIZE];
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

void insertName(struct TrieNode *root, string key)
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

void insertPhoneNumber(struct TrieNode *root, long key)
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
 
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
    long arr[] = {11122,12,111,1};
    struct TrieNode *phoneRoot = getNode();

    for(int i =0;i<4;i++){
        string number = LongToString(arr[i]);
        insertName(phoneRoot,number);
    }
    // Construct trie
    for (int i = 0; i < n; i++)
        insertName(root, keys[i]);
 
    // Search for different keys
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    for(int i=0;i< n ;i++){
        cout<<output[search(root,keys[i])];
    }
    // Search for different keys
    cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
    // cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
    // cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
    // cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;

    // cout<<"11---"<<output[search(phoneRoot,"1")];
    return 0;
}