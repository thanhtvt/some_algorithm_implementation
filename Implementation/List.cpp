#include <iostream>

using namespace std;

const int MAX_LENGTH = 5;

class List
{
private:
    int length;
    int arr[MAX_LENGTH];
public:
    // Constructor
    List()
    {
        length = 0;
    }
    int getLength();
    void deleteElement(int key);
    void insertElement(int val);
    bool searchElement(int key);
    bool isFull();
    void display();
};

bool List::isFull()
{
    return (length == MAX_LENGTH) ? true : false;
}

int List::getLength()
{
    return length;
}

void List::insertElement(int val)
{
    if (!isFull())
    {
        arr[length] = val;
        length++;
    }
    else cout << "Overflow";
}

void List::deleteElement(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            for (int j = i; j < length - 1; j++)
            {
                arr[j] = arr[j+1];
            }
            arr[length - 1] = '\0';
            length--;
            return;
        }
    }
}

void List::display()
{
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool List::searchElement(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key) return true;
    }
    return false;
}

int main()
{
    int x;
    List L;
    while (cin >> x)
    {
        L.insertElement(x);
    }
    cout << L.getLength() << endl;
    L.display();
    L.deleteElement(2);
    if (L.searchElement(3)) cout << "FOUND" << endl;
    else cout << "NOT FOUND" << endl;
    L.display();
}
