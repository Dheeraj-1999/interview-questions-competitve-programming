k=4
for i in range(1,5):
    for j in range(1,5):
        if k<=i:
            print(k,end=" ")
        else:
            print(" ",end=" ")
        k-=1
    print("")
    k=4
    
