def modInverse(a,m):
    for i in range(1,m):
        if(((i*a) % m) == 1):
            return i
    return -1