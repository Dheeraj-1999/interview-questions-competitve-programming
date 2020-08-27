import requests
import json

print("    BANKING  APP      ")
print("1. add customer")
print("2. view customer")
print("3. deposit")
print("4. withdraw")
print("5. exit")

opt=int(input("enter your options"))



if opt==1:
    name=input("enter the name of new customer")
    bal=input("enter starting balance of new customer")
    url="https://niteshdsharma44.000webhostapp.com/addCustomer.php?name="+name+"&balance="+bal
    
    requests.get(url)


    

    
elif opt ==2:
    accn=input("enter the customer account number")

    
    url="https://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn

    reply=requests.get(url)


    print(reply.text)









   
elif opt==3:
    newamt=float(input("enter amount to deposit"))
    accn=input("enter the customer account number")

    
    url="https://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn

    reply=requests.get(url)


    data=json.loads(reply.text)
    bal=data["data"][0]["balance"]
    print("current balance is",bal)
    newbalance=float(bal)+newamt
    url="https://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn
    






   
elif opt==4:
    print("withdraw")
elif opt==5:
    print("exit")
else:
    print("invalid")
