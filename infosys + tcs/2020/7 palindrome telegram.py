nm=input().split()
firstday=int(nm[0])
lastday=int(nm[-1])

starttime=str(firstday) + str('000000')
endtime=str(lastday) + str(235959)

lenofday=len(str(firstday))
lenoflasday=len(str(lastday))

palindrome=0

for i in range(int(starttime),int(endtime)+1):
    count=0
    if(int(str(i)[lenofday::])<235960):  
        for j in range(len(str(i))//2):
            if((str(i))[j]!=(str(i))[-j-1]):
                break
            else:
                count+=1

        if(count==len(str(i))//2):
            palindrome += 1
    
print(palindrome)