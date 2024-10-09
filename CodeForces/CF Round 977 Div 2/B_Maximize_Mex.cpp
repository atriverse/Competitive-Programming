/*
B. Maximize Mex
time limit per test1 second
memory limit per test256 megabytes
You are given an array a of n positive integers and an integer x. You can do the following two-step operation any (possibly zero) number of times:

Choose an index i (1≤i≤n).
Increase ai by x, in other words ai:=ai+x.
Find the maximum value of the MEX of a if you perform the operations optimally.

The MEX (minimum excluded value) of an array is the smallest non-negative integer that is not in the array. For example:

The MEX of [2,2,1] is 0 because 0 is not in the array.
The MEX of [3,1,0,1] is 2 because 0 and 1 are in the array but 2 is not.
The MEX of [0,3,1,2] is 4 because 0, 1, 2 and 3 are in the array but 4 is not.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤5000). The description of the test cases follows.

The first line of each test case contains two integers n and x (1≤n≤2⋅105; 1≤x≤109) — the length of the array and the integer to be used in the operation.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) — the given array.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer: the maximum MEX of a if you perform the operations optimally.

Example
Input
3
6 3
0 3 2 1 5 2
6 2
1 3 4 1 0 2
4 5
2 5 10 3
Output
4
6
0
Note
In the first test case, the MEX of a is 4 without performing any operations, which is the maximum.

In the second test case, the MEX of a is 5 without performing any operations. If we perform two operations both with i=1, we will have the array a=[5,3,4,1,0,2]. Then, the MEX of a will become 6, which is the maximum.
In the third test case, the MEX of a is 0 without performing any operations, which is the maximum.
*/

// Editorial
/*
2021B - Maximize Mex
For the MEX to be at least k, then each non-negative integer from 0 to k−1 must appear at least once in the array.

First, notice that since there are only n elements in the array, there are at most n different values, so the MEX can only be at most n. And since we can only increase an element's value, that means every element with values bigger than n can be ignored.

We construct a frequency array freq such that freq[k] is the number of elements in a with value k.

Notice that the values just need to appear at least once to contribute to the MEX, so two or more elements with the same value should be split into different values to yield a potentially better result. To find the maximum possible MEX, we iterate each index k in the array freq from 0 to n. In each iteration of k, if we find freq[k]>0, that means it's possible to have the MEX be bigger than k, so we can iterate k to the next value. Before we iterate to the next value, if we find freq[k]>1, that indicates duplicates, so we should do an operation to all except one of those values to change them into k+x, which increases freq[k+x] by freq[k]−1 and changes freq[k] into 1. In each iteration of k, if we find freq[k]=0, that means, k is the maximum MEX we can get, and we should end the process.

Time complexity for each test case: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define yes "YES\n"
#define no "NO\n"
#define gcd __gcd
#define ed "\n"
#define cin(x)        \
    for (auto &v : x) \
        cin >> v;
/**
 * Solves a problem where the goal is to maximize the MEX (Minimum Excluded) value of an array by performing a given number of operations.
 *
 * The function takes in the size of the array (n) and the number of operations to perform (x), as well as the array itself (a). It then uses a map (mp) to keep track of the frequency of each element in the array.
 *
 * The function then iterates through the possible MEX values (from 0 to n), and checks if the current value is not present in the array. If so, it prints the current value and returns, as this is the maximum MEX that can be achieved.
 *
 * If the current value is present in the array, the function checks if its frequency is greater than 1. If so, it adds the excess frequency to the next possible MEX value (i+x), as this can be used to increase the MEX.
 *
 * @param n The size of the input array.
 * @param x The number of operations to perform.
 * @param a The input array.
 */
void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (!mp[i])
        {
            cout << i << endl;
            return;
        }
        if (mp[i] > 1)
        {
            mp[i + x] += mp[i] - 1;
        }
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}