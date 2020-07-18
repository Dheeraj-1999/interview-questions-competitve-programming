p=int(input())
q=int(input())
r=int(input())
s=int(input())
ans=0
def children(cad):
    child=0
    a,b=cad
    while a>0 and b>0:
        if a<b:
            a,b=a,b-a
            child+=1
        elif a>b:
            a,b=a-b,b
            child+=1
        elif a==b:
            a,b=0,0
            child+=1
    return child
for i in range(p,q+1):
    for j in range(r,s+1):
        print(children((i,j)), (i,j))
print(ans)