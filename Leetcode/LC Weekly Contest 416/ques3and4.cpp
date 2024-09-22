/*
Question 3 and 4 are same except the time complexity.
Count substrings that can be rearranged to contain a string I
You are given two strings word1 and word2.

A string x is called valid if x can be rearranged to have word2 as a
prefix
.

Return the total number of valid
substrings
 of word1.



Example 1:

Input: word1 = "bcca", word2 = "abc"

Output: 1

Explanation:

The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.

Example 2:

Input: word1 = "abcabc", word2 = "abc"

Output: 10

Explanation:

All the substrings except substrings of size 1 and size 2 are valid.

Example 3:

Input: word1 = "abcabc", word2 = "aaabc"

Output: 0



Constraints: Question 3: Could be solved in O(nlog(n)) or similar time complexity.

1 <= word1.length <= 105
1 <= word2.length <= 104
word1 and word2 consist only of lowercase English letters.

Constraints: Question 4: Needed to be solved in O(n) time complexity.

1 <= word1.length <= 106
1 <= word2.length <= 104
word1 and word2 consist only of lowercase English letters.
*/


//Sollution:
/*
Purpose: This code counts how many substrings of a given string (word1) can be rearranged to have another string (word2) as a prefix. A substring is considered valid if it contains all the characters needed to form word2 at the beginning, with the rest of the characters in any order.

Inputs: The code takes two inputs: word1 (the main string) and word2 (the prefix string we're looking for).

Outputs: It returns a single number, which is the count of valid substrings found in word1.

How it works: The code uses a technique called the "sliding window" approach. It moves through word1, keeping track of the characters it sees in a window. As it goes, it checks if the current window has enough of the right characters to form word2 at the start.

Here's the step-by-step process:

    -> It first counts how many of each letter are in word2.
    -> Then it starts moving through word1, expanding a window from left to right.
    -> For each character it adds to the window, it updates a count of the letters seen so far.
    -> When the window contains all the letters needed for word2, it starts counting valid substrings.
    -> It then shrinks the window from the left side, continuing to count valid substrings until it no longer has enough letters for word2.
    -> This process repeats until the end of word1 is reached.

Important logic: The key idea is that once we have a valid window (containing all letters for word2), all substrings from that point to the end of word1 are also valid. This allows the code to count multiple valid substrings at once, making it efficient.

The code uses arrays to keep track of letter frequencies, which allows for quick checking of whether the current window matches the requirements for word2. It also uses variables to track how many unique letters need to be matched and how many have been matched so far.

This solution is designed to be efficient, running in linear time relative to the length of word1, which makes it suitable for handling large input strings quickly.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Counts the number of valid substrings of `word1` that have `word2` as a prefix.
     *
     * A valid substring is a substring of `word1` that can be rearranged to have `word2` as a prefix.
     *
     * @param word1 The input string.
     * @param word2 The prefix string.
     * @return The count of valid substrings.
     */
    long long validSubstringCount(string word1, string word2)
    {
        long long n = word1.length();
        long long m = word2.length();
        long long count = 0;

        /**
         * Counts the frequency of each character in the `word2` string.
         * This information is used later to determine if a substring of `word1` can be rearranged to have `word2` as a prefix.
         *
         * @param word2 The prefix string to match against.
         * @return A vector of length 26, where each element represents the frequency of the corresponding lowercase letter in `word2`.
         */
        vector<long long> word2_freq(26, 0);
        for (char c : word2)
        {
            word2_freq[c - 'a']++;
        }

        vector<long long> window_freq(26, 0);
        long long left = 0, right = 0;
        long long chars_to_match = 0;

        /**
         * Counts the number of unique characters in `word2` that need to be matched in a valid substring of `word1`.
         *
         * This is used to keep track of how many unique characters from `word2` need to be present in a substring of `word1` for it to be considered valid.
         */
        for (int i = 0; i < 26; i++)
        {
            if (word2_freq[i] > 0)
                chars_to_match++;
        }

        long long matched = 0;

        /**
         * Counts the number of valid substrings of `word1` that have `word2` as a prefix.
         *
         * This part of the code maintains a sliding window over `word1` and keeps track of the number of unique characters from `word2` that have been matched so far. It then calculates the number of valid substrings by counting the number of substrings that start at the current right pointer and end at any position to the right.
         *
         * @param word1 The input string.
         * @param word2 The prefix string.
         * @param n The length of `word1`.
         * @param m The length of `word2`.
         * @param word2_freq The frequency of each character in `word2`.
         * @param window_freq The frequency of each character in the current window of `word1`.
         * @param chars_to_match The number of unique characters in `word2` that need to be matched.
         * @param matched The number of unique characters from `word2` that have been matched so far.
         * @param count The total number of valid substrings found.
         * @param left The left pointer of the current window.
         * @param right The right pointer of the current window.
         * @return The count of valid substrings.
         */
        while (right < n)
        {
            window_freq[word1[right] - 'a']++;
            if (window_freq[word1[right] - 'a'] == word2_freq[word1[right] - 'a'])
            {
                matched++;
            }

            while (matched == chars_to_match && left <= right)
            {
                count += n - right;

                window_freq[word1[left] - 'a']--;
                if (window_freq[word1[left] - 'a'] < word2_freq[word1[left] - 'a'])
                {
                    matched--;
                }
                left++;
            }

            right++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    // Example 1
    cout << s.validSubstringCount("bcca", "abc") << endl;

    // Example 2
    cout << s.validSubstringCount("abcabc", "abc") << endl;

    // Example 3
    cout << s.validSubstringCount("abcabc", "aaabc") << endl;

    return 0;
}