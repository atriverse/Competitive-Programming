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
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        int ans = 0;
        if(a <= m && b <= m) {
            ans = a + b + min(2*m-a-b, c);
        } else if(a > m && b <= m) {
            ans = m + b + min(m-b, c);
        } else if(a <= m && b > m) {
            ans = a + m + min(m-a, c);
        } else {
            ans = 2*m;
        }
        cout << ans << "\n";
    }

    return 0;
}