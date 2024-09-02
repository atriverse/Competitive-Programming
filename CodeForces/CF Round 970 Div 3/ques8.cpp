/*
2008H - Sakurako's Test
Let's fix one x and try to solve this task for it. As we know, in 0−indexed array median is ⌊n2⌋ where n is number of elements in the array, so to find median, we need to find the smallest element which has at least ⌊n2⌋ elements in the array that is less or equal to it. Also, it is obvious, that we need to decrease all elements till we can, since the least element, the least median of the array is. So, after all operation, we change ai to aimodx.

How to find number of i that aimodx≤m for some m. In fact, we can try to find number of elements in range [k⋅x,k⋅x+m] for all k, since all this elements will be less then m if we take it by modulo x. To find number of elements in such range, we can notice that ai≤n, so we can make prefix sum of counting array (let's call it pref[i] number of elements less or equal i) and then number of elements in tange [a,b] will be pref[b]−pref[a−1]. Also, since ai≤n, k will be less then nx, so for fixed x our solution will work in nx⋅log(n). Let's precompute it for all x in range [1,n]. Then, it will work in time ∑n+1x=1nx⋅log(n)=log(n)⋅∑n+1x=1nx=(∗)log(n)⋅n⋅log(n)=n⋅log2(n).
(∗) This transition is true because of ∑n+1i=1nx is harmonic series. It means, ∑n+1i=1nx=n⋅∑n+1i=11x≤n⋅log(n).
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Solves the "2008H - Sakurako's Test" problem from Codeforces Round 970 Division 3.
 * The problem involves finding the median of an array after performing a modulo operation on each element.
 * The solution uses a prefix sum approach to efficiently count the number of elements less than or equal to a given value.
 * The time complexity of the solution is O(n * log(n)).
 */
int main()
{
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        vector<int>c(n+1,0ll);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            c[a[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            c[i]+=c[i-1];
        }
        int res[n+1]={0};
        for(int x=1;x<=n;x++)
        {
            int l=0,r=x;
            while(l<r)
            {
                int mid=(l+r)/2;
                int cnt=c[mid];
                for(int k=1;k*x<=n;k++)
                {
                    cnt+=c[min(k*x+mid,n)]-c[k*x-1];
                }
                if(cnt-1>=n/2)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            res[x]=l;
        }
        while(m--)
        {
            int x;
            cin>>x;
            cout<<res[x]<<" ";
        }
        cout<<endl;
    }
}