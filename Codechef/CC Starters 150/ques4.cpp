#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> hash(n+1,0);
        hash[0]=n;
        int max_el=INT_MIN;
        int fin_ans=0;
        int last=0;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            hash[0]-=1;
            hash[y]+=1;
            if(i==0){
                int z=max(max_el,hash[y]);
                max_el=max(max_el,hash[y]);
                
                z+=hash[0];
                int ans=((z-1)*z)/2;
                cout<<ans<<" ";
                fin_ans=ans;
            }
            else{
                if(last==y){
                    cout<<fin_ans<<" ";
                }
                else{
                    int z=max(max_el,hash[y]);
                    max_el=max(max_el,hash[y]);
                    
                    z+=hash[0];
                    int ans=((z-1)*z)/2;
                    cout<<fin_ans-ans<<" ";
                    fin_ans-=ans;
                }
            }
            last=y;
        }
        
        cout<<endl;
        
    }
}
