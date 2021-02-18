#include<iostream>
#include<climits>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int cutRod(int price[], int n)
{
    int table[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
                continue;
            }
            if (i > j)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                table[i][j] = max(table[i-1][j], price[i] + table[i][j - i]);
            }
        }
    }
    return table[n][n];
}

int main()
{
    int n;
    cin >> n;
    int price[n+1];
    price[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    cout << cutRod(price, n);
    return 0;
}
