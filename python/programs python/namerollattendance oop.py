class students:
    
    def __init__ (self):
        self.roll=int(input("enter roll number of student:"))
        #self.name=input("enter name of student:")
        self.attd=print("present or absent")


    def file(self):
        f=open("myfil.txt","r")
        copy=f.readlines()
        fp=open("my file.txt","a")
        a=f.write(str(copy[self.roll])+"\t ATTD:"+str(self.attd))
        f.close()
        fp.close()


a1=students()
a1.file()
