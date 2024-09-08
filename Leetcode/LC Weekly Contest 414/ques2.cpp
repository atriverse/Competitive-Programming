/*
You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].

You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.

Return the maximum possible score of the chosen integers.

 

Example 1:

Input: start = [6,0,3], d = 2

Output: 4

Explanation:

The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which equals 4.

Example 2:

Input: start = [2,6,13,13], d = 5

Output: 5

Explanation:

The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) which equals 5.

 

Constraints:

2 <= start.length <= 105
0 <= start[i] <= 109
0 <= d <= 109
*/


//Solution
/*
Intuition
The problem revolves around distributing values in such a way that the difference between consecutive values remains feasible. Our goal is to maximize the minimum difference (mid) while ensuring that the next value does not exceed the original value plus the given range (d).

Approach
    -> Sorting: Sort the start array to arrange the values in increasing order for easier binary search.

    -> Binary Search: Use binary search to find the largest possible minimum difference (mid) between consecutive values. The search range for mid is from 0 to start.back() - start.front() + d.

    -> Check Function: For each mid, check if we can place all values such that the difference between consecutive values is at least mid and doesn't exceed start[i] + d. Adjust the search range based on this check.

Complexity
    -> Time complexity: O(n log n + n log(max_difference))
    -> Space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    /**
     * Checks if it is possible to place all the values in the `start` vector such that the difference between consecutive values is at least `mid` and does not exceed `start[i] + d`.
     *
     * @param start The vector of starting values.
     * @param d The maximum allowed difference between consecutive values.
     * @param mid The minimum difference to be maintained between consecutive values.
     * @return `true` if it is possible to place all the values, `false` otherwise.
     */
    bool check(const vector<int>& start, int d, int mid){
        long long  prev=start[0];
        for(int i=1 ; i<start.size(); i++){
            long long int next=max(prev+mid, static_cast<long long>(start[i]));
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }
    /**
     * Finds the maximum possible score that can be obtained by distributing the values in the `start` vector such that the difference between consecutive values is at least `mid` and does not exceed `start[i] + d`.
     *
     * @param start The vector of starting values.
     * @param d The maximum allowed difference between consecutive values.
     * @return The maximum possible score that can be obtained.
     */
    int maxPossibleScore(vector<int>& start, int d) {
        int n=start.size();
        sort(start.begin(), start.end());
        long long low=0, hi=start.back() - start.front() + d;
        
        long long ans=0;
        while(low<=hi){
            long long mid=(low+hi)/2;
            if(check(start, d, mid)){
                ans=mid;
                low=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> start={6,0,3};
    int d=2;
    cout<<s.maxPossibleScore(start, d)<<endl;
    return 0;
}