string = input()
output = ""
for i in string:
    if i== " ":
        output += "%20"
    else:
        output += i
print(output)