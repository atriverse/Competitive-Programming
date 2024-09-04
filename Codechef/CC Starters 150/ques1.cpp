#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    if(b>=2*a || a>=2*b){
	        cout<<0<<endl;
	    }
	    else{
	    cout<<abs(max(a,b)/2-min(a,b))<<endl;
	    }
	}

}
