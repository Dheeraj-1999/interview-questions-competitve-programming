l=[]
def valley(l):
    a=1
    b=1
    for i in range(0,len(l)-1):
        if l[i]>l[i+1]:
            if b>1:
                return False
            a=a+1
        if l[i]<l[i+1]:
            b=b+1
    if a>1 and b>1:
        return True
    else:
        return False
            
