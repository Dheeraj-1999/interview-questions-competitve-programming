import os
# Complete the gridChallenge function below.

def is_sorted(l):
    if(all(l[i] <= l[i+1] for i in range(len(l)-1))):
        return True

def gridChallenge(grid, n):
    vertical_grid = []
    rows = n
    cols = len(grid[0])
    for i in range(cols):
        temp = ''
        # print(n, len(grid[0]))
        for j in range(rows):
            temp += grid[j][i]
        # print(temp)
            # print(sorted(i))
    
        vertical_grid.append(temp)
    print(vertical_grid)
    for i in vertical_grid:
        print(i, (is_sorted(i)))
        if(not(is_sorted(i))):
            return('NO')
    return('YES')

    
    # return ('True')

t = int(input())

for t_itr in range(t):
    n = int(input())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(sorted(grid_item))
    result = gridChallenge(grid, n)
    print(result)


