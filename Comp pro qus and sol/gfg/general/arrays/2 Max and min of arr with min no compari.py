def maxAndMinRec(arr, i, j):
    if((j-i) == 0):
        arr_max = arr[i]
        arr_min = arr[i]
        return (arr_max, arr_min)
    
    elif((j-i) == 0):
        arr_max = max(arr[i], arr[j])
        arr_min = min(arr[i], arr[j])
        return (arr_max, arr_min)
        
    else:
        mid = (i+j)//2
        lMaxMIn = maxAndMinRec(arr, i, mid)
        rMaxMin = maxAndMinRec(arr, mid+1, j);
        return(max(lMaxMIn[0], rMaxMin[0]), min(lMaxMIn[1], rMaxMin[1]))



arr = [int(i) for i in input().split(" ")]
print(maxAndMinRec(arr, 0, len(arr)-1))