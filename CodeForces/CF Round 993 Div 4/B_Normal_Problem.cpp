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
        string s;
        cin >> s;

        string s1="";
        for (int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='p')s1+="q";
            else if(s[i]=='q')s1+="p";
            else s1+="w";
        }
        cout<<s1<<endl;
    }

    return 0;
}