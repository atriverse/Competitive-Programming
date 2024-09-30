/*
C. Cards Partition
time limit per test2 seconds
memory limit per test256 megabytes
DJ Genki vs Gram - Einherjar Joker
⠀
You have some cards. An integer between 1 and n is written on each card: specifically, for each i from 1 to n, you have ai cards which have the number i written on them.

There is also a shop which contains unlimited cards of each type. You have k coins, so you can buy at most k new cards in total, and the cards you buy can contain any integer between 1 and n, inclusive.

After buying the new cards, you must partition all your cards into decks, according to the following rules:

all the decks must have the same size;
there are no pairs of cards with the same value in the same deck.
Find the maximum possible size of a deck after buying cards and partitioning them optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains two integers n, k (1≤n≤2⋅105, 0≤k≤1016) — the number of distinct types of cards and the number of coins.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤1010, ∑ai≥1) — the number of cards of type i you have at the beginning, for each 1≤i≤n.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer: the maximum possible size of a deck if you operate optimally.

Example
Input
9
3 1
3 2 2
5 4
2 6 1 2 4
2 100
1410065408 10000000000
10 8
7 4 6 6 9 3 10 2 8 7
2 12
2 2
2 70
0 1
1 0
1
3 0
2 1 2
3 1
0 3 3
Output
2
3
1
7
2
2
1
1
2
Note
In the first test case, you can buy one card with the number 1, and your cards become [1,1,1,1,2,2,3,3]. You can partition them into the decks [1,2],[1,2],[1,3],[1,3]: they all have size 2, and they all contain distinct values. You can show that you cannot get a partition with decks of size greater than 2, so the answer is 2.

In the second test case, you can buy two cards with the number 1 and one card with the number 3, and your cards become [1,1,1,1,2,2,2,2,2,2,3,3,4,4,5,5,5,5], which can be partitioned into [1,2,3],[1,2,4],[1,2,5],[1,2,5],[2,3,5],[2,4,5]. You can show that you cannot get a partition with decks of size greater than 3, so the answer is 3.
*/

//Editorial

/*
Note that there are n types of cards, so the subsets have size at most n, and the answer is at most n.

If k=0, you can make subsets of size s if and only if the following conditions are true:

    -> the number of cards (m) is a multiple of s;
    -> the maximum number of cards of some type (x) is ≤m/s.

Proof:

    -> m is the number of decks times s.
    -> The number of decks is m/s. Each deck can contain at most 1 card of each type, so there are at most m/s cards of each type in total.
    -> If the two conditions above hold, you can make a deck containing the s types of cards with maximum frequency. You can show with some calculations that the conditions still hold after removing these cards. So you can prove by induction that the two conditions are sufficient to make decks of size s.

The same idea is used in problems like 1954D - Colored Balls and abc227_d - Project Planning.

For a generic k, the answer is n if you can make the number of cards of type 1,…,n equal. Otherwise, for any choice of number of cards to buy, you can buy them without changing x. It means that you need x⋅s cards in total:

if you have less than x⋅s cards, you have to check if you can reach x⋅s cards by buying at most k new cards;
if you already have x⋅s or more cards at the beginning, you have to check if you can make m a multiple of s.
Complexity: O(n)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

/**
 * Solves a problem related to partitioning cards into decks of equal size.
 * 
 * The function takes in the number of card types (n) and the maximum number of cards that can be bought (k).
 * It then reads in the number of cards of each type, calculates the total number of cards and the maximum number of cards of any type.
 * 
 * The function then finds the maximum size of the decks that can be created, given the constraints. It does this by iterating through the possible deck sizes, starting from n and going down to 1.
 * For each deck size, it checks if the total number of cards plus the maximum number of cards that can be bought is greater than or equal to the maximum number of cards of any type multiplied by the deck size.
 * If this condition is met, it calculates the minimum number of cards needed to create decks of that size, and checks if the number of cards that can be bought is enough to reach that minimum.
 * If so, it prints the deck size and breaks out of the loop.
 */
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n],sum=0,mx=0;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
        sum += a[i];
    }

    ll size = 0;

    for (ll i = n ; i >= 1 ; i--) {
        if ((sum + k) >= mx*i) {
            ll q = (sum + i - 1) / i;
            if (i * q - sum <= k) {
                cout << i << endl;
                break;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--)
    solve();
    return 0;
}