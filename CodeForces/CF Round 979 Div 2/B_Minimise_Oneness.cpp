/*
B. Minimise Oneness
time limit per test1.5 seconds
memory limit per test256 megabytes
For an arbitrary binary string t∗, let f(t) be the number of non-empty subsequences† of t that contain only 0, and let g(t) be the number of non-empty subsequences of t that contain at least one 1.

Note that for f(t) and for g(t), each subsequence is counted as many times as it appears in t. E.g., f(000)=7,g(100)=4.

We define the oneness of the binary string t to be |f(t)−g(t)|, where for an arbitrary integer z, |z| represents the absolute value of z.

You are given a positive integer n. Find a binary string s of length n such that its oneness is as small as possible. If there are multiple strings, you can print any of them.
∗A binary string is a string that only consists of characters 0 and 1.

†A sequence a is a subsequence of a sequence b if a can be obtained from b by the deletion of several (possibly, zero or all) elements. For example, subsequences of 1011101 are 0, 1, 11111, 0111, but not 000 nor 11100.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The only line of each test case contains an integer n (1≤n≤2⋅105) — the length of s.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output s on a new line. If multiple answers exist, output any.

Example
Input
3
1
2
3
Output
0
01
010
Note
In the first test case, for the example output, f(t)=1 because there is one subsequence that contains only 0 (0), and g(t)=0 because there are no subsequences that contain at least one 1. The oneness is |1−0|=1. The output 1 is correct as well because its oneness is |0−1|=1.

For the example output of the second test case, f(t)=1 because there is one non-empty subsequence that contains only 0, and g(t)=2 because there are two non-empty subsequences that contain at least one 1 (01 and 1). The oneness is thus |1−2|=1. It can be shown that 1 is the minimum possible value of its oneness over all possible binary strings of size 2.
*/

//Editiorial
/*
Observation: f(t)−g(t) is odd.

Proof: f(t)+g(t) is the set of all non-empty subsets of t, which is 2|t|−1, which is odd. The sum and difference of two integers has the same parity, so f(t)−g(t) is always odd.

By including exactly one 1 in the string s, we can make f(s)=2n−1−1 and g(s)=2n−1, or f(s)−g(s)=1 by the multiplication principle. Clearly, this is the best we can do. So, we print out any string with exactly one 1.
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        if (i==0)
        {
            cout<<'1';
        }
        else{
            cout<<'0';
        }
        
    }
    cout<<endl;
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}