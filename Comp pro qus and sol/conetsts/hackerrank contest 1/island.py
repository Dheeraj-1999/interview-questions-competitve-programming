t = int(input())
while(t > 0):
    
    n = int(input())
    sumNum = 0
    count = 0
    # while(sumNum <= n):
    #     print(count, i, sumNum)
    #     sumNum += i
    #     count += 1
    #     i += 1

    for i in range(1, n+1):
        if(sumNum < n):
            sumNum += i
            count += 1
        else:
            break
    print(count)
    t -= 1