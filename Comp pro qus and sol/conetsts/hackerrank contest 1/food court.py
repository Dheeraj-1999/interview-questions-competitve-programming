# // FOOD FEST (100 MARKS)

# // A food fest is organised at the JLN stadium. 
# // The alls from different states and cities have been set up. 
# // To make the test more interesting, multiple games have been arranged which can be played
# //  by the people to win the food vouchers. One such game to win the food vouchers is described below:

# // There are N number of boxes arranged in a singe queue Each box has an integer I written on it. From the

# // ghen queue, the participant has to select two contiguous subsequences A and B of the same size. The

# // selected subsequences should be such that the summation of the product of the boxes should be maximum. 
# // The product is not calculated anomaly though, To make the game interesting the 
# // first box of subsequence A is to be muted by the last box of subsequence B.
# //  The second box of subsequence As to be compiled by the second last box of subsequence
# //  Band sa on Al the products thus obtained are then added together

# // I the participant is able to in the connected ch macitum ammatie nerhel n he game and wil be

# // awarded the food voucher of the same vale
from sys import maxsize
def maxSubArraySum(a,size): 
       
    max_so_far = -maxsize - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
  
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 
    
def applyKdane(kdaneMatrix):
    ans = -maxsize - 1
    for sub in kdaneMatrix:
        max_So_far = maxSubArraySum(sub, len(sub))
        ans = max(ans, max_So_far)
    print(ans)

def solve(arr):
    matrix = []

    for i in range(len(arr)-1):
        temp = []
        for j in range(i+1):
            temp.append(0)
        for j in range(i+1, len(arr)):
            if(arr[i] != arr[j]):
                temp.append(arr[i]* arr[j])
            else:
                temp.append(0)
        matrix.append(temp)


    kdaneMatrix = []
    for i in range(1, len(arr)):
        p = 0
        q = i
        temp = []
        while(p<q):
            temp.append(matrix[p][q])
            p += 1
            q -= 1
        kdaneMatrix.append(temp)
    
    for i in range(0, len(arr)-1):
        p = i
        q = len(arr)-1
        temp = []
        while(p<q):
            temp.append(matrix[p][q])
            p += 1
            q -= 1
        kdaneMatrix.append(temp)
    # print(matrix)
    print(kdaneMatrix)
    applyKdane(kdaneMatrix)

arr = [int(u) for u in input().split(" ")]
solve(arr)
