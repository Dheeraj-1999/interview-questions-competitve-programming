/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // ***************** nSquare Solution!!!!!!!! ********************
        // int rslt = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         rslt = max(rslt, prices[j]-prices[i]);
        //     }
        // }
        // return rslt;  
        
        int profit = 0;
        int mini = INT_MAX;
        
        for(int i=0; i<n; i++) {
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i]-mini);
            // cout << profit << " ";
        }
        return profit;
    }
};
// @lc code=end

