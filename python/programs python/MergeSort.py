def MergeSort(A,left,right):
    if  right-left<=1:
        return(A[left:right])
    if right-left>1:
        mid=(right+left)//2
        l=MergeSort(A,left,mid)
        r=MErgeSort(A,mid,right)

        return(Merge(l,r))
def Merge(a,b):
    m=len(a)
    n=len(b)

    (i,j,c)=(0,0,[])
    while (i+j)<(m+n):
        if i==m:
            c.append(b[j])
            j=j+1
        elif j==n:
            c.append(b[i])
            i=i+1
        elif a[i]<=b[j]:
            c.append(a[i])
            i=i+1
        elif a[i]>b[j]:
            c.append(b[j])
            j=j+1
        return c
        
