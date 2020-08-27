roll=int(input("enter yur roll"))
try:
    f=open("myfile.txt","r+")
    a=f.readlines()
    print(a[roll])
    f.close()
except :
    print("your roll doesn't exist")
    input("please enter your roll again")
    name=input("enter your name")
    f=open("myfile.txt","a")
    f.write("\n"+str(roll)+"\t"+str(name))
    f.close()
    
    


