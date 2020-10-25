from math import sqrt, floor

def createBaseseive(limit, primes):
    # baseSeive = [True for i in range(int(sqrt(high)+1))]


    # for i in range(2, int(sqrt(high))+1):
    #     if(baseSeive[i] == True):
    #         for j in range(i*i, int(sqrt(high))+1, i):
    #             # print(j, end = " ")
    #             baseSeive[j] = False
    # return baseSeive

    mark = [False]*(limit+1)
     
    for i in range(2, limit+1):
        if not mark[i]:
             
            # If not marked yet, 
            #then its a prime
            primes.append(i)
            for j in range(i, limit+1, i):
                mark[j] = True

def segmentedPrimeSeive(low, high):

    limit = int(sqrt(high)) + 1
    primes = []
    createBaseseive(limit, primes)
    
    n = high - low + 1
    mark  = [False]*(n)


    for i in range(len(primes)):
        # Find the minimum number in [low..high] that is a multiple of prime[i] (divisible by prime[i])
        firstNumber = (floor(low/primes[i])) * primes[i]
        if(firstNumber < low):
            firstNumber += primes[i]
        if firstNumber == primes[i]:
            firstNumber += primes[i]

        # mark all the multiples of primes[i] in low-high range as non primes
            
        for j in range(firstNumber, high+1, primes[i]):
            if(j != primes[i]):
                mark[j-low] = True
        
    for i in range(len(mark)):
        if not mark[i]:
            print(i+low, end = " ")
    # for i in range(low, high+1):
    #     if not mark[i-low]:
    #         print(i, end = " ")



low, high = map(int, input().split(" "))
segmentedPrimeSeive(low , high)
# nPrimes(seive)
