/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    //    approach 1 complexity--------o(n) < ourTc < o(n2)
    // mean time complexity between n and n2

        int* temp = new int[102]();
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            temp[nums[i]]++;
        }

        for(int i=0; i<nums.size(); i++) {
            int resultEle = 0;
            for(int j=nums[i]-1; j>=0; j--) {
                resultEle += temp[j];
            }
            result.push_back(resultEle);
        }
        // delete temp;
        return result;
    
        // Approach 2
        // int n = nums.size();
        // int* count = new int[101]();
        // int* res = new int[nums.size()]();
        // for (int i =0; i < nums.size(); i++) {
        //     count[nums[i]]++;
        // }
        
        // for (int i=1 ; i<=100; i++) {
        //     count[i] += count[i-1];    
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0)
        //         res[i] = 0;
        //     else 
        //          res[i] = count[nums[i] - 1];
        // } 
        // return res;    
    }    
};
// @lc code=end

