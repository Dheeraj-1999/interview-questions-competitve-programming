/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = nums1.size()-1;
        m--;
        n--;
        while(m >= 0 and n >= 0) {
            
            if(nums1[m] < nums2[n]) {
                nums1[last] = nums2[n];
                n -= 1;
                last -=1;
            } else if(nums1[m] > nums2[n]) {
                nums1[last] = nums1[m];
                m -= 1;
                last -= 1;
            } else if( nums1[m] == nums2[n]) {
                m -= 1;
                n -= 1;
                last -= 1;
            }
            cout << m << " " << n << " " << last << endl;
        }        
    }
};
// @lc code=end

