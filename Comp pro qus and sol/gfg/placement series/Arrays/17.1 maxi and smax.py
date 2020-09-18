def mAndSM(arr) :
    maxi = -1
    smaxi = -1
    for i in arr:
        if(i > maxi):
            smaxi = maxi
            maxi = i
        if(i < maxi and i > smaxi):
            smaxi = i
    print(maxi, smaxi)


arr = [int(i) for i in input().split(' ')]
mAndSM(arr)