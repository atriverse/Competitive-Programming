/*
C. Bitwise Balancing
time limit per test2 seconds
memory limit per test256 megabytes
You are given three non-negative integers b, c, and d.

Please find a non-negative integer a∈[0,261] such that (a|b)−(a&c)=d, where | and & denote the bitwise OR operation and the bitwise AND operation, respectively.
If such an a exists, print its value. If there is no solution, print a single integer −1. If there are multiple solutions, print any of them.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). The description of the test cases follows.

The only line of each test case contains three positive integers b, c, and d (0≤b,c,d≤1018).

Output
For each test case, output the value of a, or −1 if there is no solution. Please note that a must be non-negative and cannot exceed 261.

Example
Input
3
2 2 2
4 2 6
10 2 14
Output
0
-1
12
Note
In the first test case, (0|2)−(0&2)=2−0=2. So, a=0 is a correct answer.

In the second test case, no value of a satisfies the equation.

In the third test case, (12|10)−(12&2)=14−0=14. So, a=12 is a correct answer.
*/

//Editorial
/*
The first observation is that the expression a|b - a&c=d is bitwise independent. That is, the combination of a tuple of bits of a,b,and c corresponding to the same power of 2 will only affect the bit value of d at that power of 2 only.

This is because:

We are performing subtraction, so extra carry won't be generated to the next power of 2.

Any tuple of bits of a, b, and c corresponding to the same power of 2 won't result in -1 for that power of 2. As that would require a|b to be zero and a&c to be one. The former condition requires the bit of a to be zero, while the latter requires it to be one, which is contradicting.

Now, let us consider all 8 cases of bits of a, b, c and the corresponding bit value of d in the following table:

 b  c    a    d
 0  0    0    0
 0  0    1    1
 0  1    0    0
 0  1    1    0
 1  0    0    1
 1  0    1    1
 1  1    0    1
 1  1    1    0

So, clearly, for different bits of b,c, and d, we can find the value of the corresponding bit in a, provided it is not the case when bit values of b,c, and d are 1,0,0 or 0,1,1, which are not possible; so, in that case, the answer is -1.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
/**
 * Solves a problem related to bitwise operations and balancing.
 * 
 * The function takes three long long integers `b`, `c`, and `d` as input, and
 * computes a non-negative integer `a` that satisfies the equation `(a|b) - (a&c) = d`.
 * If no such `a` exists, the function outputs `-1`.
 * 
 * The function works by iterating through the bits of `a`, `b`, `c`, and `d`, and
 * determining the value of each bit of `a` based on the values of the corresponding
 * bits in `b`, `c`, and `d`. The function uses bitwise operations to efficiently
 * compute the values of the bits.
 * 
 * @param b The first input long long integer.
 * @param c The second input long long integer.
 * @param d The third input long long integer.
 */
void solve() {
    ll a = 0, b, c, d, pos = 1, bit_b, bit_c, bit_d, mask = 1;
    cin >> b >> c >> d;
    for (ll i = 0; i < 62; i++) {
        if (b&mask) bit_b = 1;
        else bit_b = 0;
        if (c&mask) bit_c = 1;
        else bit_c = 0;
        if (d&mask) bit_d = 1;
        else bit_d = 0;
        if ((bit_b && (!bit_c) && (!bit_d)) || ((!bit_b) && bit_c && bit_d)) {
            pos = 0;
            break;
        }
        if (bit_b && bit_c) {
            a += (1ll-bit_d)*mask;
        } else {
            a += bit_d*mask;
        }
        mask<<=1;
    }
    if (pos) {
        cout << a << "\n";
    } else {
        cout << -1 << "\n";
    }
}
 
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}