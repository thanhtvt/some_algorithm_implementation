#include <iostream>
#include <cstring>

using namespace std;

int findMin(int a, int b, int c)
{
    return min(min(a, b), c);
}

int editDist(string s1, string s2, int len1, int len2)
{
    int table[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
            {
                table[i][j] = j;
                continue;
            }
            else if (j == 0)
            {
                table[i][j] = i;
                continue;
            }
            if (s1[i-1] == s2[j-1]) table[i][j] = table[i-1][j-1];
            else
            {
                table[i][j] = 1 + findMin(table[i][j-1], table[i-1][j-1], table[i-1][j]);
                                    //    Insert         Replace          Remove
            }
        }
    }
    return table[len1][len2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << editDist(s1, s2, s1.length(), s2.length());
}
