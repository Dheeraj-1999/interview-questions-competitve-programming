
def rec(a):
    global b
    if(b<=10):
        c=b*a
        print(a," * " , b , " = " ,  c)
        
        b=b+1
        rec(a)
a=int(input("enter the number "))
b=1
rec(a)
