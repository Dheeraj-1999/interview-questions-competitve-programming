
def binSearch(arr, i, j, ele):
    
    if(i<=j):
        mid = (i+j)//2
        if(arr[mid] == ele):
            return mid
        elif(arr[mid] < ele):
            return binSearch(arr, mid+1, j, ele)
        else:
            return binSearch(arr, i, mid-1,ele)
    
    else:
        return -1

def binSearchItr(arr, ele):
    i = 0
    j = len(arr)
    while(i < j):
        mid = (i+j)//2
        if(arr[mid] == ele):
            return mid
        elif(arr[mid] < ele):
            i = mid + 1
        else:
            j = mid - 1
    return -1
    
arr = [int(i) for i in input().split(' ')]
ele = int(input())
k = binSearchItr(arr, ele)
print(k)    

