#include <iostream>
#include <vector>

using namespace std;

int Binary_Search(int target, vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int middle;

    while(left <= right){
        middle = left + ((right-left) / 2);

        // Assuming data ordered in ascending order
        if(target < nums[middle]){
            right = middle - 1;
        } else if(target > nums[middle]){
            left = middle + 1;
        } else {
            return middle;
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    // Test with existing target
    int target = 7; 
    int result = Binary_Search(target, nums);

    if (result != -1){
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    // Test with non existing target
    target = 8;
    result = Binary_Search(target, nums);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}