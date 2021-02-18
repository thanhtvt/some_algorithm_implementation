// Minh họa: https://nguyenvanhieu.vn/thuat-toan-sap-xep-noi-bot/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int arr[], int n)
{
    bool haveSwap = false;
    for (int i = 0; i < n-1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                haveSwap = true;
            }
        }
        if (haveSwap == false) break;
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
    bubbleSort(a, n);
    printArray(a, n);
}
