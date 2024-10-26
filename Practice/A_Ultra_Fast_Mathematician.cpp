#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    cin>>s1;
    cin>>s2;
    string s3="";
    for(int i=0;i<s1.size();i++){
        if (s1[i]!=s2[i])
        {
            s3+="1";
        }
        else{
            s3+="0";
        }
        
    }
    cout<<s3<<endl;

    return 0;
}