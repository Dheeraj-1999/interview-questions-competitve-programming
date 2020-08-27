def fact(a):
    global b
    if a>1:
        b=a*fact(a-1)
        
    return b
   
b=1
a=int(input("enter the number"))
c=fact(a)
print(c)

