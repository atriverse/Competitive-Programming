/*
B. All Pairs Segments
time limit per test1.5 seconds
memory limit per test256 megabytes
Shirobon - FOX
⠀
You are given n points on the x axis, at increasing positive integer coordinates x1<x2<…<xn.

For each pair (i,j) with 1≤i<j≤n, you draw the segment [xi,xj]. The segments are closed, i.e., a segment [a,b] contains the points a,a+1,…,b.

You are given q queries. In the i-th query, you are given a positive integer ki, and you have to determine how many points with integer coordinates are contained in exactly ki segments.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains two integers n, q (2≤n≤105, 1≤q≤105) — the number of points and the number of queries.

The second line of each test case contains n integers x1,x2,…,xn (1≤x1<x2<…<xn≤109) — the coordinates of the n points.

The third line of each test case contains q integers k1,k2,…,kq (1≤ki≤1018) — the parameters of the q queries.

It is guaranteed that the sum of n over all test cases does not exceed 105, and the sum of q over all test cases does not exceed 105.

Output
For each test case, output a single line with q integers: the i-th integer is the answer to the i-th query.

Example
Input
3
2 2
101 200
2 1
6 15
1 2 3 5 6 7
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
5 8
254618033 265675151 461318786 557391198 848083778
6 9 15 10 6 9 4 4294967300
Output
0 100 
0 0 0 0 2 0 0 0 3 0 2 0 0 0 0 
291716045 0 0 0 291716045 0 301749698 0 
Note
In the first example, you only draw the segment [101,200]. No point is contained in exactly 2 segments, and the 100 points 101,102,…,200 are contained in exactly 1 segment.

In the second example, you draw 15 segments: [1,2],[1,3],[1,5],[1,6],[1,7],[2,3],[2,5],[2,6],[2,7],[3,5],[3,6],[3,7],[5,6],[5,7],[6,7]. Points 1,7 are contained in exactly 5 segments; points 2,4,6 are contained in exactly 9 segments; points 3,5 are contained in exactly 11 segments.
*/

//Editorial
/*
First, let's focus on determining how many intervals contain some point x. These intervals are the ones with l≤x and x≤r.

So a point xi<p<xi+1 satisfies x1≤p,…,xi≤p, and p≤xi+1,…,p≤xn. It means that you have found xi+1−xi−1 points contained in exactly i(n−i) intervals (because there are i possible left endpoints and n−i possible right endpoints).

Similarly, the point p=xi is contained in i(n−i+1)−1 intervals (you have to remove interval [xi,xi], which you do not draw).

So you can use a map that stores how many points are contained in exactly x intervals, and update the map in the positions i(n−i) and i(n−i+1)−1.

Complexity: O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve();

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int test;
    cin>>test;
    while(test--) solve();
    return 0;
}

/**
 * Solves the "All Pairs Segments" problem from CodeForces Round 975 Div 2.
 * 
 * For each test case, the function reads in the number of points `n` and the number of queries `q`,
 * as well as the coordinates of the `n` points and the `q` query points.
 * 
 * The function then calculates the number of segments that contain each query point and outputs the
 * result for each query.
 * 
 * The time complexity of this solution is O(n log n).
 */
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n),test(q);
    map<ll,ll> hmap;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++) cin>>test[i];
    for(int i=0;i<n;i++){
        ll num=(i+1)*(n-i-1);
        if(hmap.find(num+i) == hmap.end()) hmap[num+i]=1;
        else hmap[num+i]++;
        if(hmap.find(num) == hmap.end()) hmap[num]=arr[i+1]-arr[i]-1;
        else hmap[num]+=arr[i+1]-arr[i]-1;
    }
    for(int i=0;i<q;i++){
        ll num=test[i];
        if(hmap.find(num) == hmap.end()) cout<<0<<" ";
        else cout<<hmap[num]<<" ";
    }
    cout<<endl;
}