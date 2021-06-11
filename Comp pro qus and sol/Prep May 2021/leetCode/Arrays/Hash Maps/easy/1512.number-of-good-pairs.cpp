/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> store;
        int result = 0;
        for(int ele:nums) {
            result += store[ele]++;
        }

        // for(auto it:store) {
        //     int n = it.second;
        //     result += n*(n-1)/2;
        // }
        return result;
    }
};
// @lc code=end

