/*
Two Sneaky Numbers of Digitville
In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.



Example 1:

Input: nums = [0,1,1,0]

Output: [0,1]

Explanation:

The numbers 0 and 1 each appear twice in the array.

Example 2:

Input: nums = [0,3,2,1,3,2]

Output: [2,3]

Explanation:

The numbers 2 and 3 each appear twice in the array.

Example 3:

Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]

Output: [4,5]

Explanation:

The numbers 4 and 5 each appear twice in the array.



Constraints:

2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
The input is generated such that nums contains exactly two repeated elements.
*/
#include <bits/stdc++.h>
using namespace std;

// Using  Hashmap
class Solution
{
public:
    /**
     * Finds the two sneaky numbers in the given array.
     * 
     * The function uses a hash table to keep track of the count of each number in the array.
     * It then iterates through the array and identifies the two numbers that appear twice, which are the sneaky numbers.
     * 
     * @param nums The input array containing the sneaky numbers.
     * @return A vector of size 2 containing the two sneaky numbers.
     */
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> hash(n - 2, 0);
        vector<int> res(2, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (hash[nums[i]] > 0)
            {
                res[count] = nums[i];
                count += 1;
            }
            hash[nums[i]] += 1;
            if (count == 2)
            {
                break;
            }
        }
        return res;
    }
};

// Using XOR
class Solution2
{
public:
    /**
     * Finds the two sneaky numbers in the given array using the XOR operation.
     * 
     * The function first XORs all the elements of the array to get the XOR of the two sneaky numbers.
     * It then finds the rightmost set bit in the XOR value, which helps separate the array into two groups.
     * By XORing the elements in each group and the range of numbers from 0 to n-1, the function
     * can identify the two sneaky numbers.
     * 
     * @param nums The input array containing the sneaky numbers.
     * @return A vector of size 2 containing the two sneaky numbers.
     */
    vector<int> getSneakyNumbers(vector<int> &nums)
    {

        int xorSum = 0;
        int totalSize = nums.size();
        int actualSize = nums.size() - 2;

        // XOR all elements of the array
        for (int i = 0; i < totalSize; i++)
        {
            xorSum ^= nums[i];
        }

        // XOR all numbers from 0 to n-1 (excluding the two sneaky numbers)
        for (int i = 0; i < actualSize; i++)
        {
            xorSum ^= i;
        }

        // Find the rightmost set bit in xorSum
        int rightmostSetBit = xorSum & ~(xorSum - 1);

        int firstSneakyNumber = 0;
        int secondSneakyNumber = 0;

        // Separate the numbers into two groups based on the rightmost set bit
        for (int i = 0; i < totalSize; i++)
        {
            if (nums[i] & rightmostSetBit)
            {
                firstSneakyNumber ^= nums[i];
            }
            else
            {
                secondSneakyNumber ^= nums[i];
            }
        }

        // XOR the range of numbers from 0 to n-1
        for (int i = 0; i < actualSize; i++)
        {
            if (i & rightmostSetBit)
            {
                firstSneakyNumber ^= i;
            }
            else
            {
                secondSneakyNumber ^= i;
            }
        }

        return {firstSneakyNumber, secondSneakyNumber};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 0, 3, 7, 8};
    vector<int> res = s.getSneakyNumbers(nums);
    cout << res[0] << " " << res[1] << endl;
    Solution2 s2;
    vector<int> res2 = s2.getSneakyNumbers(nums);
    cout << res2[0] << " " << res2[1] << endl;
    return 0;
}
