def distantAdjacentElement(a, n):

    # dict used to count the frequency
    # of each element occurring in the
    # array
    m = dict()

    # In this loop we count the frequency
    # of element through map m
    for i in range(n):
        if a[i] in m:
            m[a[i]] += 1
        else:
            m[a[i]] = 1

    # mx store the frequency of element which
    # occurs most in array .
    mx = 0

    # In this loop we calculate the maximum
    # frequency and store it in variable mx.
    for i in range(n):
        if mx < m[a[i]]:
            mx = m[a[i]]

# By swapping we can adjust array only
# when the frequency of the element
# which occurs most is less than or
# equal to (n + 1)/3.
    if mx > (n+1) // 3:
        print("Yes")
    else:
        print("No")

a = [int(i) for i in input().split(' ')]
n = len(a)
distantAdjacentElement(a, n)