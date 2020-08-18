def findFactors(number):
    factor = 0
    for i in range(1, number//2):
        if(number % i == 0):
            factor = i
    return factor

print(findFactors(28))