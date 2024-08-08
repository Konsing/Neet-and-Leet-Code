/* Reverse Bits
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.
Example 1: Input: n = 00000000000000000000000000010101
Output:    2818572288 (10101000000000000000000000000000)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for(int i = 0; i < 32; i++){
            uint32_t bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    } 
};
