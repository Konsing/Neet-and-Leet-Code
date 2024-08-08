// Question 5 : Maximum Subarray
// Given an integer array nums, find the contiguous subarray(containing at least one number) 
// which has the largest sum and return its sum.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums){
    int cs = nums[0];
    int ms = nums[0];

    for (int i = 1; i < nums.size(); i++){
        cs = max(cs + nums[i], nums[i]);
        ms = max(ms, cs);
    }

    return ms;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSubArray(nums);
    // Expected output: 6 (subarray [4, -1, 2, 1])
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}