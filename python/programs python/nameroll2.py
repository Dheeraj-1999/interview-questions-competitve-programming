roll=input("enter yoyr roll")
name=input("enter your name")
f=open("myfile.txt","r")
for line in f:
    if (line==str(roll),"\t",str(name))and(line=="ROLL:\tNAME:"):
        print("your file exist")
    else:
        print("your file doesn't exist") 

    

