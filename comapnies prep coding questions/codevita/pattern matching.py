n = int(input())
fig = []
for i in range(3):
    fig.append(input().replace(' ', '')) 

O = '****.****'
A = '.*.****.*'
E = '*********'
I = '***.*.***'
U ='*.**.****'
a, e, i, o, u = [], [], [], [], []
for k in range(0, len(A), 3):
    a.append(A[k:k+3])
    e.append(E[k:k+3])
    i.append(I[k:k+3])
    o.append(O[k:k+3])
    u.append(U[k:k+3])

vowels = {}
vowels['A'] = a
vowels['E'] = e
vowels['I'] = i
vowels['O'] = o
vowels['U'] = u


used = [False for i in range(n)]
ans = ''
for i in range(n):
    if(fig[0][i] == "#" and fig[1][i] == "#" and fig[2][i] == "#"):
        ans += '#'
        used[i] = True
        continue
    
    # analyze the vowels
    if(i+2 < n):
        if(used[i] or used[i+1] or used[i+2]):
            continue
    
        # store the pattern
        pat = []
        for j in range(3):
            print(fig[j][i] + fig[j][i+1] + fig[j][i+2])
            pat.append(fig[j][i] + fig[j][i+1] + fig[j][i+2])
        print(pat)
        
        # match the pattern
        for seq in vowels:
            print(vowels[seq], pat)
            if(vowels[seq] == pat):
                ans += seq
                used[i], used[i+1], used[i+2] = True, True, True
                break

        print(ans, i)


# * . * # * * * # * * * # * * * . * .
# * . * # * . * # . * . # * * * * * *
# * * * # * * * # * * * # * * * * . *