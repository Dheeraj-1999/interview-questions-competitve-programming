/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        int temp = 0;
        sums.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            sums.push_back(sums[i-1] + nums[i]);
        }
        // 1 3 6 10
        // vector<int> subArrSums;
        for (int i = 0; i < n; i++)
        {
            // subArrSums.push_back(sums[i]);
            for(int j=i+1; j<n; j++) {
                sums.push_back(sums[j] - sums[i]);
            }
        }
        

        sort(sums.begin(), sums.end());
        vector<int> resultSum(sums.size(), 0);
        resultSum[0] = sums[0];
        for (int i = 1; i < sums.size(); i++)
        {
            resultSum[i] = resultSum[i-1] + sums[i];
        }
        // for(int i:sums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for(int i:resultSum) {
        //     cout << i << " ";
        // }
        if(left == 1) {
            return resultSum[right-1];
        }
        return resultSum[right-1] - resultSum[left-1];
    }
};
// @lc code=end

