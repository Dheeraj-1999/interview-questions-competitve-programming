# Given an array A of positive integers. Your task is to find the leaders in the array.

# Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
# Also, the rightmost element is always a leader. 


# Scan all the elements from right to left in array and keep track of maximum till now.
#  When maximum changes it’s value, print it


def leaders(A, n):
    ans = []
    maxi = A[n-1]
    ans.append(maxi)
    for i in range(len(A)-2,-1, -1):
        if(A[i] >= maxi):
            maxi = A[i]
            ans.append(maxi)
    ans.reverse()
    return(ans)