/*
D. Minimize the Difference
time limit per test2 seconds
memory limit per test256 megabytes
Zhan, tired after the contest, gave the only task that he did not solve during the contest to his friend, Sungat. However, he could not solve it either, so we ask you to try to solve this problem.

You are given an array a1,a2,…,an of length n. We can perform any number (possibly, zero) of operations on the array.

In one operation, we choose a position i (1≤i≤n−1) and perform the following action:

ai:=ai−1, and ai+1:=ai+1+1.
Find the minimum possible value of max(a1,a2,…,an)−min(a1,a2,…,an).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤2⋅105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1012).

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer: the minimum possible value of max(a1,a2,…,an)−min(a1,a2,…,an).

Example
Input
5
1
1
3
1 2 3
4
4 1 2 3
4
4 2 3 1
5
5 14 4 10 2
Output
0
2
1
1
3
Note
In the third testcase, you can perform the operation twice with i=1.

After that, the array is a=[2,3,2,3], and max(2,3,2,3)−min(2,3,2,3)=3−2=1.
*/
#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long>& a) {
    int n = a.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    long long avg = sum / n;
    long long rem = sum % n;
    
    long long min_val = avg;
    long long max_val = avg + (rem > 0);
    
    return max_val - min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << solve(a) << "\n";
    }
    
    return 0;
}
