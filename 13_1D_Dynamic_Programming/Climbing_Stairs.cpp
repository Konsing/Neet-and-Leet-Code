/* Climbing Stairs
You are given an integer n representing the number of steps to reach the top of a staircase. 
You can climb with either 1 or 2 steps at a time.
Return the number of distinct ways to climb to the top of the staircase.*/

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }

        if(n == 2){
            return 2;
        }

        int n1 = 1;
        int n2 = 2;

        int r = 0;

        for(int i = 2; i < n; i++){
            r = n1 + n2;
            n1 = n2;
            n2 = r;
        }

        return r;
    }
};
