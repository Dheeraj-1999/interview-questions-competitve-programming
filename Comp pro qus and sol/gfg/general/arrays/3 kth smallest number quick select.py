def partition(arr, l, r): 
  
    x = arr[r] 
    i = l 
    for j in range(l, r): 
        if (arr[j] <= x): 
            arr[i], arr[j] = arr[j], arr[i] 
            i += 1
    arr[i], arr[r] = arr[r], arr[i] 
    return i 

def kSmall(arr, l, r, k):
    # n = len(arr)

    if(k > 0 and k < r-l+1):

        pos = partition(arr, l, r)
        if(pos == k+1):
            return (arr[pos])
        elif(pos > k+1):
            return (kSmall(arr, l, pos-1, k))
        else:
            kSmall(arr, pos+1, r, k)
        


t = int(input())

while(t > 0):
    arr = [int(i) for i in input().split(" ")]
    k = int(input())
    print(kSmall(arr, 0, len(arr)-1, k))
    t -= 1