/*
Add 1 or 2 Game
Alice and Bob play a game.
There is an integer X, which is initially 0. On their turn, Alice or Bob can choose to increment X by either 1 or 2.

The game ends as soon as X≥N holds. When the game ends, Bob wins the game if X=N, otherwise Alice wins the game.
Alice goes first, and the players alternate turns.
If both players play optimally, predict the winner.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
The first and only line of each test case contains a single integer N — the limit for the game.
Output Format
For each test case, output on a new line the name of the winner: the string "ALICE" if Alice wins the game, and "BOB" if Bob wins the game (without the quotes).

Each character of the output may be printed in either uppercase or lowercase, i.e, the strings Bob, BOB, bOb, and bOB will all be treated as equivalent.

Constraints
1≤T≤10
1≤N≤10
Sample 1:
Input
2
1
3
Output
ALICE
BOB
Explanation:
Test case 1: Alice can simply increase X by 2 on the first move. Then, the game ends since X≥N, and Alice wins because X!=N holds (N=1).

Test case 2: Bob has a simple strategy that guarantees a win:
If Alice does +2, Bob does +1, thus making X= 3
If Alice does +1, Bob does +2, thus making X= 3
In both cases, the game ends after the 2 turns, and Bob wins as X=N=3 holds.
*/

//Explanation:
/*
Alice can win if Alice is at N-1 which implies that Bob was at N-2 or Bob is at N-3.
Therefore, Bob could have added 2 if he is at N-2 or Bob could have added 1 if he is at N-3. In both cases Bob wins.
Therefore, Alice can win only if N==1, for all other cases Bob wins.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Determines the winner of the "Add 1 or 2 Game" given the target value N.
 * 
 * If N is 1, Alice wins the game. Otherwise, Bob wins the game.
 * 
 * @param N The target value for the game.
 * @return The name of the winner ("ALICE" or "BOB").
 */
string solve(int N) {
    if(N==1)return "ALICE";
    return "BOB";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}