/*
Report Spam message
You are given an array of strings message and an array of strings bannedWords.

An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.

Return true if the array message is spam, and false otherwise.

Example 1:

Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]

Output: true

Explanation:

The words "hello" and "world" from the message array both appear in the bannedWords array.

Example 2:

Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]

Output: false

Explanation:

Only one word from the message array ("programming") appears in the bannedWords array.

Constraints:

1 <= message.length, bannedWords.length <= 105
1 <= message[i].length, bannedWords[i].length <= 15
message[i] and bannedWords[i] consist only of lowercase English letters.
*/


// Solution:
/*
The reportSpam method takes two inputs: a vector of strings called 'message' (which represents the words in the message) and another vector of strings called 'bannedWords' (which contains the list of words that are not allowed).

The output of this method is a boolean value: true if the message is considered spam, and false if it's not.

To achieve its purpose, the code first creates a set (called bannedSet) from the bannedWords vector. This allows for faster lookup of banned words. Then, it goes through each word in the message and checks if it's in the bannedSet. If a match is found, it increments a counter (matchCount). As soon as this counter reaches 2, the method immediately returns true, indicating that the message is spam. If the method goes through all words without finding two matches, it returns false.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Checks if the given message array contains at least two words that are in the banned words array.
     *
     * @param message The array of strings representing the message.
     * @param bannedWords The array of strings representing the banned words.
     * @return True if the message is considered spam, false otherwise.
     */
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
        int matchCount = 0;

        for (const auto& word : message) {
            if (bannedSet.find(word) != bannedSet.end()) {
                matchCount++;
                if (matchCount >= 2) {
                    return true;
                }
            }
        }

        return false;

    }
};

int main() {
    Solution solution;
    /// Example 1
    vector<string> message = {"hello", "world", "leetcode"};
    vector<string> bannedWords = {"world", "hello"};

    bool result = solution.reportSpam(message, bannedWords);
    cout << "Example 1 Output: " << (result ? "true" : "false") << endl;

    /// Example 2
    message = {"hello", "programming", "fun"};
    bannedWords = {"world", "programming", "leetcode"};

    result = solution.reportSpam(message, bannedWords);
    cout << "Example 2 Output: " << (result ? "true" : "false") << endl;
    return 0;
}