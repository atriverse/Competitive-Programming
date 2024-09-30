/*
A. Max Plus Size
time limit per test1 second
memory limit per test256 megabytes
EnV - Dynasty
⠀
You are given an array a1,a2,…,an of positive integers.

You can color some elements of the array red, but there cannot be two adjacent red elements (i.e., for 1≤i≤n−1, at least one of ai and ai+1 must not be red).

Your score is the maximum value of a red element plus the number of red elements. Find the maximum score you can get.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1000) — the given array.

Output
For each test case, output a single integer: the maximum possible score you can get after coloring some elements red according to the statement.

Example
Input
4
3
5 4 5
3
4 5 4
10
3 3 3 3 4 1 2 3 4 5
9
17 89 92 42 29 92 14 70 45
Output
7
6
10
97
Note
In the first test case, you can color the array as follows: [5,4,5]. Your score is max([5,5])+size([5,5])=5+2=7. This is the maximum score you can get.

In the second test case, you can color the array as follows: [4,5,4]. Your score is max([4,4])+size([4,4])=4+2=6. This is the maximum score you can get.

In the third test case, you can color the array as follows: [3,3,3,3,4,1,2,3,4,5]. Your score is max([3,3,4,3,5])+size([3,3,4,3,5])=5+5=10. This is the maximum score you can get.
*/

// Editorial
/*
The maximum red element is ≤max(a), and the maximum number of red elements is ⌈n/2⌉. Can you reach the score max(a)+⌈n/2⌉?

If n is even, you always can, by either choosing all the elements in even positions or all the elements in odd positions (at least one of these choices contains max(a)).
If n is odd, you can if and only if there is one occurrence of max(a) in an odd position. Otherwise, you can choose even positions and your score is max(a)+⌈n/2⌉−1.
Complexity: O(n)
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

/**
 * Solves the problem of finding the maximum score that can be obtained by coloring some elements of an array red.
 * The score is the maximum value of a red element plus the number of red elements.
 * The input consists of multiple test cases, where each test case has an array of integers.
 * The output for each test case is the maximum possible score.
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
        cin>>n;
        vector<int> v(n);
        int maxi_o=0;
        int maxi_e=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if (v[i]>=maxi_o && i%2==0)
            {
                maxi_o=max(maxi_o,v[i]);
            }
            if (v[i]>=maxi_e && i%2!=0)
            {
                maxi_e=max(maxi_e,v[i]);
            }
        }
        cout<<max(maxi_o+(n+1)/2,maxi_e+n/2)<<endl;
    }

    return 0;
}