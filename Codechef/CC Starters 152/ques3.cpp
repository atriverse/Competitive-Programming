/*
Maximize Hamming Distance
You are given M strings, each of length N. The i-th string is called Si.
The strings contain only the characters 0, 1, or ?.

You must replace every ? with either a 0 or a 1, hence obtaining M binary strings.
If you perform these replacements optimally, find the maximum possible sum of Hamming distances between each pair of strings.

Formally, your aim is to maximize
        ∑i=1toM∑j=i+1toMf(Si,Sj)
where f(Si,Sj) denotes the Hamming distance between strings Si and Sj.

The Hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.
For example, the Hamming distance between 1001 and 0011 is 2, since they differ at the first and third characters.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers N and M — the length of the strings and the number of strings, respectively.
The next M lines contains the strings each of length N.
Output Format
For each test case, output on a new line the maximum sum of Hamming distances between each pair of strings that can be obtained.

Constraints
1≤T≤10^5
1≤N≤1.5⋅10^5
2≤M≤3⋅10^5
 
The sum of N×M over all test cases won't exceed 3⋅10^5  .
The strings contain only 0, 1, or ?.
Sample 1:
Input
4
2 2
?1
0?
3 3
001
???
011
5 3
10001
00000
00000
4 2
001?
00??

Output
2
6
4
2

Explanation:
Test case 1: Consider the following operations:

Replace the ? from the string ?1 with 1 giving us 11.
Replace the ? from the string 0? with 0 giving us 00.
We can now calculate the sum of hamming distances of all pairs as:

Hamming distance between 00 and 11 = 2
The total sum is 2 which is the maximum possible.

Test case 2: Consider the following operations:

Replace the first, second and third ? from the string ??? with 1,1 and 0 respectively, giving us 110.
We can now calculate the sum of hamming distances of all pairs as:

Hamming distance between 001 and 110 = 3
Hamming distance between 001 and 011 =1
Hamming distance between 110 and 011 = 2
The total sum is 3+1+2=6 which is the maximum possible.

Test case 3: The strings do not contain any ? so no replacements are required

We can now calculate the sum of hamming distances of all pairs as:

Hamming distance between 10001 and 00000 = 2
Hamming distance between 10001 and 00000 = 2
Hamming distance between 00000 and 00000 = 0
The total sum is 2+2+0=4 which is the maximum possible.

Test case 4: We can replace the ? to make the first string 0010 and the second string 0001 The Hamming distance between 0010 and 0001 is 2.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Solves a test case by calculating the maximum possible sum of Hamming distances between all pairs of strings.
 *
 * The function takes in the number of strings (N) and the length of each string (M), and the strings themselves.
 * It then calculates the maximum possible sum of Hamming distances between all pairs of strings by iterating through each position in the strings and determining the maximum and minimum counts of 0s and 1s, taking into account any '?' characters that can be replaced.
 *
 * @param N the number of strings
 * @param M the length of each string
 * @param strings the input strings
 * @return the maximum possible sum of Hamming distances between all pairs of strings
 */
long long solveTestCase() {
    int N, M;
    cin >> N >> M;

    vector<string> strings(M);
    for (int i = 0; i < M; i++) {
        cin >> strings[i];
    }

    long long totalHammingDistance = 0;

    for (int j = 0; j < N; j++) {
        int count0 = 0, count1 = 0, countQ = 0;

        for (int i = 0; i < M; i++) {
            if (strings[i][j] == '0') count0++;
            else if (strings[i][j] == '1') count1++;
            else countQ++;
        }

        int max_count = max(count0, count1);
        int min_count = min(count0, count1);

        /**
         * Handles the case where there are '?' characters in the input strings.
         * If the maximum count of 0s or 1s is greater than or equal to half the length of the strings,
         * then the minimum count is incremented by the number of '?' characters.
         * Otherwise, the maximum count is incremented by the '?' characters up to half the length of the strings,
         * and the minimum count is incremented by the remaining '?' characters.
         */
        if (countQ > 0) {
            if (max_count >= (M / 2)) {
                min_count += countQ;
            } else {
                int half = (M + 1) / 2;
                if (max_count + countQ <= half) {
                    max_count += countQ;
                } else {
                    min_count += (max_count + countQ) - half;
                    max_count = half;
                }
            }
        }

        totalHammingDistance += (long long)max_count * min_count;
    }

    return totalHammingDistance;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long result = solveTestCase();
        cout << result << endl;
    }

    return 0;
}