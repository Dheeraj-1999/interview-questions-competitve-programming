/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i += 2) {
            result.insert(result.end(), nums[i], nums[i+1]);
        }
        return result;
    }
};
// @lc code=end

