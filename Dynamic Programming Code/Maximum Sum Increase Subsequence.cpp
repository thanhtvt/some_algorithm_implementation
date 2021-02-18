#include <iostream>

using namespace std;

int maxSumIncreaseSubsequence(int element[], int n)
{
    int sum[n+1];
    for (int i = n; i >= 0; i--)
    {
        if (i == n)
        {
            sum[i] = element[i];
            continue;
        }
        int max = INT_MIN;
        for (int j = i + 1; j <= n; j++)
        {
            int tmp = sum[j];
            if (element[i] < element[j])
            {
                tmp += element[i];
                if (tmp > max) max = tmp;
            }
            if (max == INT_MIN) sum[i] = element[i];
            else sum[i] = max;
        }
    }
    return sum[0] + 1;
}

int main()
{
    int n;
    cin >> n;
    int element[n+1];
    element[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> element[i];
    }
    cout << maxSumIncreaseSubsequence(element, n);
}
