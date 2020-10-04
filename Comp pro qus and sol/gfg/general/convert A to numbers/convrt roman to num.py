
def getValue(r):
    if (r == 'I'): 
        return 1
    if (r == 'V'): 
        return 5
    if (r == 'X'): 
        return 10
    if (r == 'L'): 
        return 50
    if (r == 'C'): 
        return 100
    if (r == 'D'): 
        return 500
    if (r == 'M'): 
        return 1000
    return -1


def romanToNum(rNum):
    number = 0
    for i in range(len(rNum)-1):
        if(getValue(rNum[i]) >= getValue(rNum[i + 1])):
            number += getValue(rNum[i])
        else:
           number -= getValue(rNum[i])
    number += getValue(rNum[len(rNum)-1])
    return number



romanNumber = input()
print(romanToNum(romanNumber))