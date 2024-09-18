#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int m,p;
        cin>>m>>p;
        int w=(1000-m-p)/21;
        cout<<min(299-m,w)<<endl;
    }
}
