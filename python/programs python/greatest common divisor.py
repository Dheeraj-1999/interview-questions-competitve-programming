def gcd(m,n):
    m=int(input("enter"))
    n=int(input("second"))
    fm = []
    for i in range(1,m+1):
        if (m%i)== 0 :
            fm.append(i)

    fn = []
    for j in range(1,n+1):
        if(n%j)==0:
            fn.append(j)

    cf=[]
    for k in fm:
        if k in fn:
            cf.append(k)

    return(cf[-1])
      
      
      
      
