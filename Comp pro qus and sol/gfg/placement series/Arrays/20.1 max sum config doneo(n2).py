def max_sum(a,n):
    #code here
    maxSum = -1
    for i in range(n):
        temp = 0
        for j in range(0, n-i):
            temp += a[j+i]*j
            # print(temp, end=' ')
        # start = j
        for j in range(0, i):
            # if(i != 0):
            temp += a[j]*(j+n-i)
            # print(temp, end=' ')
        maxSum = max(temp, maxSum)
    return maxSum