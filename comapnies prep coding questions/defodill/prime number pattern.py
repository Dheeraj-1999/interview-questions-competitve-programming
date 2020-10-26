from math import sqrt
def primeseive(n):

    seive = [True for i in range(n)]
    seive[0], seive[1] = False, False
    for i in range(2, int(sqrt(n))):
        if(seive[i]):  
           for j in range(i*i, n, i):
               seive[j] = False

    primes = []
    for i in range(len(seive)):
        if(seive[i]):
            primes.append(i)
    return primes


def primePattern(n):
    primes = primeseive(100)
    for i in range(n):
        print(primes[:i])

n = int(input())
primePattern(n)
