def primeSeive(array, n):
    # mark all odd numbers as prime
    for i in range(3, n+1, 2):
        array[i] = 1
    for i in range(3, n+1, 2):
        if(array[i] == 1):
            for j in range(i*i, n+1, i):
                array[j] = 0
    array[2] = 1
    array[1] = array[0] = 0
    return array

n = int(input())
array =  [0]*(n+1)
primes = []
primeSeive(array, n)
# print(array)
for i in range(len(array)):
    if(array[i]):
        primes.append(i)
print(primes)