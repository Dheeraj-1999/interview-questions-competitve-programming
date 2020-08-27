arr = [int(i) for i in input().split(' ')]

def bubbleSort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-i-1):
            if(arr[j] > arr[j+1]):
                arr[j+1], arr[j] = arr[j], arr[j+1]
    print(arr)

bubbleSort(arr)
