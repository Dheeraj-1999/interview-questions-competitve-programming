# Smallest divisible number

# Given a number n the task is to complete the function which returns an integer 
# denoting the smallest number evenly divisible by each number from 1 to n.

# Input:
# The first line of input contains an integer T denoting the 
# no of test cases then T test cases follow. Each line contains an integer N.

# Output:
# For each test case output will be in new line denoting the smallest number 
# evenly divisible by each number from 1 to n.

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

def smalNumberFailed(n):
    array =  [0]*(n+1)
    primes = []
    primeSeive(array, n)
    for i in range(len(array)):
        if(array[i]):
            primes.append(i)
    lcm = 1
    for i in primes:
        lcm *= i
    for i in primes:
        if(i*i <= n):
            lcm *= i
    print(lcm)
import math
def smalNumber(n): # lcm of all numbers till n
    ans = 1
    for i in range(2, n+1):
        temp = math.gcd(ans, i);
        ans = (ans*i)//temp
    print(ans)

n = int(input())
smalNumber(n)