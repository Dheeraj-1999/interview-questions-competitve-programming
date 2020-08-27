class students:
    
    def __init__ (self):
        self.roll=input("enter roll number of student:")
        self.name=input("enter name of student:")

    def file(self):
        f=open("myfil.txt","a")
        f.writelines("\nROLL:\t"+str(self.roll)+"\tNAME:\t"+str(self.name))
    def exit(self):
        self.opt=input("do you want to exit :\n yes: or no:")
        if self.opt=="yes":
            input("press enter to exit:")
        else:
            self.__init__()
            self.file()
            self.exit()

a1=students()
a1.file()
a1.exit()

                   
    
