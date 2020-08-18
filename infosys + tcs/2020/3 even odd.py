from itertools import product

lowRange, highRange = [int(i) for i in input().split(' ')]
k=int(input())
allPermu = product(range(lowRange, highRange+1), repeat=k)
answer = 0
for triplet in allPermu:
    if(sum(triplet)%2 == 0):
        answer += 1
answer %= 100000007 
print(answer)