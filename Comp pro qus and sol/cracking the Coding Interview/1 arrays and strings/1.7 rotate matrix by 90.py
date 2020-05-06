matrix = []
n = int(input())
for i in range(n):
    matrix.append([int(j) for j in input().split(' ')])
print(matrix)
# layer = -1
for layer in range((n//2)):
    # layer += 1
    for j in range(layer, n-layer-1):
        temp = matrix[layer][j]
        # 0,0 to 0,4
        # 0,4 to 4,4
        # 4,4 to 4,0
        # 4,0 to 0,0
        matrix[layer][j] = matrix[n-1-j][layer]
        matrix[j][layer] = matrix[n-1][j]
        matrix[n-1][j] = matrix[n-j-1][n-1]
        matrix[j][n-layer-1] = temp
        print(layer,j)
print(matrix)
