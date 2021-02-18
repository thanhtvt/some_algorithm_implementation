#include <iostream>
#include <cstring>

using namespace std;

string longestCommon(string s1, string s2)
{
    int maxLength = 0;
    char* common = new char;
    int rows, cols;
    int len1 = s1.length(), len2 = s2.length();
    int commonTable[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0) commonTable[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
            {
                commonTable[i][j] = commonTable[i - 1][j - 1] + 1;
                if (commonTable[i][j] > maxLength)
                {
                    maxLength = commonTable[i][j];
                    rows = i;
                    cols = j;
                }
            }
            else commonTable[i][j] = 0;
        }
    }
    if (maxLength > 0)
    {
        common[maxLength] = '\0';
        while (commonTable[rows][cols] != 0)
        {
            common[maxLength - 1] = s1[rows - 1];
            rows--;
            cols--;
            maxLength--;
        }
    }
    return common;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string common = longestCommon(s1, s2);
    cout << common;
}
