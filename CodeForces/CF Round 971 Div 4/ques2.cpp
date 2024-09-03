#include <bits/stdc++.h>
using namespace std;

/**
 * Prints the column indices of the '#' characters in each row of the input vector of strings, in reverse order.
 *
 * @param n The number of strings in the input vector.
 * @param v The vector of strings to process.
 */
void f(int n, vector<string> &v)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (v[i][j] == '#')
            {
                cout<<(j + 1)<<" ";
            }
        }
    }
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n,"");
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        f(n, v);

    }
}

/*
Editorial:
Implement the statement. Iterate from n−1 to 0 and use the .find() method in std::string in C++ (or .index() in python) to find the '#' character.
*/