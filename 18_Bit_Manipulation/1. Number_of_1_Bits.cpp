/* Number of One Bits
You are given an unsigned integer n. Return the number of 1 bits in its binary representation.

Example 1: Input: n = 00000000000000000000000000010111
Output: 4
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count += n % 2;
            n = n >> 1;
        }
        return count;
    }
};

int hammingWeight(uint32_t n) { // Other method
    int count = 0;
    while(n){
        if(n & 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}
