/*
Minimum Number of Strings to Form a Target II
You are given an array of strings words and a string target.

A string x is called valid if x is a prefix of any string in words.

Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.

A prefix of a string is a substring that starts from the beginning of the string and extends to any point within it.

Example 1:

Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"

Output: 3

Explanation:

The target string can be formed by concatenating:

Prefix of length 2 of words[1], i.e. "aa".
Prefix of length 3 of words[2], i.e. "bcd".
Prefix of length 3 of words[0], i.e. "abc".
Example 2:

Input: words = ["abababab","ab"], target = "ababaababa"

Output: 2

Explanation:

The target string can be formed by concatenating:

Prefix of length 5 of words[0], i.e. "ababa".
Prefix of length 5 of words[0], i.e. "ababa".
Example 3:

Input: words = ["abcdef"], target = "xyz"

Output: -1



Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 5 * 104
The input is generated such that sum(words[i].length) <= 105.
words[i] consists only of lowercase English letters.
1 <= target.length <= 5 * 104
target consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Computes the prefix function (also known as the KMP table) for the given string `s`.
 * The prefix function is a fundamental data structure used in the Knuth-Morris-Pratt algorithm
 * for pattern matching in strings.
 *
 * The prefix function `pi[i]` represents the length of the longest proper prefix of the
 * substring `s[0:i+1]` that is also a suffix of that substring.
 *
 * @param s The input string to compute the prefix function for.
 * @return A vector containing the prefix function values for each index in the input string.
 */
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
class Solution
{

public:
    /**
     * Finds the minimum number of valid strings from the given `words` vector that can be used to construct the `target` string.
     *
     * The function first computes the prefix function (also known as the KMP table) for each word in the `words` vector, concatenated with the `target` string. It then iterates through the `target` string, finding the longest match between the current prefix of the `target` string and any of the words in `words`. If no match is found, the function returns -1 to indicate that the `target` string cannot be constructed. Otherwise, it increments the result and removes the matched portion from the `target` string.
     *
     * @param words The vector of strings that can be used to construct the `target` string.
     * @param target The target string to be constructed.
     * @return The minimum number of valid strings from `words` that can be used to construct `target`, or -1 if it is impossible.
     */
    int minValidStrings(vector<string> &words, string target)
    {
        vector<vector<int>> pis;
        for (const auto &w : words)
            pis.push_back(prefix_function(w + "#" + target));
        int len = target.size(), res = 0;
        while (len > 0)
        {
            int match = 0;
            for (int i = 0; i < words.size(); ++i)
                match = max(match, pis[i][words[i].size() + len]);
            if (match == 0)
                return -1;
            ++res;
            len -= match;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "aaaaa", "bcdef"};
    string target = "aabcdabc";
    cout << s.minValidStrings(words, target) << endl;
    return 0;
}