#include <iostream>

using namespace std;

int longestIncreasingSubsequence(int element[], int n)
{
    int length[n+2];
    for (int i = n + 1; i >= 0; i--)
    {
        if (i == n + 1)
        {
            length[i] = 1;
            continue;
        }
        int max = INT_MIN;
        for (int j = i + 1; j <= n + 1; j++)
        {
            if (element[i] < element[j])
            {
                length[i] = length[j] + 1;
                if (length[i] > max) max = length[i];
            }
        }
        if (max == INT_MIN) length[i] = 1;
        else length[i] = max;
    }
    return length[0] - 2;
}

int main()
{
    int n;
    cin >> n;
    int element[n+2];
    element[0] = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        cin >> element[i];
    }
    element[n+1] = INT_MAX;
    cout << longestIncreasingSubsequence(element, n);
}
