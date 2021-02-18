// Visualize: https://www.youtube.com/watch?v=nu4gDuFabIM
// Visualize counting sort: https://www.youtube.com/watch?v=7zuGmKfUt7s
// Explain counting sort: https://www.youtube.com/watch?v=pEJiGC-ObQE 

#include <iostream>
#include <climits>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int maxElement(int a[], int n)
{
    int myMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (myMax < a[i]) myMax = a[i];
    }
    return myMax;
}

void countingSort(int a[], int n, int index)
{
    int output[n];
    int counter[10] = {0};
    for (int i = 0; i < n; i++)
    {
        counter[(a[i] / index) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];
    }

    // loop from biggest index to maintain the STABILITY of the algorithm
    for (int i = n - 1; i >= 0; i--)
    {
        output[ counter[(a[i] / index) % 10] - 1 ] = a[i];
        counter[(a[i] / index) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radixSort(int a[], int n)
{
	// To find the maximum digits an element can have
    int maxNumber = maxElement(a, n);
    for (int index = 1; maxNumber / index > 0; index *= 10)
    {
        countingSort(a, n, index);
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
    radixSort(a, n);
    printArray(a, n);
}
