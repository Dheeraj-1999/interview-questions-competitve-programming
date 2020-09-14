# Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. 
# The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. 
# The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. 
# If no three numbers sum up to the target sum, the function should return an empty array.


# problem 80 81 notebook
# Algoexpert

def tripletSum(arr, target):
    result = []
    arr = sorted(arr)
    n = len(arr)
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if(arr[i] + arr[j] + arr[k] == target):
                    result.append([arr[i] , arr[j] , arr[k]])
    return result


def tripletSumOpt(arr, target):
    result = []
    arr = sorted(arr)
    n = len(arr)
    Kchecker = {}
    for i in arr:
        Kchecker[i] = 1
    for i in range(n):
        for j in range(i+1, n):
                if(Kchecker.get(target - (arr[i] + arr[j])) and (target - (arr[i] + arr[j]) > arr[j])):
                    result.append([arr[i] , arr[j] ,target - (arr[i] + arr[j]) ])
    return result

def tripletSum3Pointer(arr, target):
    result = []
    arr.sort()
    for i in range(len(arr)-2):
        left = i+1
        right = len(arr)-1
        while(left < right):
            currSum = arr[i] + arr[left] + arr[right]

            if(currSum == target):
                result.append([arr[i], arr[left], arr[right]])
                left += 1
                right -= 1
            elif(currSum < target):
                left += 1
            elif(currSum > target):
                right -= 1
    return(result)

def tripletSucloset(arr, target):
    # currSumArr = []
    closest = -1
    arr.sort()
    mini = 100000
    for i in range(len(arr)-2):
        left = i+1
        right = len(arr)-1
        # currSum = (arr[i] + arr[left] + arr[right])
        while(left < right):
            currSum = arr[i] + arr[left] + arr[right]

            if(currSum == target):
                return target
                # break
            elif(currSum < target):
                left += 1
            elif(currSum > target):
                right -= 1
            
            if(mini > abs(target - currSum)):
                mini = abs(target - currSum)
                closest = currSum
                # currSumArr.append(currSum)
                print(closest, mini)
        
            elif(mini == abs(target - currSum)):
                closest = max(closest, currSum)
                print(closest, mini)
    return(closest)


arr = [int(i) for i in input().split(' ')]
target = int(input())

result = tripletSucloset(arr, target)
print(result)

