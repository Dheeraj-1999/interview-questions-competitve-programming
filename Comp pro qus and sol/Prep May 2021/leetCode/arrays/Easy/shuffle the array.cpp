class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        # newArr = []
        # for i in range(n):
        #     newArr.append(nums[i])
        #     newArr.append(nums[i+n])
        #     i += 1
        # return newArr
        
#         o(1) space
        for i in range(n, len(nums)):
            val = nums.pop(i)
            nums.insert(2*(i-n) + 1, val)
        return nums