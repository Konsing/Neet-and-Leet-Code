/* Is Anagram
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different. */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        if(s.size() != t.size()){
            return false;
        }

        for(int i = 0; i < s.size(); i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }

        if(m1 != m2){
            return false;
        } else {
            return true;
        }
    }
};
