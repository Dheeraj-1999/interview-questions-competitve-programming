k=1
for  i in range(4,0,-1):
    for j in range(1,5):
        if k>=i:
            print(k,end=" ")
        else:
            print(" ",end="  ")
        k=k+1
    print("")
    k=1
