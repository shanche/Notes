import MySQLdb
import datetime
from datetime import date
from random import randint
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


db = MySQLdb.connect(host = "yoda",user = "root", passwd = "mysql", db = "devusbfica")
cur = db.cursor()

cur.execute("SELECT * FROM pendgl WHERE account <> 1001 ")
db.commit()
bankJ = cur.fetchall()[0:]

if len(bankJ) == 0 :
    print("The allocation is right")
