/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        // if(n == 0) return false;
        // if(n == 1) return true;
        // if(n == 4) {
        //     return true;
        // }
        // if(n < 4) {
        //     return false;
        // } 
        // return isPowerOfFour(n/4);

        while(num > 1) {
            if(num % 4)return false;
            num /= 4;
        }
        return num == 1;
    }
};
// @lc code=end

