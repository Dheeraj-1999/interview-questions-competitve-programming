arr = [int(i) for i in input().split(' ')]
ele = int(input())

def linearSearch(arr):
    for i in range(len(arr)):
        if(ele == arr[i]):
            return i
    return -1

index = linearSearch(arr)
print(index+1)