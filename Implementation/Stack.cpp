#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int capacity;
    int* element;
public:
    Stack(int s);
    void push(int val);
    int pop();
    int getTop();
    int getSize();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int s)
{
    capacity = s;
    top = -1;
    element = new int[capacity];
}

bool Stack::isFull()
{
    if(top == capacity - 1) return true;
    else return false;
}

void Stack::push(int val)
{
    if (!isFull())
    {
        top++;
        element[top] = val;
    }
    else
    {
        int* arr = new int[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = element[i];
        }
        arr[capacity] = val;
        delete[] element;
        element = arr;
        top = capacity;
        capacity *= 2;
    }
}

int Stack::pop()
{
    if (!isEmpty())
    {
        int data = element[top];
        element[top] = '\0';
        top--;
        return data;
    }
}

int Stack::getTop()
{
    return element[top];
}

int Stack::getSize()
{
    return top + 1;
}

bool Stack::isEmpty()
{
    return (top == -1) ? true : false;
}

int main()
{
    Stack s(10);
    int x;
    while (cin >> x)
    {
        s.push(x);
    }
    cout << s.pop() << endl;
    s.push(20);
    cout << s.getTop() << endl;
    cout << s.getSize() << endl;
    if(!s.isEmpty()) cout << "NOT EMPTY";
}
