/*
Minimum Number of Seconds to Make Mountain Height Zero
You are given an integer mountainHeight denoting the height of a mountain.

You are also given an integer array workerTimes representing the work time of workers in seconds.

The workers work simultaneously to reduce the height of the mountain. For worker i:

To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.
Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.


Example 1:

Input: mountainHeight = 4, workerTimes = [2,1,1]

Output: 3

Explanation:

One way the height of the mountain can be reduced to 0 is:

Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds.
Worker 1 reduces the height by 2, taking workerTimes[1] + workerTimes[1] * 2 = 3 seconds.
Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second.
Since they work simultaneously, the minimum time needed is max(2, 3, 1) = 3 seconds.

Example 2:

Input: mountainHeight = 10, workerTimes = [3,2,2,4]

Output: 12

Explanation:

Worker 0 reduces the height by 2, taking workerTimes[0] + workerTimes[0] * 2 = 9 seconds.
Worker 1 reduces the height by 3, taking workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12 seconds.
Worker 2 reduces the height by 3, taking workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12 seconds.
Worker 3 reduces the height by 2, taking workerTimes[3] + workerTimes[3] * 2 = 12 seconds.
The number of seconds needed is max(9, 12, 12, 12) = 12 seconds.

Example 3:

Input: mountainHeight = 5, workerTimes = [1]

Output: 15

Explanation:

There is only one worker in this example, so the answer is workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15.

 

Constraints:

1 <= mountainHeight <= 105
1 <= workerTimes.length <= 104
1 <= workerTimes[i] <= 106
*/

//Solution:
/*
The purpose of this code is to find the minimum time required to reduce a mountain's height to zero, given the initial height of the mountain and the working speeds of different workers. Each worker can reduce the mountain's height, but their efficiency decreases as they work longer.

The main inputs for this problem are:

The initial height of the mountain (an integer)
A list of worker times (a vector of integers), where each number represents how long it takes a worker to reduce the mountain height by 1 unit
The output is a single number: the minimum number of seconds needed to reduce the mountain's height to zero.

The code uses a binary search algorithm to efficiently find the minimum time. It starts with a wide range of possible times (from 0 to 10^18 seconds) and repeatedly narrows down this range until it finds the smallest time that works.

The core of the algorithm is in the canReduceMountain function. This function checks if it's possible to reduce the mountain to zero within a given time limit. It does this by calculating how much each worker can reduce the mountain's height in the given time, using a mathematical formula. If the total reduction from all workers is enough to bring the mountain to zero, the function returns true.

The minNumberOfSeconds function performs the binary search. It keeps adjusting the time (represented by mid) and checking if it's possible to reduce the mountain in that time. If it's possible, it tries a smaller time; if not, it tries a larger time. This process continues until it finds the smallest possible time that works.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    /**
     * Determines if the mountain height can be reduced to 0 within the given time limit.
     *
     * @param time The maximum time allowed to reduce the mountain height.
     * @param mountainHeight The initial height of the mountain.
     * @param workerTimes The time it takes for each worker to reduce the mountain height by 1.
     * @return `true` if the mountain height can be reduced to 0 within the given time limit, `false` otherwise.
     */
    bool canReduceMountain(long long time, int mountainHeight, const std::vector<int>& workerTimes) {
        long long totalReduction = 0;
        for (int workerTime : workerTimes) {
            /*
            //long long x = (-1 + static_cast<long long>(std::sqrt(1 + 8.0 * time / workerTime))) / 2;
            -> The formula is derived from the quadratic equation that represents the total time taken by a worker: time = workerTime + 2workerTime + 3workerTime + ... + x*workerTime

            -> This series can be simplified to: time = workerTime * (x * (x + 1) / 2)

            -> Rearranging this equation to solve for x gives us: x^2 + x - (2 * time / workerTime) = 0

            -> Using the quadratic formula to solve this, we get: x = (-1 + sqrt(1 + 8 * time / workerTime)) / 2

            -> In the code, we're using static_cast to ensure we're working with integer values, as we can't have fractional reductions in mountain height.

            -> The formula calculates the maximum number of height units a worker can reduce within the given time, considering that each subsequent reduction takes longer than the previous one.
            */
            long long x = (-1 + static_cast<long long>(std::sqrt(1 + 8.0 * time / workerTime))) / 2;
            totalReduction += x;
            if (totalReduction >= mountainHeight) {
                return true;
            }
        }
        return false;
    }
public:
    /**
     * Finds the minimum number of seconds required to reduce the mountain height to 0 using the given worker times.
     *
     * @param mountainHeight The initial height of the mountain.
     * @param workerTimes A vector of the time it takes for each worker to reduce the mountain height by 1.
     * @return The minimum number of seconds required to reduce the mountain height to 0.
     */
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canReduceMountain(mid, mountainHeight, workerTimes)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
int main() {
    Solution solution;
    // Example 1
    std::vector<int> workerTimes1 = {2, 1, 1};
    int mountainHeight1 = 4;
    std::cout << "Example 1 Output: " << solution.minNumberOfSeconds(mountainHeight1, workerTimes1) << std::endl;

    // Example 2
    std::vector<int> workerTimes2 = {3, 2, 2, 4};
    int mountainHeight2 = 10;
    std::cout << "Example 2 Output: " << solution.minNumberOfSeconds(mountainHeight2, workerTimes2) << std::endl;

    // Example 3
    std::vector<int> workerTimes3 = {1};
    int mountainHeight3 = 5;
    std::cout << "Example 3 Output: " << solution.minNumberOfSeconds(mountainHeight3, workerTimes3) << std::endl;
    return 0;
}