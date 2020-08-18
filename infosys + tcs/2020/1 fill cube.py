def transpose(l1, l2): 
    for i in range(len(l1[0])): 
        row =[] 
        for item in l1: 
            row.append(item[i]) 
        l2.append(row) 
    return l2 

def count_D_column(input_array):
  max=0
  for i in input_array:
    count_D = i.count("D")
    if count_D>max:
      max=count_D
  return max

def size_of_biggest_C(input_array):
  row_R = 0      # without rotation
  row_W_R = 0   

  input_array_rotate = []
  input_array_rotate = transpose(input_array, input_array_rotate)
  
  row_R = count_D_column(input_array)
  row_W_R = count_D_column(input_array_rotate)

  if len(input_array)>3:
    row_W_R-=1
  return min(row_R, row_W_R)

import math
n=int(input())
cube = []
for i in range(n):
    cube.append([i for i in input().split(' ')])
# count = fillCube(cube)
# print(size_of_biggest_C(cube))
print(math.floor(math.sqrt(size_of_biggest_C(cube))))