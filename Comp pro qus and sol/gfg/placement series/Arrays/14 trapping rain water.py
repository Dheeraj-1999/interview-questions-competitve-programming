def trappingWaterFailed(arr,n):
    maxi = max(arr)
    # print(maxi)
    smax = -1
    index = 0
    for i in range(n):
        if(arr[i] > smax):
            smax = arr[i]
            index = i
    water = 0
    for i in range(n-1):
        if(arr[i] == maxi):
            continue
        if(smax - arr[i] > 0 and index > i):
            water += smax - arr[i]
        print(water, end = ' ')
    print(water)


def trappedRainDp(arr, n):
    left = [0]*(n)
    right = [0]*(n)

    left[0] = arr[0]
    right[n-1] = arr[n-1]
    for i in range(1, n):
        left[i] = max(left[i-1], arr[i])
    for i in range(n-2, -1, -1):
        right[i] = max(right[i+1], arr[i])
    water = 0
    for i in range(n):
        water += min(left[i], right[i]) - arr[i]
    print(water)

arr = [int(i) for i in input().split(' ')]
trappedRainDp(arr, len(arr))