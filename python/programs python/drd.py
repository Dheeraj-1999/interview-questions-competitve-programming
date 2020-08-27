import pymysql
roll_number =input("enter the roll_number")
name = input("enter the name")

gender = input("enter the gender")
marks=input("enter the marks")

con=pymysql.connect("localhost","root","Dheeraj@1999","d")
cur=con.cursor()
cur.execute("insert into t values({},'{}',{},'{}')".format(roll_number,name,marks,gender))
con.connect()
cur.close()
con.close()
