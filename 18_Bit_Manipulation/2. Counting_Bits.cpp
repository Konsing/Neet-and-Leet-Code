/* Counting Bits

Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].
Return an array output where output[i] is the number of 1's in the binary representation of i.
Example 1: Input: n = 4
Output: [0,1,1,2,1]*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0); // Initialize vector with size n+1 and all elements set to 0

        for (int i = 0; i <= n; ++i) {
            result[i] = result[i >> 1] + (i & 1); // result[i >> 1] is the most recently computed number
        }

        return result;
    }
};

/*
Example Walkthrough
For n = 10, let's compute result[i] for i from 0 to 10:

i = 0: result[0] = 0 (binary 0 has no 1s)
i = 1: result[1] = result[1 >> 1] + (1 & 1) = result[0] + 1 = 1 (binary 1 has one 1)
i = 2: result[2] = result[2 >> 1] + (2 & 1) = result[1] + 0 = 1 (binary 10 has one 1)
i = 3: result[3] = result[3 >> 1] + (3 & 1) = result[1] + 1 = 2 (binary 11 has two 1s)
i = 4: result[4] = result[4 >> 1] + (4 & 1) = result[2] + 0 = 1 (binary 100 has one 1)
i = 5: result[5] = result[5 >> 1] + (5 & 1) = result[2] + 1 = 2 (binary 101 has two 1s)
i = 6: result[6] = result[6 >> 1] + (6 & 1) = result[3] + 0 = 2 (binary 110 has two 1s)
i = 7: result[7] = result[7 >> 1] + (7 & 1) = result[3] + 1 = 3 (binary 111 has three 1s)
i = 8: result[8] = result[8 >> 1] + (8 & 1) = result[4] + 0 = 1 (binary 1000 has one 1)
i = 9: result[9] = result[9 >> 1] + (9 & 1) = result[4] + 1 = 2 (binary 1001 has two 1s)
i = 10: result[10] = result[10 >> 1] + (10 & 1) = result[5] + 0 = 2 (binary 1010 has two 1s)
*/
