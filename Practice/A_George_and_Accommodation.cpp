#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        int p,q;
        cin >> p >> q;
        if(q-p>=2){
            count++;
        }
    }
    cout << count;

    return 0;
}