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
        cin >> n;
        vector<int> a(n+1);
        a[0] = 0;
        int maxi=0;
        for (int i = 1; i < n+1; i++)
        {
            cin >> a[i];
            if (a[i] > maxi)    
            {
                maxi = a[i];
            }
        }
        sort(a.begin(), a.end());
        a[0]=maxi;
        int mini=INT_MAX;
        int sum=0;
        for (int i = 1; i < n; i++){
            if (a[i]<mini)
            {
                mini=a[i];
            }
            sum+=(maxi-mini);
        }
        cout<<sum<<endl;
    }

    return 0;
}