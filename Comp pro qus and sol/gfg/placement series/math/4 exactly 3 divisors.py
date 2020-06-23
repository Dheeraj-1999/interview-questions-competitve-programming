import math

def primeSeive(array, n):
    # mark all odd numbers as prime
    for i in range(3, n+1, 2):
        array[i] = 1
    
    for i in range(3, n+1, 2):
        if(array[i] == 1):
            for j in range(i*i, n+1, i): #another optimization in i*i
                array[j] = 0
    array[2] = 1
    array[1] = array[0] = 0
    return array

def exactly3Divisors(n):
    num = 0
    for i in range(2, int(math.sqrt(n))+1):
        if(array[i]):
            # print(i*i, end = ' ')
            num += 1
    print(num)

n = int(input())
array =  [0]*(n+1)
    # primes = []
for i in range(3, n+1, 2):
    array[i] = 1

for i in range(3, n+1, 2):
    if(array[i] == 1):
        for j in range(i*i, n+1, i): #another optimization in i*i
            array[j] = 0
array[2] = 1
array[1] = array[0] = 0
exactly3Divisors(n)