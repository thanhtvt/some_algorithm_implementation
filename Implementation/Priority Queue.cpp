#include <iostream>

using namespace std;

// Size of queue
int n;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void insert(int a[], int value)
{
    int i = n;
    n++;
    a[i] = value;
    if (n == 1) return;

    // a[i] is the child node of a[(i-1)/2] (parent node)
    // if visualizing in a form of binary tree
    while (i >= 1 && a[i] < a[(i - 1) / 2])
    {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void reOrder(int a[], int i)
{
    // a[2*i+1] & a[2*i+2] are children of a[i]
    // if visualizing in a form of binary tree
    if (2 * i + 1 < n && a[i] > a[2 * i + 1])
    {
        swap(a[i], a[2 * i + 1]);
        reOrder(a, 2 * i + 1);
    }
    else if (2 * i + 2 < n && a[i] > a[2 * i + 2])
    {
        swap(a[i], a[2 * i + 2]);
        reOrder(a, 2 * i + 2);
    }
    else return;
}

void deleteMinElement(int a[])
{
    if (n == 0)
    {
        cout << "Queue is currently empty" << endl;
        return;
    }
    else
    {
        a[0] = a[n - 1];
        n--;
        reOrder(a, 0);
    }
}

void printInOrder(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int getSmallestElement(int a[])
{
    return a[0];
}

int main()
{
    n = 0;
    int val, a[100];
    while (cin >> val)
    {
        insert(a, val);
    }
    cout << getSmallestElement(a) << endl;
    printInOrder(a);
    deleteMinElement(a);
    printInOrder(a);
}
