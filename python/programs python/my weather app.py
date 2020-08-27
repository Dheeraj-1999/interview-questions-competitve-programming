import requests
import json
city=input("enter your city")
url="http://api.openweathermap.org/data/2.5/weather?q="+city+"&sangrur,india&appid=fd097768de0a389a66b77f98a9f5f044"
reply=requests.get(url)
data=json.loads(reply.text)
#print(reply.text)
print(data["weather"][0]["description"])
print(data["main"]["temp"])


