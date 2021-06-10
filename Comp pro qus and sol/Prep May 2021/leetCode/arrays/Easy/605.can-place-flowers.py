#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        pre = 0
        count = 0
        for i in range(0, len(flowerbed)):
            curr = flowerbed[i]
            if(curr == 0):
                if(pre == 0 and (i == len(flowerbed)-1 or flowerbed[i+1] == 0)):
                   count += 1
                   pre = 1
                else:
                    pre = 0
            else:
                pre = 1
            if(count >= n):
                return True
        return False     
# @lc code=end

