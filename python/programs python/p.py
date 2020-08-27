num=int(input("enter no"))
i=2
while i<num:
    p=num%i
   
    if (p==0):
        print("not prime")
        break
    i+=1
else:
        print("prime no")
    
print("end")
