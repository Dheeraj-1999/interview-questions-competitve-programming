def convertFive(n):
    # Code here
    # n = str(n)
    # ans = ''
    # for i in range(len(n)):
    #     if(n[i] == '0'):
    #         ans += '5'
    #     else:
    #         ans += n[i]
    # n = int(ans)
    # return n
    if(n == 0):
        return 0
    a = n%10
    if(a == 0):
        a = 5
    num = convertFive(n//10) * 10 + a
    return num

n = int(input())
convertFive(n)
