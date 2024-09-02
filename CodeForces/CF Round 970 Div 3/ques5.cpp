/*
2008E - Alternating String
Firstly, since first operation can be used at most 1 time, we need to use it only when string has odd length.

Let's assume that the string has even length, then we can look at characters on odd and even positions independently. So, if we change all characters on even positions to the character that which is occurs the most. Same goes to the characters on the odd position.

Now, we have case where we need to delete one character. We can make prefix sum on even positions (let's call pref1[i][c] number of c on such even i>j and s[j]=c), prefix sum on odd position (let's call it pref2[i][c]. Definition same as for pref1[i][c] but with odd instead of even), suffix sum on even positions (let's call it suff1[i][c] and definition same as pref1[i][c] but with j>i instead of i>j) and suffix sum on odd positions (let's call it suff2[i][c] and definition same as pref2[i][c] but with j>i instead of i>j). If we delete character on index i, our string after i shift right and changes parity for all indeces bigger then i, so to find how many characters c there are on even positions after deleting index i is pref1[i][c]+suf2[i][c]. Using this, we can try to delete each character independently and solve the task as it has even length.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int res=s.size();
        if(n%2==0)
        {
            vector<int>v[2]={vector<int>(26),vector<int>(26)};
            for(int i=0;i<n;i++)
            {
                v[i%2][s[i]-'a']++;
            }
            for(int i=0;i<2;i++)
            {
                int mx=0;
                for(int j=0;j<26;j++)
                {
                    mx=max(mx,v[i][j]);
                }
                res-=mx;
            }
            cout<<res<<endl;
        }
        else
        {
            vector<int>pref[2]={vector<int>(26),vector<int>(26)};
            vector<int>suf[2]={vector<int>(26),vector<int>(26)};
            for(int i=n-1;i>=0;i--)
            {
                suf[i%2][s[i]-'a']++;
            }
            for(int i=0;i<n;i++)
            {
                suf[i%2][s[i]-'a']--;
                int ans=n;
                for(int k=0;k<2;k++)
                {
                    int mx=0;
                    for(int j=0;j<26;j++)
                    {
                        mx=max(mx,suf[1-k][j]+pref[k][j]);
                    }
                    ans-=mx;
                }
                res=min(res,ans);
                pref[i%2][s[i]-'a']++;
            }
            cout<<res<<endl;
        }
    }
}