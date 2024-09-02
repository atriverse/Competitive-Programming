/*
2008G - Sakurako's Task
Let's look at case when n=1. We cannot change the value of the element, so we will not change the array.

If n>1, let's call g=gcd(a1,a2,…,an). Using operations in the statement, we can get only numbers 0 and that have g as a divisor. So, the best array for this task will be ai=(i−1)⋅g.

Now, we can find where the mexk should be in linear time. Firstly, if it is before the first one, then the answer is k, otherwise, we can assign k=k−a1. Then let's look at the second element. If a1+k<a2, then answer should be a1+k and otherwise we can assign k=k−a2+a1−1. In other words, when we look if our k can be in range from ai to ai+1, we know that number of elements that were not in the array and less than ai equal to k+ai. Then, when we find such i, we can output the answer.
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Solves the "Sakurako's Task" problem from Codeforces Round 970 Div 3.
 * Given an array of integers `a` of length `n` and an integer `k`, the task is to find the smallest positive integer that is not present in the array and is a multiple of the greatest common divisor (GCD) of the elements in `a`.
 * The function first calculates the GCD of the elements in `a`, and then constructs a new array `a` where each element is a multiple of the GCD. It then iterates through the new array to find the smallest positive integer that is not present and is a multiple of the GCD.
 * @param n the length of the input array `a`
 * @param k the integer to find the smallest positive multiple of the GCD that is not present in the array
 * @param a the input array of integers
 * @return the smallest positive integer that is not present in the array and is a multiple of the GCD of the elements in `a`
 */
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long long a[n+1],g=0,mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g=__gcd(g,a[i]);
            mx=max(mx,a[i]);
        }
        if(g==0)
        {
            cout<<k<<endl;
            continue;
        }
        sort(a,a+n);
        int q=-g;
        if(n!=1)
        {
            for(int i=0;i<n;i++)
            {
                q+=g;
                a[i]=q;
            }
        }
        a[n]=1e16;
        long long lst=-1;
        for(int i=0;i<=n;i++)
        {
            if(k<=a[i]-lst-1)
            {
                break;
            }
            k-=max(a[i]-lst-1,0ll);
            lst=a[i];
        }
        cout<<lst+k<<endl;
    }
}