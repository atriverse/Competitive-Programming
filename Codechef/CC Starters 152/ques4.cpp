/*
Anti-Palindrome Queries
An array B of length M is called an anti-palindrome if no pair of its opposite elements are equal.
That is, Bi!=BM+1−i   should hold for every index 1≤i≤M.
For example, [1,2] and [1,2,3,2] are anti-palindromes, but [1,2,3] and [1,2,3,1] are not (i=2 is violated in the first case, i=1 in the second).

We say the array B is beautiful if every cyclic rotation  of B is an anti-palindrome.

You are given an array A of length N, which contains only the integers 1,2, and 3.
Answer Q queries on this array:

Given L and R, let B=[AL,A L+1  ,…,AR] denote the subarray of A from index L to index R.
Is it possible to rearrange the elements of B to make it beautiful   
A cyclic rotation of an array is obtained by repeatedly removing its last element and placing it at the beginning 
For example, the cyclic rotations of A=[1,2,2,3] are:[1,2,2,3],[3,1,2,2],[2,3,1,2],[2,2,3,1].

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers N and Q — the length of the array and the number of queries The second line contains N space-separated integers A1,A2 ,…,AN.
The next Q lines describe the queries. The i-th line contains two space-separated integers L and R, the parameters of the i-th query.
Output Format
For each query, output on a new line the answer: "Yes" if it's possible to rearrange the subarray to make it beautiful, and "No" otherwise (without quotes).

Each character of the output may be printed in either uppercase or lowercase, i.e, the strings NO, nO, No, and no will all be treated as equivalent.

Constraints
1≤T≤10^5
1≤N,Q≤2⋅10^5
1≤Ai ≤3
1≤L≤R≤N
The sum of N and the sum of Q over all test cases both won't exceed 2⋅10^5.
Sample 1:
Input
2
5 4
2 2 3 1 3
2 5
2 4
1 2
1 4
6 4
1 2 3 2 2 2
1 6
4 4
4 5
1 4


Output
Yes
No
No
Yes
No
No
No
Yes

Explanation:
Test case 1: There are four queries, with their results as follows The first query asks for[2,3,1,3]. This is already beautiful, and doesn't require rearrangement.
This can be verified by looking at every cyclic shift of it, namely:
[2,3,1,3],[3,2,3,1],[1,3,2,3],[3,1,3,2].
The second query asks for [2,3,1]. It can be verified that no rearrangement of this is beautiful.
The third query asks for [2,2]. This is the only rearrangement possible, and it isn't beautiful since it isn't an anti-palindrome.
The fourth query asks for [2,2,3,1].
This is not beautiful since its third cyclic shift [2,3,1,2] isn't an anti-palindrome.
However, it can be rearranged to form [3,2,1,2], which is beautiful.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Solves a problem related to rearranging a sequence of integers to form an "anti-palindrome".
 *
 * The function takes in the number of elements N and the number of queries Q, reads in the sequence of integers A,
 * and then processes the queries. Each query specifies a range [L, R] and the function determines whether the
 * subsequence A[L-1] to A[R-1] can be rearranged to form an "anti-palindrome".
 *
 * The function uses a prefix sum approach to efficiently count the occurrences of each integer value (1, 2, 3) in
 * the given range. It then checks if the maximum count of any integer value is equal to half the length of the
 * range, which would indicate that the subsequence can be rearranged to form an "anti-palindrome".
 *
 * The time complexity of this function is O(n + q), where n is the length of the input sequence A and q is the
 * number of queries.
 */
void solve() {
    int n, q;
    cin >> n >> q;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } //O(n)

    vector < vector < int >> pr(4, vector < int > (n + 1, 0)); //pr[1], pr[2], pr[3]
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) pr[j][i] = pr[j][i - 1];
        pr[a[i - 1]][i]++;
    }
    //O(n)

    while (q--) {
        int l, r;
        cin >> l >> r;
        if ((r - l + 1) % 2) {
            cout << "No\n";
            continue;
        }
        vector < int > c(4); //c[1], c[2], c[3]
        for (int j = 0; j <= 3; j++) c[j] = pr[j][r] - pr[j][l - 1];
        if (max({c[1], c[2], c[3]}) == (r - l + 1) / 2) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    } //O(q)

}

//tc -> O(n+q)

int32_t main() {

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}