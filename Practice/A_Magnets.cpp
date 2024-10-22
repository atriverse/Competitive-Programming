#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int count = 1;
    string prev;
    cin>>prev;
    t-=1;
    while (t--)
    {
        string s;
        cin >> s;
        
        if (prev[0]!=s[0])
        {
            count++;
        }
        
        prev = s;
        
    }
    cout << count << endl;
    return 0;
}