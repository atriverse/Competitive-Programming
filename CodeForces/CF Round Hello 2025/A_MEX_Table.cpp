#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int m,n;
        cin >> m >>n;
        cout<<max(m,n)+1<<endl;
    }

    return 0;
}