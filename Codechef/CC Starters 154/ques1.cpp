#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;
            if(sum<=k){
                count++;
            }
        }
        cout<<count<<endl;
    }
}
