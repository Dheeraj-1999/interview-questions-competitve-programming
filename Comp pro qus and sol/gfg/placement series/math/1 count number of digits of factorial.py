n = int(input())

# Solution 1 0(n)

def countDigit(n):
    if(n == 0):
        return 0
    return(1+countDigit(n//10))

def countDigitIter(n):
    count = 0
    while(n != 0):
        count += 1
        n //= 10
    return count


# Solution 2: optimized O(1)

# number of digits in N = log10(N) + 1
import math
def countDigitOpt(n):
    ans = math.log10(n) + 1
    return((ans))


def countDigitFact(n):
    digits = 0
    for i in range(2, n+1):
        digits += math.log10(i)
        print(digits, end = ' ')
    print()
    return(digits) 

print(math.floor(countDigitFact(n)))