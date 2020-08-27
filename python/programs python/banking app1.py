import requests
import json
print("BANKING APP")
print("1. ADD CUSTOMER")
print("2. VIEW CUSTOMER")
print("3.DEPOSIT")
print("4.WITHDRAW")
print("5.TRANSFER")
print("6.EXIT")
opt=int(input("enter option"))
if(opt==1):
    name=input("enter customer name")
    bal=input("enter balance")
    url="http://niteshdsharma44.000webhostapp.com/addCustomer.php?name="+name+"&balance="+bal
    requests.get(url)
elif opt==2:
    accn=input("enter account no")
    url="http://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn
    reply=requests.get(url)
    print(reply.text)
elif opt==3:
    newamount=float(input("enter newdeposit"))
    accn=input("enter account no")
    url="http://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn
    reply=requests.get(url)
    data=json.loads(reply.text)
    bal=data["data"][0]["balance"]
    newbalance=float(bal)+newamount
    url="http://niteshdsharma44.000webhostapp.com/updateBalance.php?accno="+accn+"&balance="+str(newbalance)
    reply=requests.get(url)

    print(newbalance)
elif opt==4:
    newamount=float(input("enter withdrawamount"))
    accn=input("enter account no")
    url="http://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn
    reply=requests.get(url)
    data=json.loads(reply.text)
    bal=data["data"][0]["balance"]
    newbalance1=float(bal)-newamount
    url="http://niteshdsharma44.000webhostapp.com/updateBalance.php?accno="+accn+"&balance="+str(newbalance1)
    reply=requests.get(url)
    print(newbalance1)
elif opt==5:
    newamount=float(input("enter transfer_amount"))
    accn=input("enter account no of sender")
    accnin=input("enter account no of reciever")
    url="http://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accnin
    reply=requests.get(url)
    data=json.loads(reply.text)
    bal=data["data"][0]["balance"]
    newbalance12=float(bal)+newamount
    url="http://niteshdsharma44.000webhostapp.com/updateBalance.php?accno="+accnin+"&balance="+str(newbalance12)
    reply=requests.get(url)
    

    url="http://niteshdsharma44.000webhostapp.com/viewCustomer.php?accn="+accn
    reply=requests.get(url)
    data=json.loads(reply.text)
    bal=data["data"][0]["balance"]
    newbalance13=float(bal)-newamount
    url="http://niteshdsharma44.000webhostapp.com/updateBalance.php?accno="+accn+"&balance="+str(newbalance13)
    reply=requests.get(url)
    print("amount in sender account",newbalance13)
    print("amount in reciever account",newbalance12)
    

elif opt==6:
    input("enter any key to exit")
    
    
    







    
    
    
