// ILLUSTRATE TABLE BELOW

#include <iostream>

using namespace std;

bool subsetSum(int number[], int n, int sum)
{
    bool table[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                table[i][j] = true;
                continue;
            }
            else if (i == 0)
            {
                table[i][j] = false;
                continue;
            }
            if (number[i] > j) table[i][j] = table[i-1][j];
            else
            {
                if (table[i-1][j - number[i]] || table[i-1][j])
                {
                    table[i][j] = true;
                }
                else table[i][j] = false;
            }
        }
    }
    return table[n][sum];
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int number[n+1];
    number[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }
    bool answer = subsetSum(number, n, sum);
    if(answer) cout << "TRUE";
    else cout << "FALSE";
}

// ILLUSTRATE TABLE
/*

   | 0   1   2   3   4   5   6   7   8   9
0  | T   F   F   F   F   F   F   F   F   F
3  | T   F   F   T   F   F   F   F   F   F
34 | T   F   F   T   F   F   F   F   F   F
4  | T   F   F   T   T   F   F   T   F   F
12 | T   F   F   T   T   F   F   T   F   F
5  | T   F   F   T   T   T   F   T   T   T
2  | T   F   T   T   T   T   T   T   T   T

*/
