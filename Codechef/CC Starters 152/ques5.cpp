/*
Completion (Easy)
This is the easy version of the problem. Here, it is guaranteed that P2i =0 for all i.

You are given a permutatio   P of the integers 1 to 2N, with some of its elements missing (represented by 0's).
Find the number of ways of filling in the zeros to obtain a valid permutation, such that the quantity
∣P1 −P2 ∣+∣P3  −P4 ∣+…+∣P2N−1  −P2N|
is maximized.

In this version of the problem, there is an additional constraint on the input: all the elements at even positions are 0, that is
 P2  =P4  =P6  =…=P 2N  =0.
Note that the elements at odd positions may or may not be zero.

The answer can be large, so find it modulo 998244353
A permutation of the integers 1 to N is an array of length N that contains every integer from 1 to N exactly once.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input The first line of each test case contains a single integer N — meaning that P has length 2N.
The second line contains 2N space-separated integers P1  ,P2  ,…,P 2N .
Output Format
For each test case, output on a new line the number of ways of filling in the zeros to maximize the sum, modulo 998244353


Constraints
1≤T≤10 ^5
1≤N≤2⋅10^5
0≤P i ≤2N
P2i=0 for all 1≤i≤N.
All the non-zero elements of P are distinct The sum of N over all test cases won't exceed ⋅2⋅10 ^5

Sample 1:
Input
3
3
4 0 1 0 2 0
4
3 0 0 0 5 0 8 0
2
0 0 0 0
Output
2
24
16
Explanation:
Test case 1: There are 6 permutations we can form by filling in the zeros:
[4,3,1,5,2,6] with a value of ∣4−3∣+∣1−5∣+∣2−6∣=9.
[4,3,1,6,2,5] with a value of ∣4−3∣+∣1−6∣+∣2−5∣=9.
[4,5,1,3,2,6] with a value of ∣4−5∣+∣1−3∣+∣2−6∣=7.
[4,5,1,6,2,3] with a value of ∣4−5∣+∣1−6∣+∣2−3∣=7.
[4,6,1,3,2,5] with a value of ∣4−6∣+∣1−3∣+∣2−5∣=7.
[4,6,1,5,2,3] with a value of ∣4−6∣+∣1−5∣+∣2−3∣=7.
The maximum possible value is 9, and two permutations attain that maximum.

Test case 2: The maximum possible value is  16, attained by  24 permutations.

Test case 3: There are 24 ways of filling in the zeros to obtain a permutation; of which it can be verified that 16 of them attain the maximum possible value of 4.
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int M = 998244353;

/**
 * Calculates the modular exponentiation of a number x raised to the power of n, modulo M.
 *
 * @param x The base number.
 * @param n The exponent.
 * @return The result of x^n modulo M.
 */
int powm(int x, int n)
{
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}

vector<int> fact;

/**
 * Solves a problem by counting the number of permutations that can be formed from a given array of integers, where the maximum absolute difference between adjacent elements is maximized.
 *
 * @param n The size of the input array.
 * @param a The input array of integers.
 * @return The number of permutations that can be formed with the maximum absolute difference between adjacent elements.
 */
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    } // O(n)

    int cl = n, cg = n, c = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (a[i] != 0)
        {
            if (a[i] <= n)
            {
                cl--;
            }
            else
                cg--;
        }
        else
        {
            c++;
        }
    } // O(n)

    int ans = fact[cl] * fact[cg] % M * powm(2, c) % M;
    cout << ans << '\n';
}

// tc -> O(n + 1e6)

int32_t main()
{

    fact.assign(1e6, 1);
    for (int i = 1; i < 1e6; i++)
        fact[i] = (fact[i - 1] * i) % M;

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}