def swap(a, b):
    a, b = b, a

def mergeSorted(arr1, arr2, n, m):
    flag = False
    if(n < m):
        arr1, arr2 = arr2, arr1
        n ,m = m, n
        flag = True
    # print(arr1, arr2)
    p1 = n-2
    p2 = m-1
    # k = n+m
    last = arr1[n-1]
    for i in range(n-2, -1, -1):
        if(n <= 2):
            break;
        if(arr1[p1] > arr2[p2]):
            # arr1[p1] = arr2[p2]; 
            p1 -= 1
        if(arr2[p2] > arr1[p1]):
            for j in range(n-2, p1-1, -1):
                arr1[j+1] = arr1[j]
            arr1[p1+1] = arr2[p2]
            arr2[p2] = last
            last = arr1 [n-1]
            p2-= 1
        # print(arr1, arr2, p1, p2, last)
    if(flag == True):
        for i in range(n-m):
            arr2.insert(0, arr1.pop())
        arr1, arr2 = arr2, arr1
        n, m = m, n
    print(arr1, arr2)
    # print(arr1, arr2, p1, p2, last)
        



arr1 = [int(i) for i in input().split(' ')]
arr2 = [int(i) for i in input().split(' ')]
mergeSorted(arr1, arr2, len(arr1), len(arr2))
print(arr1 ,arr2)
