i=int(input("enter the first number"))
j=int(input("enter the second number"))
print("************welcome to the calculator app************\n")
n=input("""please enter \ 
'+'  \
'-'  \
'*'  \
'/'""")
while n!=0:

 if n== '+':
    print("your sum of numbers is:",i+j)
 elif n=='-':
    print("subtracion of given numbers is:",i-j)
 elif n=='*':
    print("multiplication is :",i*j)
 elif n =='/':
    print("division of two given numbers is:",i*j)
exit(input("enter 0 to exit"))

