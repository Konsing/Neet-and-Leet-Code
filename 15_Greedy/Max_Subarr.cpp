// Question 5 : Maximum Subarray
// Given an integer array nums, find the contiguous subarray(containing at least one number) 
// which has the largest sum and return its sum.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxSubArray(const vector<int> &nums){
    int total_sum = 0;
    int max_sub = nums[0];

    for(auto n : nums){
        if(total_sum < 0){
            total_sum = 0;
        }
        total_sum = total_sum + n;
        max_sub = max(max_sub, total_sum);
    }
    return max_sub;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSubArray(nums);
    // Expected output: 6 (subarray [4, -1, 2, 1])
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}