// ILLUSTRATE TABLE BELOW

#include <iostream>

using namespace std;

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int minimumCoins(int coin[], int total, int n)
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
            else if (coin[i] == j) table[i][j] = table[i][j - coin[i]];
            else
            {
                if (table[i-1][j] != 0 && table[i][j - coin[i]] != 0)
                {
                    table[i][j] = min(table[i-1][j], table[i][0] + table[i][j - coin[i]]);
                }
                else if (table[i][j - coin[i]] != 0)
                {
                    table[i][j] = table[i][0] + table[i][j - coin[i]];
                }
                else table[i][j] = table[i-1][j];
            }
        }
    }
    return ( table[n][total] != 0 ) ? table[n][total] : -1;
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
    cout << minimumCoins(coin, total, n);
}

// ILLUSTRATE TABLE

/*

  |	0	1	2	3	4	5	6	7	8	9	10	11	12
0 |	1	0	0	0	0	0	0	0	0	0	0	0	0
9 |	1	0	0	0	0	0	0	0	0	1	0	0	0
6 |	1	0	0	0	0	0	1	0	0	1	0	0	2
5 |	1	0	0	0	0	1	1	0	0	1	2	2	2
1 |	1	1	2	3	4	1	1	2	3	1	2	2	2
2 |	1	1	1	2	2	1	1	2	2	1	2	2	2

*/