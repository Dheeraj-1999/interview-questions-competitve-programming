def thirdLargest(arr, n):
    lar = arr[0]
    sLar = -1 
    tLar = -1
    for i in range(1, len(arr)):
        if(arr[i] < lar and arr[i] > sLar):
            tLar = sLar
            sLar = arr[i]
        if(arr[i] < sLar  and arr[i] > tLar):
            tLar = arr[i]
        if(arr[i]> lar):
            tLar = sLar
            sLar = lar
            lar = arr[i]
            
    print(lar, sLar, tLar)

def thirdLargest2(arr, n):
    big1 = -1
    big2 = -1
    big3 = -1
    
    for i in arr:
        if i > big3 and i != big2 and i != big1:
            big3 = i
        
        if big3 > big2:
            big2, big3 = big3, big2
        
        if big2 > big1:
            big1, big2 = big2, big1
        # print(big1, big2, big3)
    lis = []
    if(big3 != -1):
               
        lis = ([big3, big2, big1])
        print(len(lis)) 
        return lis
    else:
        print(len(lis))
        return(lis)

arr1 = [int(i) for i in input().split(' ')]
lis = thirdLargest2(arr1, len(arr1))
print(lis)