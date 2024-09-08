/*
Reach End of Array with MAximum Score

You are given an integer array nums of length n.

Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.

The score for a jump from index i to index j is calculated as (j - i) * nums[i].

Return the maximum possible total score by the time you reach the last index.


Example 1:

Input: nums = [1,3,1,5]

Output: 7

Explanation:

First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.

Example 2:

Input: nums = [4,3,1,3,2]

Output: 16

Explanation:

Jump directly to the last index. The final score is 4 * 4 = 16.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

//Solution
/*
Implementation 1:
This function uses a dynamic programming approach to solve the problem. Here's how it works:

    -> It initializes a DP array dp of size n to store the maximum scores.
    -> It iterates from the second-to-last index to the first index.
    -> For each index i, it tries all possible jumps forward (to indices j > i).
    -> It calculates the score for each jump and updates the maximum score for the current index.
    -> The maximum score for each index is stored in the dp array.
    -> Finally, it returns dp[0], which represents the maximum score starting from the first index.
The reason this solution is giving a Time Limit Exceeded (TLE) error for the given constraints is due to its time complexity:

    -> The outer loop runs n times.
    -> The inner loop, in the worst case, also runs n times for each iteration of the outer loop.
This results in a time complexity of O(n^2), which is too slow for the given constraint of 1 <= nums.length <= 10^5.

With n = 10^5, the algorithm would perform approximately 10^10 operations, which is too many to complete within the 1-second time limit typically given in competitive programming problems.

To optimize this solution and avoid TLE, you'd need to reduce the time complexity, possibly by using a more efficient data structure or by finding a way to avoid checking all possible jumps for each index.


Implementation 2:
First, it creates a vector called dp to store the maximum scores that can be achieved starting from each position in the array. It also creates a stack to keep track of important positions as it moves through the array.

The function then starts from the second-to-last position in the array and works its way backwards to the start. For each position, it does a few things:

    It removes any positions from the stack that have lower or equal numbers than the current position. This is because jumping to those positions would never be better than jumping directly from the current position to a later one.

    If the stack is empty after this, it means the best move is to jump directly to the end from the current position. The score for this is calculated and stored in dp.

    If the stack isn't empty, it compares two options: jumping to the position at the top of the stack, or using the best score that can be achieved from that position (which is stored in the stack). It chooses the better of these two options and stores it in dp.

    Finally, it adds the current position and its best score to the stack.

This process continues until it reaches the start of the array. The maximum score that can be achieved from the start is then returned as the final answer.

The key to this algorithm is that it efficiently handles the case where it might be better to make multiple smaller jumps instead of one big jump. By using the stack, it avoids having to recalculate scores for positions that have already been determined to be less optimal.

Time Complexity:
The time complexity of the findMaximumScore function is O(n), where n is the length of the input vector nums.

This linear time complexity is achieved because:

The main loop iterates through the array once, from the second-to-last element to the first. This contributes O(n) to the time complexity.

The while loop inside the main loop might seem to add extra complexity, but each element is pushed and popped from the stack at most once throughout the entire execution of the function. This means that the total number of operations performed by the while loop across all iterations of the main loop is also O(n).

All other operations inside the loops (comparisons, arithmetic operations, and accessing vector elements) are constant time O(1) operations.

Therefore, the overall time complexity remains O(n), which is a significant improvement over the O(n^2) complexity of the initial implementation that was causing a Time Limit Exceeded error. This optimized version can handle the given constraint of 1 <= nums.length <= 10^5 efficiently.
*/

#include<bits/stdc++.h>
using namespace std;

#include <algorithm>

class Solution {
public:
    //Implementation 1
    //Gives TLE
    /**
     * Finds the maximum possible total score by starting at index 0 and reaching the last index in the given array `nums`.
     * The score for a jump from index `i` to index `j` is calculated as `(j - i) * nums[i]`.
     * The function uses dynamic programming to compute the maximum score.
     *
     * @param nums - The input array of integers.
     * @return The maximum possible total score.
     */
    long long findMaximumScore_TLE(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        
        // Start from the second-to-last index
        for (int i = n - 2; i >= 0; i--) {
            long long maxScore = 0;
            // Try all possible jumps forward
            for (int j = i + 1; j < n; j++) {
                long long score = (j - i) * (long long)nums[i] + dp[j];
                maxScore = max(maxScore, score);
            }
            dp[i] = maxScore;
        }
        
        return dp[0];
    }


    //Implementation 2

    /**
     * Finds the maximum possible total score by starting at index 0 and reaching the last index in the given array `nums`.
     * The score for a jump from index `i` to index `j` is calculated as `(j - i) * nums[i]`.
     * The function uses a stack-based approach to compute the maximum score.
     *
     * @param nums - The input array of integers.
     * @return The maximum possible total score.
     */
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        
        vector<pair<int, int>> stack;
        for (int i = n - 2; i >= 0; i--) {
            while (!stack.empty() && nums[i] >= nums[stack.back().first]) {
                stack.pop_back();
            }
            
            if (stack.empty()) {
                dp[i] = (long long)(n - 1 - i) * nums[i];
            } else {
                int j = stack.back().first;
                dp[i] = max((long long)(j - i) * (long long)nums[i] + dp[j], (long long)stack.back().second);

            }
            
            stack.push_back({i, dp[i]});
        }
        
        return dp[0];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,5};
    cout << s.findMaximumScore(nums) << endl;
    cout << s.findMaximumScore_TLE(nums) << endl;
    return 0;
}