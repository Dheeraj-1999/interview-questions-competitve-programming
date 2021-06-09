/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rslt;
        // for(int i=0; i<nums.size(); i++) {
        //     int findNum = target - nums[i];
        //     auto it = find(nums.begin(), nums.end(), findNum);

        //     if(it == nums.end()or (it - nums.begin()) == i) continue;
        //     rslt.push_back(i);
        //     rslt.push_back(it - nums.begin());
        //     break;
        // }

        // Approach 2

        map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) != m.end()) {
                rslt.push_back(m[nums[i]]);
                rslt.push_back(i);
                break;
            }
            m[target - nums[i]] = i;
        }
        return rslt;
    }
};
// @lc code=end

