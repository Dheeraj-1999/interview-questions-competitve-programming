arr = [int(i) for i in input().split(' ')]

def swap(a, b):
    a, b = b, a

def selectionSort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if(arr[i] > arr[j]):
                arr[i], arr[j] = arr[j], arr[i]

selectionSort(arr)
print(arr)