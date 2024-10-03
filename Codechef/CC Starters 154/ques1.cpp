/*
Calorie Limit
Sushil is a diabetic patient. He is only allowed to eat at most K calories in a day. However, he likes to eat sweets a lot.

There are N sweets in front of him. The i-th sweet has a calorie count of Ai.
Sushil will eat the sweets in order, i.e. he will start from the 1-st sweet, then the 2-nd, then the 3-rd, and so on.
If eating the i-th sweet would take him over his daily calorie limit, he will not eat it, and he will also not eat any further sweets 
Find the maximum number of sweets Sushil can eat without exceeding his calorie limit.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains two space-separated integers N and K — the number of sweets and the calorie limit, respectively.
The second line contains N space-separated integers — A1  ,A2 ,…,AN  .
Output Format
For each test case, output on a new line the maximum number of sweets Sushil can eat in order without exceeding his calorie limit.

Constraints

1≤T≤100
1≤N≤100
1≤Ai≤100
1≤K≤10^4
 
Sample 1:
Input
3
4 10
5 2 5 2
4 5
2 1 1 1
3 10
11 1 1
Output
2
4
0
Explanation:
Test case 1: Sushil can eat the first 2 sweets for a total calorie count of 5+2=7. If he tries to eat the 3rd sweet, he exceeds his calorie limit of 10, so he immediately stops.

Test case 3: Sushil is unable to eat the first sweet itself because it has 11 calories and he can have at most 10 calories.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Solves the "Calorie Limit" problem from CodeChef.
 * The program reads in a number of test cases, where each test case consists of:
 * - The number of sweets N and the calorie limit K
 * - The calorie counts of the N sweets
 * The program then outputs the maximum number of sweets Sushil can eat without exceeding the calorie limit.
 */
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;
            if(sum<=k){
                count++;
            }
        }
        cout<<count<<endl;
    }
}
