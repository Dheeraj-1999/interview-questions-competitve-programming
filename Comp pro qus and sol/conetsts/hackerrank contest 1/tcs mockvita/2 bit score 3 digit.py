def make_pair(lis):
    ans = 0
    count = 0
    for i in range(len(lis)):
        count = 0
        for j in range(i+1, len(lis)):
            if(count == 2):
                # print(i, ans)
                # flag = True
                break
            if(lis[i] == lis[j]):
                count += 1
                ans += 1
    return ans

n = int(input())
numbers = [i for i in input().split(' ')]
# print(numbers)
even = []
odd = []
i = 0
while(i < n):
    num = sorted(numbers[i])
    ans = str(int(num[0])*7 + int(num[2])*11)
    if(i%2 == 0):
        even.append(ans[-2])
    else:
        odd.append(ans[-2])
    i += 1
# oddD = {}
# evenD = {}    
# for i in odd:
#     oddD[i] = 0
# for i in even:
#     evenD[i] = 0
# for i in even:
#     evenD[i] += 1
# for i in odd:
#     oddD[i] += 1
ans = 0
print(odd, even)
ans += make_pair(odd)
print(ans)
ans += make_pair(even)
print(ans)

