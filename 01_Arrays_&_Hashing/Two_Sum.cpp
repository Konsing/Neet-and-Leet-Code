// Question 1: Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

pair<int, int> twoSum(const vector<int> &nums, int target){
    int comp;
    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++){
        comp = target - nums[i];
        if(m.find(comp) != m.end()){
            return {m[comp], i};
        }
        m[nums[i]] = i;
    }
    
    return make_pair(-1, -1); // Placeholder return
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    auto result = twoSum(nums, target);
    // Expected output: (0, 1)
    cout << "(" << result.first << ", " << result.second << ")" << endl;
    return 0;
}