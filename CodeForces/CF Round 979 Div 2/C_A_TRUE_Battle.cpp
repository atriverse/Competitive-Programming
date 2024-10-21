/*
C. A TRUE Battle
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob are playing a game. There is a list of n booleans, each of which is either true or false, given as a binary string ∗ of length n (where 1 represents true, and 0 represents false). Initially, there are no operators between the booleans.

Alice and Bob will take alternate turns placing and or or between the booleans, with Alice going first. Thus, the game will consist of n−1 turns since there are n booleans. Alice aims for the final statement to evaluate to true, while Bob aims for it to evaluate to false. Given the list of boolean values, determine whether Alice will win if both players play optimally.

To evaluate the final expression, repeatedly perform the following steps until the statement consists of a single true or false:

If the statement contains an and operator, choose any one and replace the subexpression surrounding it with its evaluation.
Otherwise, the statement contains an or operator. Choose any one and replace the subexpression surrounding the or with its evaluation.
For example, the expression true or false and false is evaluated as true or (false and false) = true or false = true. It can be shown that the result of any compound statement is unique.
∗
A binary string is a string that only consists of characters 0 and 1

Input
The first line contains t (1≤t≤104) — the number of test cases.

The first line of each test case contains an integer n (2≤n≤2⋅105) — the length of the string.

The second line contains a binary string of length n, consisting of characters 0 and 1 — the list of boolean values.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each testcase, output "YES" (without quotes) if Alice wins, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and "Yes" will be recognized as a positive response).

Example
Input
5
2
11
3
010
12
101111111100
10
0111111011
8
01000010
Output
YES
NO
YES
YES
NO
Note
In the first testcase, Alice can place and between the two booleans. The game ends as there are no other places to place operators, and Alice wins because true and true is true.

In the second testcase, Alice can place or between the middle true and the left false. Bob can place and between the middle true and the right false. The statement false or true and false is false.

Note that these examples may not be the best strategies for either Alice or Bob.
*/

//Editorial
/*
Let's understand what Alice wants to do. She wants to separate a statement that evaluates to true between two or's. This guarantees her victory since or is evaluated after all and's.

First, if the first or last boolean is true, then Alice instantly wins by placing or between the first and second, or second to last and last booleans.

Otherwise, if there are two true's consecutively, Alice can also win. Alice may place or before the first of the two on her first move. If Bob does not put his operator between the two true's, then Alice will put an or between the two true's on her next move and win. Otherwise, Bob does place his operator between the two true's. However, no matter what Bob placed, the two true's will always evaluate to true, so on her second move Alice can just place an or on the other side of the two true's to win.

We claim these are the only two cases where Alice wins. This is because otherwise, there does not contain two true's consecutively. Now, whenever Alice places an or adjacent to a true, Bob will respond by placing and after the true, which will invalidate this clause to be false.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void aliceWins(const string& booleans) {
    int n = booleans.size();
    int aliceWins = 0;
    for (int i = 0; i < n; i++)
    {
        if (booleans[i] == '1')
        {
            if (i==0 || i==n-1 || (i>0 && booleans[i-1] == '1') || (i<n-1 && booleans[i+1] == '1'))
            {
                aliceWins=1;
                break;
            }
            
        }
        
    }
    string ans=(aliceWins)?"YES":"NO";
    cout<<ans<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string booleans;
        cin >> booleans;

        aliceWins(booleans);
    }

    return 0;
}
