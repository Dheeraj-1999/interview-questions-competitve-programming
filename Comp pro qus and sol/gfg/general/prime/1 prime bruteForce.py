import math
def prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if(n%i == 0):
            return False
    return True

def nPrimes(n):
    primes = []
    for i in range(n+1):
        if(prime(i)):
            primes.append(i)
    return(primes)


n = int(input())
print(nPrimes(n))