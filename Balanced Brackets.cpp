#include <iostream>
#include <stack>

using namespace std;

bool isValid(string expr)
{
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        // IF the current character is not opening
        // bracket, then it must be closing. So
        // stack cannot be empty at this point.
        if (s.empty()) return false;

        switch (expr[i])
        {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x == '[') return false;
                break;

            case '}':
                x = s.top();
                s.pop();
                if (x == '(' || x == '[') return false;
                break;

            case ']':
                x = s.top();
                s.pop();
                if (x == '(' || x == '{') return false;
                break;
        }
    }
    return s.empty();
}

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (isValid(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
