/*
A. A Gift From Orangutan
time limit per test1 second
memory limit per test256 megabytes
While exploring the jungle, you have bumped into a rare orangutan with a bow tie! You shake hands with the orangutan and offer him some food and water. In return...

The orangutan has gifted you an array a of length n. Using a, you will construct two arrays b and c, both containing n elements, in the following manner:

bi=min(a1,a2,…,ai) for each 1≤i≤n.
ci=max(a1,a2,…,ai) for each 1≤i≤n.
Define the score of a as ∑ni=1ci−bi (i.e. the sum of ci−bi over all 1≤i≤n). Before you calculate the score, you can shuffle the elements of a however you want.

Find the maximum score that you can get if you shuffle the elements of a optimally.

Input
The first line contains t (1≤t≤100) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤1000) — the number of elements in a.

The following line contains n integers a1,a2,…,an (1≤ai≤1000) — the elements of the array a.

It is guaranteed that the sum of n over all test cases does not exceed 1000.

Output
For each test case, output the maximum score that you can get.

Example
Input
3
1
69
3
7 6 5
5
1 1 1 2 2
Output
0
4
4
Note
In the first test case, there is no other way to rearrange a. So, b=[69] and c=[69]. The only possible score is 69−69=0.

In the second test case, you can rearrange a as [7,5,6]. Here, b=[7,5,5] and c=[7,7,7]. The score in this case is (7−7)+(7−5)+(7−5)=4. It can be shown this is the maximum possible score.
*/

//Editorial
/*
First, what is the maximum possible value of ci−bj for any i,j? Since ci is the maximum element of some subset of a and bi is the minimum element of some subset of a, the maximum possible value of ci−bj is max(a)−min(a).

Also note that c1=b1 for any reordering of a. By reordering such that the largest element of a appears first and the smallest element of a appears second, the maximum possible value of the score is achieved. This results in a score of (max(a)−min(a))⋅(n−1).
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

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
        vector<int> a(n+1);
        a[0] = 0;
        int maxi=0;
        for (int i = 1; i < n+1; i++)
        {
            cin >> a[i];
            if (a[i] > maxi)    
            {
                maxi = a[i];
            }
        }
        sort(a.begin(), a.end());
        a[0]=maxi;
        int mini=INT_MAX;
        int sum=0;
        for (int i = 1; i < n; i++){
            if (a[i]<mini)
            {
                mini=a[i];
            }
            sum+=(maxi-mini);
        }
        cout<<sum<<endl;
    }

    return 0;
}