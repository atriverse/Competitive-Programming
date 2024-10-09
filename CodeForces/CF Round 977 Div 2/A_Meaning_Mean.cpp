/*
A. Meaning Mean
time limit per test1 second
memory limit per test256 megabytes
Pak Chanek has an array a of n positive integers. Since he is currently learning how to calculate the floored average of two numbers, he wants to practice it on his array a.

While the array a has at least two elements, Pak Chanek will perform the following three-step operation:

Pick two different indices i and j (1≤i,j≤|a|; i≠j), note that |a| denotes the current size of the array a.
Append ⌊ai+aj2⌋∗ to the end of the array.Remove elements ai and aj from the array and concatenate the remaining parts of the array.For example, suppose that a=[5,4,3,2,1,1]. If we choose i=1 and j=5, the resulting array will be a=[4,3,2,1,3]. If we choose i=4 and j=3, the resulting array will be a=[5,4,1,1,2].After all operations, the array will consist of a single element x. Find the maximum possible value of x if Pak Chanek performs the operations optimally.∗⌊x⌋ denotes the floor function of x, which is the greatest integer that is less than or equal to x. For example, ⌊6⌋=6, ⌊2.5⌋=2, ⌊−3.6⌋=−4 and ⌊π⌋=3
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤5000). The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤50) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.

Do note that the sum of n over all test cases is not bounded.

Output
For each test case, output a single integer: the maximum possible value of x after all numbers have been picked.

Example
InputCopy
3
5
1 7 8 4 5
3
2 6 5
5
5 5 5 5 5
OutputCopy
6
4
5
Note
In the first test case, the array is initially a=[1,7,8,4,5]. Pak Chanek will perform the following operations:Pick i=1 and j=2, then a=[8,4,5,4].Pick i=3 and j=2, then a=[8,4,4].Pick i=2 and j=3, then a=[8,4].Pick i=1 and j=2, then a=[6].
After all the operations, the array consists of a single element x=6. It can be proven that there is no series of operations that results in x greater than 6 in the end.



*/

//Editorial
/*
2021A - Meaning Mean
For now, let's ignore the floor operation, so an operation is merging two elements ai and aj into one element ai+aj2.

Consider the end result. Each initial element in a must contribute a fractional coefficient to the final result. It turns out that the sum of the coefficients is fixed (it must be 1). That means we can greedily give the biggest values in a the biggest coefficients.

One way to do this is by sorting a in ascending order. We merge a1 and a2, then merge that result with a3, then merge that result with a4, and so on until an. If we do this, an contributes 12 times, an−1 contributes 14 times, an−2 contributes 18 times, and so on. This is the optimal way to get the maximum final result.

It turns out that the strategy above is also the optimal strategy for the original version of the problem. So we can simulate that process to get the answer.

Time complexity for each test case: O(nlogn)
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

/**
 * Solves the "Meaning Mean" problem from CodeForces Round 977 Division 2.
 * 
 * The problem involves finding the maximum possible value of x after performing a series of operations on an array a.
 * The operations involve merging two elements ai and aj into one element (ai + aj) / 2.
 * 
 * This implementation first reads in the number of test cases t, then for each test case:
 * 1. Reads in the length of the array n and the elements of the array a.
 * 2. Sorts the array a in ascending order.
 * 3. Initializes the answer variable ans to the first element of the sorted array.
 * 4. Iterates through the remaining elements of the sorted array, merging each element with the current ans value.
 * 5. Outputs the final value of ans, which represents the maximum possible value of x.
 * 
 * The time complexity of this solution is O(n log n) for each test case, where n is the length of the array a.
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = v[0];
        for (int i = 1; i < n; i++){
            ans=(ans+v[i])/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}