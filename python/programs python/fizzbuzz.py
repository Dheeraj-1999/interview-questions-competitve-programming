a=int(input("enter a decimal number:"))
c=0
while a>0:
  b=a%2
  c=c+b
  c=c*10
  a=a//2
c=c//10
print(c)
