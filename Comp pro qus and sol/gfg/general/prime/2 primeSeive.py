from math import sqrt

def primeSeive(n):
    seive = [1]*(n+1)

    seive[0] = 0
    seive[1] = 0

    for i in range(2, int(sqrt(n))+1):
        for j in range(i*i, n+1, i):
            seive[j] = 0
    return seive

def nPrimes(seive):
    for i in range(len(seive)):
        if seive[i] == 1:
            print(i, end = ' ')


n = int(input())
seive = primeSeive(n)
nPrimes(seive)

