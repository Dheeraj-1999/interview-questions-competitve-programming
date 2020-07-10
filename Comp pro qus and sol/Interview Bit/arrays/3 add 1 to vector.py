n = [int(i) for i in input().split(' ')]
string = ''
for i in n:
    string += str(i)
num = int(string)+1
print(list(str((num))))


# list(str(int("".join(list(map(str,n))))+1))

