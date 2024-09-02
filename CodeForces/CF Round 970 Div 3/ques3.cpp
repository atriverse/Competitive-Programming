#include<bits/stdc++.h>
using namespace std;

int f(int a, int b){
    if (a==b)
    {
        return 1;
    }
    else{
        int x=1;
        int ans=1;
        int y=a;
        for (int i = a; i <=b; i=i+x)
        {
            if (y+x<=b)
            {
                y+=x;
                ans+=1;
            }
            x+=1;
        }
        return ans;
        
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<f(a,b)<<endl;
    }
    return 0;
}
/*
2008C - Longest Good Array
We can solve this problem greedily. Let's choose the first element equal to l. Then, the second element should be l+1. The third l+3, and so on. In general, the i−th element is equal to l+i⋅(i+1)2.

Proof of this solution:

Assume that array a is the array made by our algorithm and b is the array with a better answer. This means that len(b)>len(a). By the construction of a, there exists an integer i such that for all j<i, aj=bj and ai<bi, because ai we choose as the smallest possible element. WLOG assume that len(b)=len(a)+1=n. Then bn−bn−1>bn−1−bn−2≥an−1−an−2. So, we can append bn to the array a, which leads to a contradiction.

Now, the task is to find the biggest x such that l+x⋅(x+1)2≤r. In fact, it can be found by binary search, the formula of discriminant, or just by brute force.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        b-=a;
        long long l=2,r=1000000000;
        while(l<r)
        {
            long long m=(l+r)/2;
            if(m*(m-1)/2<=b)
            {
                l=m+1;
            }
            else
            {
                r=m;
            }
        }
        cout<<l-1<<endl;
    }
}
*/