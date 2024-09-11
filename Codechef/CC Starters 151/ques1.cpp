/*
International Gym Day
On the account of International Gym Day, Chefland gym has a special discount offer for a lifetime membership.

Chef is taking trial sessions at the gym where he pays 1 coin per session. For every trial session Chef takes, he is eligible for an additional D % discount while taking the lifetime membership.

Given that the membership costs X coins and Chef has a total budget of Y coins, find the minimum number of trial sessions he needs to take so that he can purchase the lifetime membership If it is impossible for him to get the lifetime membership, print −1 instead.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases Each test case consists of three space-separated integers D,X, and Y — the additional discount Chef gets by attending one trial session, the cost of lifetime membership, and Chef's budget respectively Output Forma For each test case, output on a new line, the minimum number of trial sessions Chef needs to take so that he can purchase the lifetime membership 
If it is impossible for him to get the lifetime membership, print −1 instead 
Constraints

1≤T≤6400

1≤D≤5

1≤Y≤X≤50
Sample 1:
Input
3
2 2 2
5 40 38
3 26 15
Output
0
2
-1
Explanation:
Test case 1: Lifetime membership costs 2 coins and Chef already has 2 coins. Thus he does not need to attend any trial sessions.

Test case 2: Lifetime membership costs 40 coins and Chef has 38 coins.


If he takes 1 trial session, he is left with 38−1=37 coins, and gets a 5% discount on membership. The membership price would become 40⋅95/100 =38. Chef still does not has enough coins.
If he takes 

2 trial sessions, he is left with 38−2=36 coins, and gets a 10 % discount on membership. The membership price would become 40⋅90/100=36 Chef can now purchase the membership.
Thus, Chef needs to take a minimum of two trial sessions.

Test case 3: It can be shown that Chef cannot purchase the membership, no matter how many trial sessions he takes.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int d, int x, int y) {
    int count = 0;
    double xf = x; // Use double for better precision
    int yf=y;
    while (yf > 0) {
        if (xf <= (y-count)) {
            return count;
        }
        count += 1;
        xf =xf*( (100.0 - (count*d))) / 100.0;
        
        if (xf <= (y-count)) {
            return count;
        }
        yf-=1;
        xf=x;
    }
    return -1;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int d,x,y;
        cin>>d>>x>>y;
        cout<<solve(d,x,y)<<endl;
    }
}
