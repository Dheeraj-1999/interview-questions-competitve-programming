import collections

def swayamvar(brides, grooms, n):
    brides = collections.deque(brides)
    grooms = collections.deque(grooms)
    while(brides):
        if(brides[0] not in grooms):
            return(len(brides))
        if(brides[0] != grooms[0]):
            temp = grooms.popleft()
            grooms.append(temp)
        elif(brides[0] == grooms[0]):
            grooms.popleft()
            brides.popleft()
    return 0
    
    

    # return(abs((brideR + groomsR) - (brideM + groomsM)))
n = int(input())
brides = input()
grooms= input()
print(swayamvar(brides, grooms, n))
# print(brides.count('R'))
# print(brides.count('M'))
# print(grooms.count('R'))
# print(grooms.count('M'))

