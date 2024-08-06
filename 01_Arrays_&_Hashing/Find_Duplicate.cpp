// Question 3: Find Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range[1, n] inclusive, 
// there is only one repeated number. Return this repeated number.

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int findDuplicate(const vector<int> &nums){ // Regular method
    unordered_set<int> n;
    for(int i = 0; i < nums.size(); i++){
        if(n.find(nums[i]) != n.end()){
            return nums[i];
        }
        n.insert(nums[i]);
    }
    return -1;
}

int findDuplicate2(const vector<int> &nums){ // Ranged for loop method
    unordered_set<int> s;
    for (const auto& n : nums){
        if (s.find(n) != s.end()){
            return n;
        }
        s.insert(n);
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 3, 4, 5, 2, 6, 7, 5};
    int duplicate = findDuplicate(nums);
    int duplicate2 = findDuplicate2(nums);
    // Expected output: 2
    cout << "Duplicate number: " << duplicate  << ", duplicate2: " << duplicate2 << endl;
    return 0;
}
