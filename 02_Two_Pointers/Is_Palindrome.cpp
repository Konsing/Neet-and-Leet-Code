/*Is Palindrome
Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters. */

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;

        while (left < right){
            while (!isalnum(s[left]) && left < right){
                left++;
            }

            while (!isalnum(s[right]) && left < right){
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
