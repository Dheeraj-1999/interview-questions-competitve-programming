class vehicle:


    def __init__(self):
        self.number=input("entr your vehicle number")
        self.owner=input("owner name")
        self.phone=input("phone")

    def print(self):
        print(self.number)
        print(self.owner)
        print(self.phone)

truck=vehicle()
truck.print()
