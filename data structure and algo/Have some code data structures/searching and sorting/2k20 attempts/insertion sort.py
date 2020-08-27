arr = [int(i) for i in input().split(' ')]

def insetionSort(arr):
    for i in range(len(arr)):
        key = arr[i]
        j = i-1
        while(j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    print(arr)
insetionSort(arr)