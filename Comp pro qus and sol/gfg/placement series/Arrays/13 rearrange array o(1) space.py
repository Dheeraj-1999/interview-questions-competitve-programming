# Given an array arr[] of size N where every element is in the range from 0 to n-1.
# Rearrange the given array so that arr[i] becomes arr[arr[i]]. 


# *********HINT************************HINTS******************************HINT******************


# Here, We will use the formula Dividend = Divisor * Quotient + Remainder
# where Divisor = size of array
#            Quotient = New number at index i after rearrangement
#            Remainder = Old Number at index i before rearrangement
#            Dividend = The number stored at index i

# While Traversing the array, we will Look for the value at arr[arr[i]] 
# (which is to be stored at index i), 
# multiply it with Divisor (size of array), and add the old value present at arr[i] to it.
# Divisor is a value which is higher then values in array 
# (in this case n - size of array, as array elements are between 0 to n-1)

# Obviously, don't forget to remove the multiplier n from the values while accessing and outputting the new values.

# https://www.youtube.com/watch?v=Zq208EIYTu8

def rearrange(arr, n):

    old =  arr[0] 
    new = arr[arr[0]]
    arr[0] = (n*new + old)
    for i in range(1, n):
        old =  arr[i] 
        new = arr[arr[i]]%n  # for accessing previous value eg. 19(new value) % 5(size) == 4(previous value)
        arr[i] = (n*new + old) # arr[i] += (arr[arr[i]]%n) * n
    print(arr)
    for i in range(n):
        arr[i] /= n
        arr[i] =  int(arr[i])
    print(arr)


arr = [int(i) for i in input().split(' ')]
rearrange(arr, len(arr))