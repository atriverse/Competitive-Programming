/*
Equal Pairs (Hard)
This is the hard version of the problem. In this version, the array A is changing. The constraint on N is also larger: N≤2⋅10  .

For an array A containing non-negative integers, we define f(A) as follows:

First, for each index i such that A  =0, replace A   by an arbitrary positive integer of your choice.
Then, calculate the number of pairs (i,j) such that i<j and Ai  =Aj
That is, the number of pairs of distinct indices that contain the same value.
Let this value be P.
f(A) is then the maximum possible value of P if you choose the replacements of the zeros appropriately.
You have an array A of size N, initially filled with 0's.

You have to handle the following N events:

Given X and Y, update A  =Y. Then, find f(A).
It is guaranteed that all N events have distinct values of X - that is, each index will be updated exactly once.
Note that when computing f(A), we don't actually replace the zeros in A: we just want to know the maximum possible value of P if we replaced the zeros appropriately.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases
Each test case consists of multiple lines of input
The first line of each test case contains N - the size of the array
The next N lines each contain 2 integers X and Y - meaning we must update A  =Y.
Output Format
For each test case, output N space-separated integers on a single line - the value of f(A) after each of the N events.

Constraints
 1≤T≤10
 1≤N≤2⋅10^5
 1≤X,Y≤ N
 All N events have distinct values of X
 The sum of N over all test cases does not exceed 2⋅10^5.
Sample 1:
Input
3
4
3 2
1 1
4 1
2 4
1
1 1
3
1 1
2 1
3 1
Output
6 3 3 1
0
3 3 3
Explanation:
Test case 1: The initial array A is [0,0,0,0].

After the first event, the array A is [0,0,2,0].
We have to modify all the 0 elements in array A. We can change them all to get 2 to get [2,2,2,2] which has 6 equal pairs, which is the best we can do.
After the second event, the array A is [1,0,2,0].
The zeros can be filled in to obtain [1,1,2,1] which has 3 equal pairs.
*/

//Solution Explanation:
/*
The code achieves its purpose through an efficient algorithm that doesn't actually modify the array, but instead keeps track of frequencies and calculates the maximum number of pairs using a clever formula. Here's how it works:

    It uses a map (mp) to keep track of the frequency of each number in the array. Initially, all elements are considered zero, so mp[0] is set to n (the array size).

    For each update, it increases the frequency of the new value (y) and decreases the count of zeros.

    It maintains a running total (keep) of the number of pairs formed by all elements except the most frequent one and zeros.

    After each update, it calculates the maximum number of equal pairs using the formula: ans = keep - eqn(curr_max) + eqn(curr_max + mp[0]) Where eqn(x) calculates x * (x-1) / 2, which is the number of pairs that can be formed from x elements.

    This formula subtracts the pairs formed by the most frequent element (curr_max) and adds the maximum possible pairs that could be formed by replacing zeros with the most frequent element.

The main logic flow involves processing each update, adjusting the frequencies, updating the running total, and calculating the maximum number of pairs. This approach allows the program to handle large inputs efficiently without actually modifying the array.

The code uses long long integers (ll) to handle potentially large numbers and includes some optimizations for faster input/output in competitive programming contexts.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll eqn(ll x)
{
    return (x * (x - 1)) / 2;
}

void TRAVERSAL()
{
    ll n; cin >> n;
    map<ll, ll> mp, solve;
    mp[0] = n;
    ll curr_max = 0, keep = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[y]++;
        mp[0]--;
        ll ans = 0;
        keep -= eqn(mp[y] - 1); // erasing previous occurences of y
        keep += eqn(mp[y]);     // inserting current occurences of y

        curr_max = max(curr_max, mp[y]);

        ans = keep - eqn(curr_max) + eqn(curr_max + mp[0]);

        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll TEST;
    cin >> TEST;
    while (TEST--)
        TRAVERSAL();
}
/*
Time Complexity:
The time complexity of this solution is O(T * N * log N), where T is the number of test cases and N is the size of the array for each test case.

Here's a breakdown of the time complexity:

The outer loop runs T times, once for each test case.

For each test case, we have:

Initialization of variables and map: O(1)
A loop that runs N times, where each iteration:
Performs map operations (insertion/update) which take O(log N) time
Calculates and outputs the answer in constant time
The operations inside the inner loop are dominated by the map operations, which take O(log N) time.

Therefore, for each test case, the time complexity is O(N * log N).

Considering all test cases, the overall time complexity becomes O(T * N * log N).
*/