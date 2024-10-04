/*
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.



Example 1:

Input: k = 5, operations = [0,0,0]

Output: "a"

Explanation:

Initially, word == "a". Alice performs the three operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "aa" to "aa", word becomes "aaaa".
Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
Example 2:

Input: k = 10, operations = [0,1,0,1]

Output: "b"

Explanation:

Initially, word == "a". Alice performs the four operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "bb" to "aa", word becomes "aabb".
Appends "aabb" to "aabb", word becomes "aabbaabb".
Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".


Constraints:

1 <= k <= 1014
1 <= operations.length <= 100
operations[i] is either 0 or 1.
The input is generated such that word has at least k characters after all operations.
*/
#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
public:
    /**
     * Finds the kth character in the final string after performing the given operations.
     *
     * @param k The index of the character to return, 1-indexed.
     * @param operations A vector of operations to perform on the initial string "a".
     * @return The kth character in the final string.
     */
    char kthCharacter(long long k, vector<int> &operations)
    {
        string word = "a";

        for (int op : operations)
        {
            if (op == 0)
            {
                word += word;
            }
            else if (op == 1)
            {
                string newPart = "";
                for (char c : word)
                {
                    newPart += (c == 'z') ? 'a' : (char)(c + 1);
                }
                word += newPart;
            }

            if (word.length() >= k)
            {
                break;
            }
        }

        return word[k - 1];
    }
};


//Optimized solution
class Solution1
{
public:
    /**
     * Finds the kth character in the final string after performing the given operations.
     *
     * This recursive function takes the index of the character to return (1-indexed) and the vector of operations to perform on the initial string "a". It determines the type of the current operation (0 or 1) and calculates the next index to check based on the length of the current string. It then recursively calls itself with the updated index and returns the appropriate character.
     *
     * @param k The index of the character to return, 1-indexed.
     * @param op A vector of operations to perform on the initial string "a".
     * @return The kth character in the final string.
     */
    char kthCharacter(long long k, vector<int> &op)
    {
        if (k == 1)
            return 'a';
        int n = op.size(), type;
        long long len = 1, nextK;
        for (int i = 0; i < n; i++)
        {
            len *= 2;
            if (len >= k)
            {
                type = op[i];
                nextK = k - len / 2;
                break;
            }
        }
        char res = kthCharacter(nextK, op);
        if (type == 0)
            return res;
        if (res == 'z')
            return 'a';
        return res + 1;
    }
};
int main()
{
    Solution s;
    vector<int> operations = {0, 0, 0};
    cout << s.kthCharacter(5, operations) << endl;

    Solution1 s1;
    cout << s1.kthCharacter(5, operations) << endl;
    return 0;
}