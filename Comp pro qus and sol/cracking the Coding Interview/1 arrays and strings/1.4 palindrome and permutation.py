string = input().strip(' ')
string = string.replace(" ", "")
def pal(string):
    checker = {}
    for i in string:
        checker[i] = 0
    for i in string:
        checker[i] += 1
    print(len(string))
    if(len(string)%2 == 0):
        for i in checker:
            if(checker[i]%2 != 0):
                print(checker[i], " not a palindrome")
                return
        print("is palindrome")
    else:
        flag = True
        for i in checker:
            print(checker[i], flag)
            if(checker[i]%2 != 0 and flag == True):
                flag = False
                continue
            if(flag == False):
                print(checker[i], " not a palindrome")
                return
        print("is palindrome")
    # print(checker)
pal(string)
