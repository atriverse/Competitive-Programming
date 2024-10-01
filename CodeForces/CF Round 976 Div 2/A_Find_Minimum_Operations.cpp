/*
A. Find Minimum Operations
time limit per test1 second
memory limit per test256 megabytes
You are given two integers n and k.

In one operation, you can subtract any power of k from n. Formally, in one operation, you can replace n by (n−kx) for any non-negative integer x.

Find the minimum number of operations required to make n equal to 0.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.
The only line of each test case contains two integers n and k (1≤n,k≤109).

Output
For each test case, output the minimum number of operations on a new line.

Example
Input
6
5 2
3 5
16 4
100 3
6492 10
10 1
Output
2
3
1
4
21
10
Note
In the first test case, n=5 and k=2. We can perform the following sequence of operations:Subtract 20=1 from 5. The current value of n becomes 5−1=4.Subtract 22=4 from 4. The current value of n becomes 4−4=0.
It can be shown that there is no way to make n equal to 0 in less than 2 operations. Thus, 2 is the answer.
In the second test case, n=3 and k=5. We can perform the following sequence of operations:Subtract 50=1 from 3. The current value of n becomes 3−1=2.Subtract 50=1 from 2. The current value of n becomes 2−1=1.Subtract 50=1 from 1. The current value of n becomes 1−1=0.
It can be shown that there is no way to make n equal to 0 in less than 3 operations. Thus, 3 is the answer.
*/


//Editorial
/*
If k is 1, we can only subtract 1 in each operation, and our answer will be n.

Now, first, it can be seen that we have to apply at least n mod k operations of subtracting k0 (as all the other operations will not change the value of n mod k). Now, once n is divisible by k, solving the problem for n is equivalent to solving the problem for nk as subtracting k0 will be useless because if we apply the k0 subtraction operation, then n mod k becomes k−1, and we have to apply k−1 more operations to make n divisible by k (as the final result, i.e., 0 is divisible by k). Instead of doing these k operations of subtracting k0, a single operation subtracting k1 will do the job.

So, our final answer becomes the sum of the digits of n in base k.

The complexity of the solution is O(logkn) per testcase.
*/
#include <cstdio>

/**
 * Calculates the minimum number of operations required to make the given integer `n` equal to 0, where each operation subtracts any power of `k` from `n`.
 *
 * @param n The integer to be reduced to 0.
 * @param k The base used to subtract powers from `n`.
 * @return The minimum number of operations required to make `n` equal to 0.
 */
long long minOperations(long long n, long long k) {
    if (k == 1) return n;
    
    long long operations = 0;
    while (n > 0) {
        operations += n % k;
        n /= k;
    }
    return operations;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", minOperations(n, k));
    }

    return 0;
}
