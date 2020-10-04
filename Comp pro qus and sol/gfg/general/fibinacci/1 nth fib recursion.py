def nthfibRec(n):
    if(n == 1):
        return 1
    if n == 0:
        return 0
    return(nthfibRec(n-1) + nthfibRec(n-2))
    # return

n = int(input())
print(nthfibRec(n-1))

# 0 1 1 2 3 5 8