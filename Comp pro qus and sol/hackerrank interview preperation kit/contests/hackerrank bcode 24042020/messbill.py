t = int(input())
while(t > 0):
    name = input()
    roll = input()
    splMeals = int(input())
    bfMeals = int(input())
    luMeals = int(input())
    diMeals = int(input())
    others = int(input())

    print(name, roll)
    toMeals = splMeals+bfMeals+luMeals+diMeals
    print(toMeals)
    
    NorAddedMeals = 0
    if(toMeals < 40):
        NorAddedMeals = 40 - toMeals + splMeals
    print(NorAddedMeals)
    
    splAddedMeals = 0
    if(splMeals < 2):
        splAddedMeals = 2 - splMeals
    print(splAddedMeals)

    billAmount = ((luMeals+diMeals+NorAddedMeals)*50 + (bfMeals*40) + (splMeals+splAddedMeals)*100 + others)
    print(billAmount)
    
    tax = 0
    if(billAmount > 3000):
        tax = 0.04*billAmount
    print(int(tax))

    total = tax + billAmount
    print(int(total))

    t -= 1






