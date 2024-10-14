#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

// to convert char to string

// string (size_t n, char c)
// eg - string(1, s[i])
#define int  long long int
#define endl "\n"


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t --)
    {
        string s, t;
        cin >> s >> t;


        int n = s.size(), m = t.size();

        int i = 0, j = 0;

        while (i != n || j != m)
        {
            if (s[i] == t[j])
            {
                i ++;
                j ++;
            }

            else
            {
                break;
            }
        }

        int ans = i + (n - i) + (m - j);

        if (i != 0)
        {
            ans ++;
        }

        cout << ans << endl;
    }
}


