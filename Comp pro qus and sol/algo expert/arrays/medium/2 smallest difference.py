# Write a function that takes in two non-empty arrays of integers. 
# The function should find the pair of numbers (one from the first array, one from the second array)
#  whose absolute difference is closest to zero.
#  The function should return an array containing these two numbers, with the number from the first array in the first position. 
# Assume that there will only be one pair of numbers with the smallest difference.


# problem 82 notebook

def smallestDif(arr1, arr2) :
    n1 = len(arr1)
    n2 = len(arr2)
    i, j = 0, 0
    diff = 100000
    ans = [0, 0]
    # diff = min(diff, abs(arr1[i] - arr2[j]))
    while(i < n1 and j < n2):
        if(diff > abs(arr1[i] - arr2[j])):
            ans[0],ans[1] = arr1[i], arr2[j]
        diff = min(diff, abs(arr1[i] - arr2[j]))
        if(arr1[i] < arr2[j]):
            i += 1      
        
        elif(arr2[j] < arr1[i]):
            j += 1
        # diff = min(diff, abs(arr1[i] - arr2[j]))
        print(ans, diff)


arr1 = [int(i) for i in input().split(' ')]
arr2 = [int(i) for i in input().split(' ')]
arr1.sort()
arr2.sort()
print(smallestDif(arr1,arr2))
    