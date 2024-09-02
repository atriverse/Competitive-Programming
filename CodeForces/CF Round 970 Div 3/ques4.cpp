/*
2008D - Sakurako's Hobby
Any permutation can be divided into some number of cycles, so F(i) is equal to the number of black colored elements in the cycle where i is. So, we can write out all cycles in O(n) and memorize for each i the number of black colored elements in the cycle where it is.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long p[n+1]={0},b[n+1]={0};
        int us[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        string s;
        cin >> s;
        for(int i=1;i<=n;i++)
        {
            /// Skips the current element if it has already been visited.
            if(us[i])continue;
            int sz=0;

            /// Traverses the cycle starting from the current element 'i' and counts the number of black elements in the cycle.
            /// The 'us' array is used to mark visited elements to avoid revisiting them.
            /// The 'sz' variable keeps track of the number of black elements in the current cycle.
            while(!us[i])
            {
                us[i]=1;
                sz += s[i - 1] == '0';
                i=p[i];
            }
            /// Traverses the cycle starting from the current element 'i' and sets the number of black elements in the cycle for each element in the cycle.
            /// The 'us' array is used to mark visited elements as 2 to avoid revisiting them.
            /// The 'b' array is used to store the number of black elements in the cycle for each element.
            while(us[i]!=2)
            {
                b[i]=sz;
                us[i]=2;
                i=p[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}