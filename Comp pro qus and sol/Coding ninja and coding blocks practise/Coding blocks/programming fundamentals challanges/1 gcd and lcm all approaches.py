def gcdBrute(n1, n2):
    for i in range((min(n1, n2)//2), 2, -1):
        if(n1%i == 0):
            return(i)
    return(1)
            
def gcdEuclidRec(n1,n2):
    # gcd(n1, n2) == gcd(n2, n1%n2) if n1 > n2
    if(n1 < n2):
        (n1, n2) = (n2, n1)
    # print(n1, n2)
    if(n2 == 0):
        print(n1)
        return n1
    gcdEuclid(n2, n1%n2)

def gcdEuclid(n1, n2):
    if(n1 < n2):
        (n1, n2) = (n2, n1)
    while(n2):
        temp = n2
        n2 = n1%n2
        n1 = temp
        print(n1, n2)
    print(n1)


# gcd*lcm == a*b
# to find lcm use above exp

n1 = int(input())
n2 = int(input())

(gcdEuclid(n1, n2))

