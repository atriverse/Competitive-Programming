/*
Intuition
The goal is to maximize the total score when jumping from the start (index 0) to the end (index n-1) of the array. The score for a jump from index i to index j is given by (j - i) * nums[i]. To maximize the total score, we should consider leveraging the highest values in the nums array, especially when making larger jumps. The challenge is to find an efficient way to calculate the maximum possible score without needing to evaluate every possible jump explicitly.

Approach
    1. Understanding the Score Calculation:

        The score for jumping from index i to j is (j - i) * nums[i]. Therefore, the score is influenced by the difference between indices (j - i) and the value at the starting index nums[i].
    2. Optimal Strategy:

        The optimal score can be achieved by:
            Keeping Track of Maximum Values: As you traverse the array, maintain the maximum value seen so far. This helps in determining the best possible score from the current index to the end of the array.
            Accumulate Scores: For each index i, compute the potential score if you were to jump directly to the end of the array from that index using the maximum value seen so far. Accumulate these scores to find the maximum possible score.
    3. Algorithm Steps:

        Initialize two variables: max to keep track of the maximum value seen so far, and sum to accumulate the total score.
        Iterate through the array from the beginning to the second-last element:
            Update the max value with the current element if it’s greater.
            Compute the score for jumping from the current index to the end using the max value and add this score to sum.
    Return the accumulated sum which represents the maximum possible score.
Complexity
    Time complexity:
        The solution involves a single pass through the array to update the maximum value and accumulate the score. Therefore, the time complexity is ( O(n) ), where ( n ) is the length of the nums array.
    Space complexity:
        The solution uses a constant amount of extra space for the variables max and sum, regardless of the input size. Therefore, the space complexity is (O(1)).
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum possible score that can be obtained by jumping from the start (index 0) to the end (index n-1) of the given array `nums`.
     *
     * The score for a jump from index `i` to index `j` is calculated as `(j - i) * nums[i]`. The goal is to maximize the total score by leveraging the highest values in the `nums` array.
     *
     * This implementation maintains the maximum value seen so far (`max`) and accumulates the scores for jumping from each index to the end of the array (`sum`). The final `sum` represents the maximum possible score.
     *
     * @param nums The input array of integers.
     * @return The maximum possible score that can be obtained.
     */
    long long findMaximumScore(vector<int>& nums) {
        long max = 0, sum = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            max = std::max(max, static_cast<long>(nums[i]));
            sum += max;
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,3,1,5};
    cout << s.findMaximumScore(nums) << endl;
    return 0;
}