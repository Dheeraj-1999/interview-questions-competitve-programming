def reverseArr(arr, n):
    i, j = 0, n-1
    while(i <= j):
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1  
    print(arr)

def reverseArrRec(arr, i, j):
    if(i >= j):
        # print(arr)
        return(arr)

    arr[i], arr[j] = arr[j], arr[i]
    reverseArrRec(arr, i+1, j-1)

arr = [int(u) for u in input().split(" ")]
# reverseArr(arr, len(arr))
reverseArrRec(arr, 0, len(arr)-1)
print(arr)