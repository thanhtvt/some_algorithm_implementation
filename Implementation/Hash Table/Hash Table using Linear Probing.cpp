#include <iostream>
#include <list>

using namespace std;

class Hash
{
private:
    int element;  // No. of elements

    list<int>* hashTable;

public:
    // Constructor
    Hash(int V);

    int hashFunction(int x)
    {
        return x % element;
    }

    // Insert a key into hash table
    void insertElement(int x);

    // Delete a key from hash table
    void deleteElement(int key);

    // Search a key in hash table
    bool searchElement(int key);

    void displayHash();
};

Hash::Hash(int V)
{
    element = V;
    hashTable = new list<int>[element];
}

void Hash::insertElement(int x)
{
    int index = hashFunction(x);
    while(hashTable[index].size() != 0)
    {
        index = (index + 1) % element;
    }
    hashTable[index].push_back(x);
}

void Hash::deleteElement(int key)
{
    int index = hashFunction(key);
    int counter = 0;
    while(*( hashTable[index].begin() ) != key && counter < element)
    {
        index = (index + 1) % element;
        counter++;
    }
    if (counter < element)
    {
        list<int>::iterator itr = hashTable[index].begin();
        hashTable[index].erase(itr);
    }
    else cout << "Cannot find " << key << " in this table" << endl;
}

bool Hash::searchElement(int key)
{
    int index = hashFunction(key);
    int counter = 0;
    while(*( hashTable[index].begin() ) != key && counter < element)
    {
        index = (index + 1) % element;
        counter++;
    }
    if (counter < element) return true;
    else return false;
}

void Hash::displayHash()
{
    for (int i = 0; i < element; i++)
    {
        cout << i;
        list<int>::iterator itr;
        for (itr = hashTable[i].begin(); itr != hashTable[i].end(); itr++)
        {
            cout << " ---> " << *itr;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    Hash h(7);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        h.insertElement(a[i]);
    }
    h.insertElement(21);
    h.displayHash();
    if (h.searchElement(20)) cout << "FOUND HIM!!" << endl;
    else cout << "NOT THING IN HERE!!" << endl;
    h.deleteElement(20);
    h.displayHash();
}
