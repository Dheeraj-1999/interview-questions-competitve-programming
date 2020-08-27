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
    # result = []
    arr.sort()
    mini = 100
    sums = 0
    for i in range(len(arr)-2):
        left = i+1
        right = len(arr)-1
        # currSum = (arr[i] + arr[left] + arr[right])
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

            if(mini, abs(target - (arr[i] + arr[left] + arr[right])) != mini):
                mini = min(mini, abs(target - (arr[i] + arr[left] + arr[right])))
                sums = (arr[i] + arr[left] + arr[right])
            else:
                mini = max(sums, (arr[i] + arr[left] + arr[right]))
    return(sums)


arr = [int(i) for i in input().split(' ')]
target = int(input())

result = tripletSum3Pointer(arr, target)
print(result)

