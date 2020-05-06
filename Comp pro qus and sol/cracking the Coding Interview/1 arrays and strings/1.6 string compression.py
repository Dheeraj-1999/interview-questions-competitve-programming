string = input()
string += ' '
count = 1
output = ''
for i in range(1, len(string)):
    # if(i == len(string)):
    #     output += string[i-1]+str(count)
    # output += string[i-1]
    if(string[i-1] != string[i]):
        output += (string[i-1]+str(count))
        count = 0
        # continue
    count += 1
    # print(output, count)
print(output)


# refer better approach solution page 150 prblm 1.6 cracking the coding interview.
# String Builder approach is the better approach.

