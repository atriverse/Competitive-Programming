/*
N balls are placed at distinct coordinates on the X−axis. The initial coordinate of the ith  ball is given as Ai(Ai  >0).

A hole is present at the origin. The ith   ball moves towards the hole with a speed of Bi units per second.
If multiple balls collide before reaching the hole, they merge into one ball, taking the maximum speed of the initial balls.

Determine the number of balls that will reach the hole considering all possible collisions along the way.

Note that collisions do not occur at the hole. Thus, if multiple balls reach the hole at the same time, all are counted separately.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases Each test case consists of multiple lines of input The first line of each test case contains a single integer N — the number of balls The second line contains N distinct positive integers A1  ,A2  ,…,AN   — the initial coordinates of balls The third line contains 
 N integers B1  ,B2  ,…,BN   — the speed with which the ith   ball is moving towards the hole.

Output Format
For each test case, print a single integer denoting the number of balls that reach the hole.

Constraints

1≤T≤10^4
1≤N≤2⋅10^5
1≤Ai ≤10^9 , Ai  is distinct.

1≤Bi≤10^9
 
The sum of N over all test cases does not exceed 2⋅10^5 .
Sample 1:
Input
4
2
1 4
1 2
3
1 7 5
1 3 2
4
3 4 8 12
1 2 4 5
2
1000000000 999999999
999999999 999999998
Output
2
2
3
1

Explanation:
Test case 1: The first ball reaches the hole in 1 second, and the second ball reaches in 2 seconds. Since they do not collide at any point, both balls will reach the hole separately 
Test case 2: The second and third balls collide midway. As a result, only two balls will reach the hole 
Test case 3: The first and second balls collide midway. After this, no further collisions occur. Thus, three balls reach the hole.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> ar(n), br(n);
    for(ll i=0; i<n; i++) cin >> ar[i];
    for(ll i=0; i<n; i++) cin >> br[i];
    vector<pair<ll,ll>> vp(n);
    for(ll i=0; i<n; i++){
        vp[i] = {ar[i], br[i]};
    }
    sort(vp.begin(), vp.end());
    stack<ll> st;
    for(ll i=0; i<n; i++){
        // ar[i] / br[i]
        // ar[i] / br[i]
        // ar[i] / br[i] > ar[i] / br[i]
        while(!st.empty() && (vp[st.top()].first * vp[i].second) > (vp[i].first * vp[st.top()].second)) st.pop();
        st.push(i);
    }
    cout << st.size() << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
    return 0;
}