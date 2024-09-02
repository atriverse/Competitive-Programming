/*
C2. Message Transmission Error (hard version)
time limit per test2 seconds
memory limit per test256 megabytes
This is a more difficult version of the problem. It differs from the easy one only by the constraints.

At the Berland State University, the local network between servers does not always operate without errors. When transmitting two identical messages consecutively, an error may occur, resulting in the two messages merging into one. In this merging, the end of the first message coincides with the beginning of the second. Of course, the merging can only occur at identical characters. The length of the merging must be a positive number less than the length of the message text.

For example, when transmitting two messages "abrakadabra" consecutively, it is possible that it will be transmitted with the described type of error, resulting in a message like "abrakadabrabrakadabra" or "abrakadabrakadabra' (in the first case, the merging occurred at one character, and in the second case, at four).

Given the received message t, determine if it is possible that this is the result of an error of the described type in the operation of the local network, and if so, determine a possible value of s.

A situation where two messages completely overlap each other should not be considered an error. For example, if the received message is "abcd", it should be considered that there is no error in it. Similarly, simply appending one message after another is not a sign of an error. For instance, if the received message is "abcabc", it should also be considered that there is no error in it.

Input
The input consists of a single non-empty string t, consisting of lowercase letters of the Latin alphabet. The length of the string t does not exceed 4·105 characters.

Output
If the message t cannot contain an error, output "NO" (without quotes) in a single line of output.

Otherwise, in the first line, output "YES" (without quotes), and in the next line, output the string s — a possible message that could have led to the error. If there are multiple possible answers, any of them is acceptable.

Examples
Input
abrakadabrabrakadabra
Output
YES
abrakadabra
*/
#include <bits/stdc++.h>
using namespace std;
 
/**
 * Determines if the given string `s` can be formed by merging two identical messages, and if so, outputs the original message.
 *
 * The function first computes the KMP next array for the input string `s`. If the length of the longest proper prefix that is also a suffix is greater than half the length of the string, then it is possible that `s` was formed by merging two identical messages. In this case, the function outputs "YES" and the substring of `s` up to the length of the longest proper prefix.
 * Otherwise, it outputs "NO" indicating that `s` cannot be formed by merging two identical messages.
 *
 * @param s The input string to be analyzed.
 * @return The original message if `s` can be formed by merging two identical messages, or "NO" otherwise.
 */
int main()
{
  string s;
  cin >> s;
 
  int n = s.size();
 
  vector<int> next(n + 1);
  next[0] = next[1] = 0;
  for (int i = 1; i < n; i++) {
    int j = next[i];
    while (j && s[j] != s[i]) j = next[j];
    if (s[j] == s[i]) j++;
    next[i + 1] = j;
  }
 
  if (next[n] * 2 > n) {
    cout << "YES" << endl << s.substr(0, next[n]) << endl;
  } else {
    cout << "NO" << endl;
  }
}