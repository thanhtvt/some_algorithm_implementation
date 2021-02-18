// Visualize: https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/visualize/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low, right = high - 1;
    while (left <= right)
    {
        if (a[left] < pivot) left++;
        else if (a[right] > pivot) right--;
        else
        {
            swap(a[right], a[left]);
            right--;
            left++;
        }
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        //Sort left side
        quickSort(a, low, pi - 1);
        //Sort right side
        quickSort(a, pi + 1, high);
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
    quickSort(a, 0, n - 1);
    printArray(a, n);
}
