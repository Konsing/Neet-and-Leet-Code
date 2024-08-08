/* Missing Number
Given an array nums containing n integers in the range [0, n] without any duplicates, return 
the single number in the range that is missing from nums.
Follow-up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Example 1: Input: nums = [1,2,3]
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for(int i = 0; i < nums.size(); i++){
            res += i - nums[i];
        }
        
        return res;
    }
};

