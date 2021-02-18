// Minh họa: https://nguyenvanhieu.vn/thuat-toan-sap-xep-chon/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int myMin = INT_MAX, index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j] && myMin > a[j])
            {
                myMin = a[j];
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    printArray(a, n);
}
