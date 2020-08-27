a=[]
for i in range(0,6):
    a=int(input("enter the numbers in your array"))

key=int(input("enter the number you want to find"))
l=-1
r=6
mid=int(l+r/2)


  

    if(key>=mid):
        l=mid

    else:
        r=mid
if(l>=0 and a[mid]==key):
    print(l)
else:
    print("no")

    
    
    
