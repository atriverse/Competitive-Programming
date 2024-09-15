// ques2.cpp
/*
B1. The Strict Teacher (Easy Version)
time limit per test1.5 seconds
memory limit per test256 megabytes
This is the easy version of the problem. The only differences between the two versions are the constraints on m and q. In this version, m=2 and q=1. You can make hacks only if both versions of the problem are solved.

Narek and Tsovak were busy preparing this round, so they have not managed to do their homework and decided to steal David's homework. Their strict teacher noticed that David has no homework and now wants to punish him. She hires other teachers to help her catch David. And now m teachers together are chasing him. Luckily, the classroom is big, so David has many places to hide.

The classroom can be represented as a one-dimensional line with cells from 1 to n, inclusive.

At the start, all m teachers and David are in distinct cells. Then they make moves. During each move

David goes to an adjacent cell or stays at the current one.
Then, each of the m teachers simultaneously goes to an adjacent cell or stays at the current one.
This continues until David is caught. David is caught if any of the teachers (possibly more than one) is located in the same cell as David. Everyone sees others' moves, so they all act optimally.

Your task is to find how many moves it will take for the teachers to catch David if they all act optimally.

Acting optimally means the student makes his moves in a way that maximizes the number of moves the teachers need to catch him; and the teachers coordinate with each other to make their moves in a way that minimizes the number of moves they need to catch the student.

Also, as Narek and Tsovak think this task is easy, they decided to give you q queries on David's position. Note: this is the easy version, and you are given only one query.

Input
In the first line of the input, you are given a single integer t (1≤t≤105) — the number of test cases. The description of each test case follows.

In the first line of each test case, you are given three integers n, m, and q (3≤n≤109, m=2, q=1) — the number of cells on the line, the number of teachers, and the number of queries.

In the second line of each test case, you are given m distinct integers b1,b2,…,bm (1≤bi≤n) — the cell numbers of the teachers.

In the third line of each test case, you are given q integers a1,a2,…,aq (1≤ai≤n) — David's cell number for every query.

It is guaranteed that for any i, j such that 1≤i≤m and 1≤j≤q, bi≠aj.

Output
For each test case, output q lines, the i-th of them containing the answer of the i-th query.

Example
Input
3
10 2 1
1 4
2
8 2 1
3 6
1
8 2 1
3 6
8
Output
1
2
2
Note
In the first example, the student can just stay at cell 2. The teacher, initially located in cell 1, can reach cell 2 in one move. Therefore, the answer is 1.

In the second example, the student should just stay at cell 1. The teacher, initially located in cell 3, can reach cell 1 in two moves. Therefore, the answer is 2.

B2. The Strict Teacher (Hard Version)
time limit per test1.5 seconds
memory limit per test256 megabytes
This is the hard version of the problem. The only differences between the two versions are the constraints on m and q. In this version, m,q≤10^5. You can make hacks only if both versions of the problem are solved.
*/


// Solution:
/*
For the easy version, there are three cases and they can be considered separately.

Case 1: David is in the left of both teachers. In this case, it is obvious that he needs to go as far left as possible, which is cell 1. Then, the time needed to catch David will be b1−1.
Case 2: David is in the right of both teachers. In this case, similarly, David needs to go as far right as possible, which is cell n. Then, the time needed to catch David will be n−b2.

Case 3: David is between the two teachers. In this case, David needs to stay in the middle (if there are two middle cells, it doesn't matter which one is picked as the middle) of two teachers, so they both have to come closer to him simultaneously. So, they will need the same amount of time, which will be (b2−b1)/2. Notice, that David can always go to the middle cell not depending on his cell number.

For the hard version, the solution is the same as the easy version, but the queries and teachers are more.
For this version, there are three cases, too. Case 1 and Case 2 from the above solution are still correct, but the last one should be changed a bit because now it is important between which two consecutive teachers David is. To find that teachers, we can use binary search (after sorting b, of course). After finding that David is between teachers i and i+1, the answer is (bi+1−bi)/2, just like the easy version.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;

    while(tt--) {
        int n, m, q; cin >> n >> m >> q;

        vector<int>arr(m);
        for(auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < q; i++) {
            int x; cin >> x;
            int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int left = right - 1;

            if(right == m) {
                cout << (n - x) + (x - arr[left]) << "\n";
            }
            else if(left == -1) {
                cout << x - 1 + (arr[right] - x) << "\n";
            }
            else {
                int distL = x - arr[left], distR = arr[right] - x;
                cout << abs(distL - distR) / 2 + min(distR, distL) << "\n";
            }
        }
    }
}