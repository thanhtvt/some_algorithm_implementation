// Minh họa: https://nguyenvanhieu.vn/thuat-toan-sap-xep-chen/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
            j--;
        }
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
    insertionSort(a, n);
    printArray(a, n);
}
