# We define super digit of an integer

# using the following rules:

# Given an integer, we need to find the super digit of the integer.

#     If 

# has only digit, then its super digit is
# .
# Otherwise, the super digit of
# is equal to the super digit of the sum of the digits of

#     .

# For example, the super digit of

# will be calculated as:

# 	super_digit(9875)   	9+8+7+5 = 29 
# 	super_digit(29) 	2 + 9 = 11
# 	super_digit(11)		1 + 1 = 2
# 	super_digit(2)		= 2  
def superDigit(string, k):
    if(len(string) == 1):
        print(string)
        return
    sumDigit = 0
    for  i in string:
        sumDigit += int(i)
    # print(sumDigit)
    superDigit(str(sumDigit), k)

nk = input().split()
n = nk[0]
k = int(nk[1])
# superDigit(n*k, k)
# print(result)123 3
l = [0]*100
print(l)
# string = "abs"
# print(string*3)
