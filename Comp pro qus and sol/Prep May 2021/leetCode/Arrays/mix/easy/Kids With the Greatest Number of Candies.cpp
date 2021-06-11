class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxEle = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] + extraCandies < maxEle) {
                result.push_back(false);
            } else {
                result.push_back(true);
            }
        }
        return result;
    }
};