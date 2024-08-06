/* Buy and Sell Crypto
You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.
Ex: Input: prices = [10,1,5,6,7,1]
Output: 6 because buy at 1 and sell at 7. (7 - 1 = 6)*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int left = 0;
        int right = 0;

        while(right < prices.size()){
            if(prices[right] > prices[left]){
                maxp = max(maxp, prices[right] - prices[left]);
            } else {
                left = right;
            }
            right++;
        }
        return maxp;
    }
};
