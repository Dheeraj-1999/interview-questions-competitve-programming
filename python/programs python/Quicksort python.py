
def partition(a,low,high):
    pivot=a[high]
    i=low-1
    for j in range(low,high):
        if a[j]<=pivot:
            i=i+1
            (a[i],a[j])=(a[j],a[i])
    (a[i+1],a[high])=(a[high],a[i+1])
    return i+1
def Quicksort(a,low,high):
    if low<high:
        pi=partition(a,low,high)
        Quicksort(a,pi+1,high)
        Quicksort(a,low,pi-1)


a=[100,90,80,70,60,50,40,30,20,10,0]
n=11

Quicksort(a,0,n-1)
print(a)
