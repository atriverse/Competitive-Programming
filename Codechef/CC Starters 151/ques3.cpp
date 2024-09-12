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

//Solution:
/*
How it works: The solve function does the main calculation. It first combines each ball's position and speed into a pair and stores these pairs in a vector. Then it sorts this vector based on the balls' positions.

The algorithm then works backwards from the ball furthest from the hole. It calculates the time each ball would take to reach the hole if it didn't collide with any other ball. If a ball would reach the hole at the same time or earlier than the previously considered ball, it's counted as reaching the hole. This approach implicitly handles collisions, as balls that would collide are represented by the fastest one among them.

Important logic:

    -> Sorting the balls by position allows the algorithm to consider potential collisions efficiently.
    -> Working backwards from the farthest ball simplifies collision detection.
    -> The condition curr <= prev checks if the current ball reaches the hole before or at the same time as the previously considered ball.
The main function handles multiple test cases. For each test case, it reads the input data, calls the solve function, and outputs the result.
*/
#include<bits/stdc++.h>

#define ll long long
#define lld long double
using namespace std;


/**
 * Determines the number of balls that reach the hole given the initial positions and speeds of the balls.
 *
 * @param N The number of balls.
 * @param A The initial positions of the balls.
 * @param B The speeds of the balls.
 * @return The number of balls that reach the hole.
 */
int solve(int N, vector<ll>& A, vector<ll>& B) {
    vector<pair<lld,lld>> vec(N);
    for(int i=0;i<N;i++){
        vec[i].first=A[i];
        vec[i].second=B[i];
    }
    sort(vec.begin(),vec.end());
    lld prev=10e9;
    int ans=0;
    for(int i=N-1;i>=0;i--){
        lld curr=(vec[i].first/vec[i].second);
        if(curr<=prev){
            ans++;
            prev=curr;
        }
    }
    return ans;
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        cout << solve(N, A, B) << '\n';
    }
    return 0;
}
