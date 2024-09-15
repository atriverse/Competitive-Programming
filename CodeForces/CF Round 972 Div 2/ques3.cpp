/*
C. Lazy Narek
time limit per test2 seconds
memory limit per test256 megabytes
Narek is too lazy to create the third problem of this contest. His friend Artur suggests that he should use ChatGPT. ChatGPT creates n problems, each consisting of m letters, so Narek has n strings. To make the problem harder, he combines the problems by selecting some of the n strings possibly none and concatenating them without altering their order. His chance of solving the problem is defined as scoren−scorec, where scoren is Narek's score and scorec is ChatGPT's score.

Narek calculates scoren by examining the selected string (he moves from left to right). He initially searches for the letter "n", followed by "a", "r", "e", and "k". Upon finding all occurrences of these letters, he increments scoren by 5 and resumes searching for "n" again (he doesn't go back, and he just continues from where he left off).

After Narek finishes, ChatGPT scans through the array and increments scorec by 1 for each letter "n", "a", "r", "e", or "k" that Narek fails to utilize (note that if Narek fails to complete the last occurrence by finding all of the 5 letters, then all of the letters he used are counted in ChatGPT's score scorec, and Narek doesn't get any points if he doesn't finish finding all the 5 letters).

Narek aims to maximize the value of scoren−scorec by selecting the most optimal subset of the initial strings.

Input
In the first line of the input, you're given a single integer t (1≤t≤105), the number of test cases. Then the description of each test case follows.

In the first line of each test case, you're given two integers n,m (1≤n,m≤103), the number of strings and the length of each string.

In the next n lines, you're given n strings, each having a length of m. The strings only contain lowercase letters of the English alphabet.

The sum of values of n⋅m over all test cases does not exceed 106.

Output
For each test case, output a single integer: the maximal possible value of scoren−scorec.

Example
Input
4
5 2
nn
aa
rr
ee
kk
1 5
narek
1 4
nare
5 7
nrrarek
nrnekan
uuuuuuu
ppppppp
nkarekz
Output
0
5
0
7
Note
In the first test case, one of the optimal answers is when Narek doesn't choose any of the strings, so the answer is 0. He can alternatively choose all the strings. In this case, the full string becomes "nnaarreekk". Narek can choose the first appearances of all letters and add 5 to the score. His opponent will add 1 for all second appearances, which will be 5 in total. So the answer will be 5−5=0.

In the third test case, the only optimal answer is when Narek doesn't choose the string. Note that if he were to choose the string, he wouldn't be able to find the last letter "k", so his score would stay at 0 instead of becoming 5. Then ChatGPT would add 4 for all of the 4 letters, and the answer would become 0−4=−4.

In the last test case, Narek needs to choose the first and the last strings. After putting these two next to each other, he gets "nrrareknkarekz". Narek can choose the letters marked with red and add 10 to his score. Since the black colored letters Narek left behind are eligible for the opponent to claim (they are used in the word "narek"), the opponent adds all other letters to the score and gets a score of 3. Therefore, the answer is 10−3=7.
*/


//Solution and Explanation
/*
Let's loop through the n strings and define dpi as the maximal answer if we are currently looking for the i-th letter in the word "Narek". Initially, dp0=0, and dp1=⋯=dp4=−∞. For the current string, we brute force on all five letters we could have previously ended on. Let’s say the current letter is the j-th, where 0≤j<5. If dpj is not −∞, we can replicate the process of choosing this string for our subset and count the score difference (the answer). Eventually, we will reach to some k-th letter in the word "Narek". If reaching dpk from dpj is bigger than the previous value of dpk, we update dpk by dpj+counted_score.

Finally, the answer is dpi−2⋅i. This is because if i is not 0, then we didn’t fully complete the entire word (the problem states that in this case, these letters are counted in the GPT’s score, so we subtract this from our score and add it to the GPT’s).
Note: Updating the array dp is incorrect, because we may update some dpi for some string, and then use that updated dpi for that same string. To avoid this, we can use two arrays and overwrite one to the other for each string.
Time complexity: O(n∗m∗5) or O(n∗m∗25), depending on the implementation.
*/
#include <bits/stdc++.h>
using namespace std;

const string narek = "narek";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; // test cases

	while (t--) {
		int n, m; cin >> n >> m;

		vector<string> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];

		vector<int> dp(5, int(-1e9)), ndp;
		dp[0] = 0;

		for (int i = 0; i < n; i++) {
			ndp = dp; // overwriting dp

			for (int j = 0; j < 5; j++) {
				if (dp[j] == int(-1e9)) continue;

				int counted_score = 0, next = j;

				for (int k = 0; k < m; k++) {
					int ind = narek.find(s[i][k]);

					if (ind == -1) continue; // if s[i][k] is not a letter of "narek"

					if (next == ind) { // if s[i][k] is the next letter
						next = (next + 1) % 5;
						counted_score++;
					}
					else counted_score--;
				}

				ndp[next] = max(ndp[next], dp[j] + counted_score);
			}

			dp = ndp; // overwriting dp back
		}

		int ans = 0;
		for (int i = 0; i < 5; i++) ans = max(ans, dp[i] - 2 * i); // checking all letters

		cout << ans << "\n";
	}
}