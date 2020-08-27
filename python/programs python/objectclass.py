class bag:
    def __init__(self):


        self.pockets=input("enter number of pockets")
        self.brand=input("enter brane of bag")
        self.quality=input("quality of bag")

    def print(self):
        print(self.pockets)
        print(self.brand)
        print(self.quality)


a1=bag()
a1.print()
