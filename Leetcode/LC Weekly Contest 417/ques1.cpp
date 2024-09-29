/*
Find the k-th character in String Game I
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.



Example 1:

Input: k = 5

Output: "b"

Explanation:

Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".
Example 2:

Input: k = 10

Output: "c"



Constraints:

1 <= k <= 500
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Finds the k-th character in the string game.
     *
     * The game starts with the string "a" and repeatedly generates a new string by changing each character to the next character in the English alphabet and appending it to the original string. This process is repeated until the string has at least k characters.
     *
     * @param k The index of the character to return, where 1 <= k <= 500.
     * @return The k-th character in the final string.
     */
    char kthCharacter(int k)
    {
        if (k == 1)
            return 'a';

        int length = 1;
        int operations = 0;

        while (length < k)
        {
            operations++;
            length *= 2;
        }

        return findChar(operations, k);
    }

private:
    /**
     * Recursively finds the character at the k-th position in the string game.
     *
     * The game starts with the string "a" and repeatedly generates a new string by changing each character to the next character in the English alphabet and appending it to the original string. This process is repeated until the string has at least k characters.
     *
     * @param n The current recursion depth, where 0 represents the base case.
     * @param k The index of the character to return, where 1 <= k <= 500.
     * @return The character at the k-th position in the final string.
     */
    char findChar(int n, int k)
    {
        if (n == 0)
            return 'a';

        int prevLength = 1 << (n - 1);
        if (k <= prevLength)
        {
            return findChar(n - 1, k);
        }
        else
        {
            char prevChar = findChar(n - 1, k - prevLength);
            return (prevChar == 'z') ? 'a' : prevChar + 1;
        }
    }
};

int main()
{
    int k;
    cin >> k;
    Solution obj;
    cout << obj.kthCharacter(k);
    return 0;
}