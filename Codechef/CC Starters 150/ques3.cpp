#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            hash[arr[i]]+=1;
        }
        int max_el,ind;
        max_el=INT_MIN;
        ind=1;
        for(int i=1;i<=n;i++){
            if(max_el<hash[i]){
                ind=i;
            }
            max_el=max(max_el,hash[i]);
            
        }

        hash[ind]+=hash[0];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=((hash[i]-1)*hash[i])/2;
        }
        cout<<ans<<endl;
    }
}
