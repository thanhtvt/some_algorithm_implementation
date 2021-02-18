// Visualize: https://www.youtube.com/watch?v=JSceec-wEyw

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of l[], if there are any
    while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }

    // Copy the remaining elements of r[], if there are any
    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
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
    mergeSort(a, 0, n - 1);
    printArray(a, n);
}
