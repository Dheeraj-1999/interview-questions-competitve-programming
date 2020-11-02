def sort(arr):
    # counts = {0:0, 1:0, 2:0}
    zero = 0
    one = 0
    two = 0
    for i in arr:
        if(i == 0):
            zero += 1
        if(i == 1):        
            one += 1
        if(i == 2):
            two += 1 
    
    for i in range(zero):
        arr[i] = 0
    # print(arr)
    for i in range(zero, zero+one):
        arr[i] = 1
    for i in range(zero+one, zero+one+two):
        arr[i] = 2
    # print(arr)
    for i in range(len(arr)): 
        print(arr[i],end=" ") 

arr = [int(i) for i in input().split(" ")]
sort(arr)