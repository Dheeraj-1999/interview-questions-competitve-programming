import random
arr = [int(i) for i in input().split(' ')]

def helper(arr, s, e):
    i = s-1
    j = s
    n = e-1
    pivot = arr[e]
    # i is denoting the end index region which is smaller than pivot
    for j in range(s, e-1):
        if(arr[j] < pivot):
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        else:
            j += 1
    arr[j], arr[i+1] = arr[i+1], arr[j]
    return i+1

def shuffling(arr):
    random.shuffle(arr)

def quickSort(arr, s, e):
    pivotIndex = helper(arr, s, e)
    quickSort(arr, s, pivotIndex-1)
    quickSort(arr, pivotIndex+1, e)


shuffling(arr)
print(arr)