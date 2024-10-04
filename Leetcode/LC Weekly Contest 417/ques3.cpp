/*
You are given a string word and a non-negative integer k.

Return the total number of
substrings
 of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.



Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".


Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/

#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
public:
    /**
     * Counts the number of substrings in the given word that contain all vowels and at most k consonants.
     *
     * @param word The input word to search for substrings.
     * @param k The maximum number of consonants allowed in the substrings.
     * @return The count of valid substrings.
     */
    int countOfSubstrings(string word, int k)
    {
        int n = word.length();
        int result = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i)
        {
            unordered_map<char, int> vowel_count;
            int consonant_count = 0;

            for (int j = i; j < n; ++j)
            {
                if (vowels.count(word[j]))
                {
                    vowel_count[word[j]]++;
                }
                else
                {
                    consonant_count++;
                    if (consonant_count > k)
                        break;
                }

                if (consonant_count == k && vowel_count.size() == 5)
                {
                    bool all_vowels_present = true;
                    for (char v : vowels)
                    {
                        if (vowel_count[v] == 0)
                        {
                            all_vowels_present = false;
                            break;
                        }
                    }
                    if (all_vowels_present)
                        result++;
                }
            }
        }

        return result;
    }
};

// Optimized solution
/*
Intuition
The problem naturally lends itself to a sliding window approach because we're dealing with substrings, which are contiguous segments of the original string. However, this problem requires some modifications to the general sliding window technique:
    -> We need to keep track of two conditions simultaneously: the presence of all vowels and the count of consonants.
    -> The valid window can extend beyond the point where we find a valid substring, as adding more characters to the right might create more valid substrings. The right can extend before the point where the next consonent found(this will alter the condition of k consonents).
    -> The efficiency of this solution hinges on a crucial insight: we don't need to explicitly extend our window to the right to count all valid substrings starting at the left pointer. Instead, we use precalculation to achieve this in constant time.
*/
class Solution1
{
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k)
    {
        int n = word.size();
        unordered_map<char, int> vowels;
        int consonantCount = 0;
        long long result = 0;

        // Precompute next consonant positions
        vector<int> nextConsonant(n);
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--)
        {
            nextConsonant[i] = lastConsonant;
            if (!isVowel(word[i]))
                lastConsonant = i;
        }

        // Sliding window
        int left = 0, right = 0;
        while (right < n)
        {
            // Expand window
            if (isVowel(word[right]))
            {
                vowels[word[right]]++;
            }
            else
            {
                consonantCount++;
            }

            // Shrink window if too many consonants
            while (left <= right && consonantCount > k)
            {
                if (isVowel(word[left]))
                {
                    if (--vowels[word[left]] == 0)
                        vowels.erase(word[left]);
                }
                else
                {
                    consonantCount--;
                }
                left++;
            }

            // Count valid substrings
            while (left < right && vowels.size() == 5 && consonantCount == k)
            {
                result += (nextConsonant[right] - right);
                if (isVowel(word[left]))
                {
                    if (--vowels[word[left]] == 0)
                        vowels.erase(word[left]);
                }
                else
                {
                    consonantCount--;
                }
                left++;
            }

            right++;
        }

        return result;
    }
};

int main()
{
    string word;
    int k;
    cin >> word >> k;
    Solution sol;
    cout << sol.countOfSubstrings(word, k) << endl;
    Solution1 sol1;
    cout << sol1.countOfSubstrings(word, k) << endl;
    return 0;
}