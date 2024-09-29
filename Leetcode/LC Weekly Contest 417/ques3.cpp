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
class Solution {
public:
    /**
     * Counts the number of substrings in the given word that contain all vowels and at most k consonants.
     *
     * @param word The input word to search for substrings.
     * @param k The maximum number of consonants allowed in the substrings.
     * @return The count of valid substrings.
     */
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int result = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> vowel_count;
            int consonant_count = 0;
            
            for (int j = i; j < n; ++j) {
                if (vowels.count(word[j])) {
                    vowel_count[word[j]]++;
                } else {
                    consonant_count++;
                    if (consonant_count > k) break;
                }
                
                if (consonant_count == k && vowel_count.size() == 5) {
                    bool all_vowels_present = true;
                    for (char v : vowels) {
                        if (vowel_count[v] == 0) {
                            all_vowels_present = false;
                            break;
                        }
                    }
                    if (all_vowels_present) result++;
                }
            }
        }
        
        return result;
    }
};

int main(){
    string word;
    int k;
    cin>>word>>k;
    Solution sol;
    cout<<sol.countOfSubstrings(word,k);
    return 0;
}