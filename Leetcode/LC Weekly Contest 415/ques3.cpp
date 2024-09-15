/*
Minimum Number of Strings to Form a Target I
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
1 <= words[i].length <= 5 * 103
The input is generated such that sum(words[i].length) <= 105.
words[i] consists only of lowercase English letters.
1 <= target.length <= 5 * 103
target consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Memory Limit Exceeded
class Solution
{
public:
    /**
     * Finds the minimum number of valid strings that can be concatenated to form the target string.
     *
     * @param words - A vector of strings representing the available words.
     * @param target - The target string to be formed.
     * @return The minimum number of valid strings that can be concatenated to form the target string, or -1 if it is not possible.
     */
    int minValidStrings(vector<string> &words, string target)
    {
        unordered_set<string> prefixes;
        for (const string &word : words)
        {
            for (int i = 1; i <= word.length(); ++i)
            {
                prefixes.insert(word.substr(0, i));
            }
        }

        int n = target.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (prefixes.count(target.substr(j, i - j)))
                {
                    if (dp[j] != INT_MAX)
                    {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

// Using Trie
// Time Complexity: O(n*m)
class Solution1
{
    vector<int> dp;
    int n;
    /**
     * Represents a node in a Trie data structure.
     * Each node contains an array of 26 pointers, one for each possible character in the alphabet.
     * The node is used to store and traverse through words in the Trie.
     */
    struct TrieNode
    {
        // unordered_map<char,TrieNode*>children;
        TrieNode *children[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
        }
    };

    class Trie
    {
        TrieNode *root;

    public:
        Trie()
        {
            root = new TrieNode();
        }

        /**
         * Inserts a word into the Trie data structure.
         * 
         * @param word The word to be inserted into the Trie.
         */
        void insert(string &word)
        {
            TrieNode *node = root;
            for (int i = 0; i < word.size(); i++)
            {
                char child = word[i];
                if (node->children[child - 'a'] == NULL)
                    node->children[child - 'a'] = new TrieNode();
                node = node->children[child - 'a'];
            }
        }

        /**
         * Recursively finds the minimum number of valid strings that can be formed from the given words to match the target string.
         *
         * @param idx The current index in the target string.
         * @param target The target string to match.
         * @param dp A dynamic programming array to store the results of previous computations.
         * @return The minimum number of valid strings that can be formed to match the target string.
         */
        int helper(int idx, string &target, vector<int> &dp)
        {
            if (idx == target.size())
                return 0;
            TrieNode *node = root;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 1e6;
            int i = idx;
            int n = target.size();
            while (i < n)
            {
                char child = target[i];
                if (node->children[child - 'a'] == NULL)
                    break;
                ans = min(ans, helper(i + 1, target, dp) + 1);
                node = node->children[child - 'a'];
                i++;
            }
            return dp[idx] = ans;
        }
    };

public:
    /**
     * Finds the minimum number of valid strings that can be formed from the given words to match the target string.
     *
     * @param words The vector of words that can be used to form the target string.
     * @param target The target string to match.
     * @return The minimum number of valid strings that can be formed to match the target string, or -1 if it is not possible.
     */
    int minValidStrings(vector<string> &words, string target)
    {
        n = target.size();
        Trie t;
        for (auto it : words)
            t.insert(it);
        dp = vector<int>(n, -1);
        int ans = t.helper(0, target, dp);
        if (ans >= 1e6)
            return -1;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "aaaaa", "bcdef"};
    string target = "aabcdabc";
    cout << s.minValidStrings(words, target) << endl;
    Solution1 s1;
    cout << s1.minValidStrings(words, target) << endl;
    return 0;
}