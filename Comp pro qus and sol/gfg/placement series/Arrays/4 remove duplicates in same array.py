def remove_duplicate(n, arr):
    #Code here
    # ar = sorted(list(set(arr)))
    # for i in range(len(ar)):
    #     arr[i] = ar[i]
    # return(len(ar))
    i = 0
    j = 0
    ele = arr[0]
    
    for j in range(1, n):
        if(arr[j] != ele):
            ele = arr[j]
            i += 1
            arr[i] = ele
    return i+1