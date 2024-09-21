#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if (v[i]>=k)
            {
                sum+=v[i];
            }
            else if (v[i]==0 && sum>0)
            {
                ans+=1;
                sum-=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}