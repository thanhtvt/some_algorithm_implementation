#include <iostream>

using namespace std;

class Queue
{
private:
    int capacity;
    int length;
    int head, tail;
    int* element;
public:
    Queue(int s);
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    int getHead();
};

Queue::Queue(int s)
{
    capacity = s;
    length = 0;
    head = 0;
    tail = -1;
    element = new int[capacity];
}

bool Queue::isEmpty()
{
    return (length == 0) ? true : false;
}

void Queue::enqueue(int data)
{
    if(length < capacity)
    {
        tail = (tail + 1) % capacity;
        element[tail] = data;
        length++;
    }
    else
    {
        int* arr = new int[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = element[(head + i) % capacity];
        }
        arr[capacity] = data;
        delete[] element;
        element = arr;
        head = 0;
        tail = capacity;
        capacity *= 2;
    }
}

int Queue::dequeue()
{
    if (!isEmpty())
    {
        int res;
        res = element[head];
        if (length == 1)
        {
            head = 0;
            tail = -1;
        }
        else head = (head + 1) % capacity;
        length--;
        return res;
    }
}

int Queue::getHead()
{
    if (!isEmpty()) return element[head];
}

int main()
{
    Queue Q(10);
    int x;
    while (cin >> x)
    {
        Q.enqueue(x);
    }
    cout << Q.dequeue() << endl;
    cout << Q.getHead();
}
