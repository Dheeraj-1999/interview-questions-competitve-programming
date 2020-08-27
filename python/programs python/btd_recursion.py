num=int(input("enter no"))
i=2
while(i<num):
    p=num%i
    if(p==0):
        i+=1
        print("np")
    else:
        print("p")
        break
