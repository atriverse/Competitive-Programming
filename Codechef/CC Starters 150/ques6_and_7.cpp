/*
Min Ops (Easy)
This is the easy version of the problem. All the constraints in this problem are smaller. Notably,N,Q<=2.10^5,Ai ,K≤30.
Min Ops (Hard)
This is the hard version of the problem. All the constraints in this problem are larger. Notably, N,Q≤2⋅10^5  and Ai,K≤10^9.


Given an array B of length M, consider the following operation on it:

Choose L and R such that 
1≤L≤R≤M 
Bi=BL   for all L≤i≤R
L=1 or BL!=BL−1 
R=M or BR!=BR+1 ​
 
Then, do one of the following 2 actions for every L≤j≤R, modify Bj   to Bj+1; or
for every L≤j≤R, modify Bj to Bj−1.

Less formally, an operation is choosing a range of equal values in the array A that's maximal (meaning the range can't be further extended left or right without including a different value), and either adding 1 to each element, or subtracting 1 from each element.
Note that in a single operation, you are not allowed to add 1 to some values and subtract 1 from others: every value in the chosen range must be modified in the same way.

For an integer K, we define f(B,K) to be the minimum number of operations required to ensure that the sum of adjacent differences of B doesn't exceed K, that is,
M
∑∣Bi−B(i−1)∣≤K
i=2
You are given an array A of length N. Answer Q queries on it:

Given L,R, and K, find f(A[L…,R],K) A[L…R] refers to the subarray [AL,AL+1,…,AR] of A.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line contains N and Q - the size of the array and the number of queries, respectively 
The second line contains N integers - A1,A2,…,AN ​
 
The next Q lines contain 3 integers each - L, R and K, the parameters of each query.
Output Format
For each query, output on a new line f(A[L…R],K)

Constraint
1≤T≤10^4
2≤N≤2.10^5
1≤Q≤2.10^5
0≤Ai≤10^9
1≤K≤10^9
1≤L<R≤N 

Sample 1:
Input
3
3 5
1 6 4
1 3 1
1 3 4
1 3 8
1 2 2
2 3 2
6 7
2 9 4 7 1 5
1 6 13
1 6 2
1 3 2
1 3 1
2 5 10
1 2 10
4 6 6
4 1
1 1 1 3
1 4 1

Output
4
2
0
3
0
6
12
5
6
2
0
2
1
Explanation:
Test case 1: We have A=[1,6,4].

Query 1: We perform the following operation 
Choose L=2,R=2 and decrement by 1 to get A=[1,5,4]
Choose L=1,R=1 and increment by 1 to get A=[2,5,4] 
Choose L=1,R=1 and increment by 1 to get A=[3,5,4] 
Choose L=2,R=2 and decrement by 1 to get A=[3,4,4]
                                                   3
At the end of these 4 operations, you can note that∑i=2 ∣Ai −Ai−1∣=1≤K(=1) holds.
Test case 3: We have A=[1,1,1,3].

Query 1:
Choose L=1,R=3 and increment by 1 (note that this is a maximal segment of equal elements). Then A=[2,2,2,3] 
The sum of adjacent differences is 1.

*/

//Soulution and Explanation:
/*
The program then processes Q queries. For each query, it reads three numbers: L, R, and K. L and R represent the start and end indices of a subarray, and K is the maximum allowed sum of differences.

The main logic of the program is in handling these queries. It calculates the sum of differences in the subarray using the prefix sum array. If this sum is already less than or equal to K, it outputs 0 as no operations are needed. If K is greater than or equal to the absolute difference between the first and last elements of the subarray, it calculates the minimum operations needed using a formula. Otherwise, it uses a more complex calculation involving multiple steps.

The program achieves its purpose by using prefix sums to quickly calculate the sum of differences in any subarray, and then applying different formulas based on the relationship between this sum, K, and the difference between the first and last elements of the subarray.

The main data transformation happening is the creation of the prefix sum array, which allows for efficient querying of subarrays. The important logic flow is in the handling of different cases in the query processing part.
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long


void minOps() {
    int n, q;
    cin >> n >> q;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector < int > pr(n, 0);
    pr[0] = 0;
    for (int i = 0; i < n; i++) {
        pr[i] = pr[i - 1] + abs(a[i] - a[i - 1]);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        int sum = pr[r] - pr[l];
        int diff = abs(a[r] - a[l]);
        if (sum <= k) {
            cout << "0\n";
        }
        else if (k >= diff) {
            cout << (sum - k + 1) / 2 << '\n';
        }
        else {
            int ans = (sum - diff + 1) / 2;
            // cout<<ans<<' '<<sum<<' '<<diff<<' ';
            sum -= ans * 2;
            ans += sum - k;
            cout << ans << '\n';
        }
    }

}

int32_t main() {

    int t = 1;
    cin >> t;
    while (t--) {
        minOps();
    }
    return 0;
}
/*
Time Complexity:
The time complexity of this program can be broken down as follows:

    Input processing:   
        Reading the array of size N: O(N)
        Creating the prefix sum array: O(N)

    Query processing:
        For each query, the operations are constant time: O(1)
        Total queries: Q

    Overall time complexity:
        O(N) for initial processing
        O(Q) for handling all queries
        
Therefore, the total time complexity is O(N + Q).
*/