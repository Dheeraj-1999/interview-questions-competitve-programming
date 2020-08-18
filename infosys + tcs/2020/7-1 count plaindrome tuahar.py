
def is_pallindrome(s):
    for j in range(len(str(i))//2):
        if((str(i))[j]!=(str(i))[-j-1]):
            return False
    return True


nm=input().split()
firstday=int(nm[0])
lastday=int(nm[-1])

starttime = str(firstday) + "000000"
endtime = str(lastday) + "235959"

palindrome=0
for i in range(int(starttime),int(endtime)+1):
    if(is_pallindrome(i)):
        palindrome += 1
    
print(palindrome)