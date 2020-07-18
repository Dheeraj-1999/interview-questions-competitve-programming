def solve(nums, k):
    finder = {}
    for i in nums:
        finder[i] = 0
    for i in nums:
            finder[i] += 1
    
    for i in nums:
        if(k-i == i):
            if(finder.get(k-i, 0) > 0):
                finder[k-i] -= 1
        print(finder.get(k-i, 0), k-i)
        if(finder.get(k-i, 0) == 1):
            return True
    return False

nums = [1, 1, 2, 3, 4, 5]
k = 10

print(solve(nums, k))            