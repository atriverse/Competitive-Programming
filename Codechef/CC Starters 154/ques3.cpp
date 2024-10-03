/*
GCD and XOR
You are given an array A of size N.
You can perform the following operation as many times as you want (possibly, zero):

Choose integers L,R,X such that 1≤L≤R≤N and 1≤X<2^30 , and do any one of the following:
For all L≤i≤R, set Ai to Ai⊕X.
⊕ denotes the bitwise XOR operation.
For all L≤i≤R, set Ai  to gcd(Ai,X).
That is, choose a subarray of A and an integer X, and either replace every element of the subarray with its GCD with X, or replace every element of the subarray with its bitwise XOR with X.

Compute the minimum number of operations required to make all elements of the array equal to K.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains two space-separated integers N and K — the size of the array, and the required value.
The second line contains N space-separated integers — A1 ,A2 ,…,AN
​
 
Output Format
For each test case, output on a new line one integer: the minimum number of operations.

Constraints

1≤T≤10^4
1≤N≤2⋅10^5
1≤K,Ai<2^30
 
The sum of N across all tests does not exceed 2⋅10^5.
Sample 1:
Input
3
4 2
2 6 4 1
1 3
3
2 2
4 8
Output
2
0
1
Explanation:
Test case 1: We can do the following operations:

Choose L=2,R=3,X=2 and the gcd operation. This turns the array 
A into [2,2,2,1].
Choose L=4,R=4,X=3 and the xor operation. This turns the array A into 
[2,2,2,2].
It can be proven that it is impossible to make all elements equal to 2 in fewer than 2 moves, and so this is optimal.

Test case 3: Choose L=1,R=2,X=2 and the gcd operation.
*/

//Explanation:
/*
The algorithm works as follows:

    -> It reads the input array and stores it in a vector 'a'.
    -> It creates a set 's' to store unique values from the array.
    -> It calculates the GCD of all elements in the array.
    -> It counts the number of "ranges" in the array, where a range is a consecutive sequence of elements not equal to k.
    -> It removes k from the set of unique values.
    -> Finally, it determines the minimum number of operations based on these conditions:
        -> If the set is empty (all elements are already k), it outputs 0.
        -> If the GCD of all elements is divisible by k, or if all non-k elements are the same and in a single range, it outputs 1.
        -> Otherwise, it outputs 2.

The key logic here is that if the GCD of all elements is divisible by k, we can make all elements equal to k in one GCD operation. Similarly, if all non-k elements are the same and in a single range, we can make them all k in one XOR operation. In all other cases, we need at most two operations.

This algorithm efficiently solves the problem without actually performing the operations, by analyzing the properties of the input array.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Calculates the greatest common divisor (GCD) of two integers.
 * 
 * @param a The first integer.
 * @param b The second integer.
 * @return The greatest common divisor of a and b.
 */
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
}


/**
 * Solves the problem of making all elements in an array equal to a target value 'k' using at most two operations.
 * The operations allowed are:
 * 1. Choose a range [L, R] and perform the GCD operation on all elements in that range.
 * 2. Choose a range [L, R] and perform the XOR operation with a value 'X' on all elements in that range.
 * 
 * The algorithm works as follows:
 * 1. Read the input array and store it in a vector 'a'.
 * 2. Create a set 's' to store unique values from the array.
 * 3. Calculate the GCD of all elements in the array.
 * 4. Count the number of "ranges" in the array, where a range is a consecutive sequence of elements not equal to 'k'.
 * 5. Remove 'k' from the set of unique values.
 * 6. Determine the minimum number of operations based on the following conditions:
 *    - If the set is empty (all elements are already 'k'), output 0.
 *    - If the GCD of all elements is divisible by 'k', or if all non-'k' elements are the same and in a single range, output 1.
 *    - Otherwise, output 2.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;

    while(tt--) {
        int n, k; cin >> n >> k;

        vector<int>a(n);
        for(auto &i : a) cin >> i;

        set<int>s; 

        int g = 0;
        for(auto &i : a) g = gcd(i, g), s.insert(i);

        int ranges = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] == k) continue;
            else if(i == 0 || a[i - 1] == k) ranges++;
        }

        s.erase(k);

        if(s.size() == 0) cout << 0 << "\n";
        else if(g % k == 0 || (*s.begin() == *s.rbegin() && ranges == 1)) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}