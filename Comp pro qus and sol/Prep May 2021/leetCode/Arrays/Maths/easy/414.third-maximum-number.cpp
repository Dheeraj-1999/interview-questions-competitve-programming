/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first, second, third;
        first = LLONG_MIN;
        second = LLONG_MIN;
        third = LLONG_MIN;
        if(nums.size() < 3) {
            return(*max_element(nums.begin(), nums.end()));
        }
        for(long long i:nums) {
            //  cout << first << " " << second << " " << third << "--";
            if(i == first or i == second or i == third) continue;
            if(i > first) {
                third = second;
                second = first;
                first = i;
            } else if(i < first and i > second) {
                third = second;
                second = i;
            } else if(i < second and i > third) {
                third = i;
            }
            // cout << first << " " << second << " " << third << endl;
        }
        if(third != LLONG_MIN)
            return third;
        else
            return(first);
    }
};
// @lc code=end

