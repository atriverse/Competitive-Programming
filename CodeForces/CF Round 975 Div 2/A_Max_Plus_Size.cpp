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
        int n;
        cin>>n;
        vector<int> v(n);
        int maxi_o=0;
        int maxi_e=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if (v[i]>=maxi_o && i%2==0)
            {
                maxi_o=max(maxi_o,v[i]);
            }
            if (v[i]>=maxi_e && i%2!=0)
            {
                maxi_e=max(maxi_e,v[i]);
            }
        }
        cout<<max(maxi_o+(n+1)/2,maxi_e+n/2)<<endl;
    }

    return 0;
}