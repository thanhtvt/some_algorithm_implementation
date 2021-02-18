#include <iostream>

using namespace std;

int coinChange(int coin[], int total, int n)
{
    int table[n+1][total+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            if (j == 0)
            {
                table[i][j] = 1;
                continue;
            }
            else if (i == 0)
            {
                table[i][j] = 0;
                continue;
            }
            if (coin[i] > j) table[i][j] = table[i-1][j];
            else table[i][j] = table[i-1][j] + table[i][j - coin[i]];

        }
    }
    return table[n][total];
}

int main()
{
    int n, total;
    cin >> n >> total;
    int coin[n+1];
    coin[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    cout << coinChange(coin, total, n);
}
