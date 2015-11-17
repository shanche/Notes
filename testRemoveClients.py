import MySQLdb
import datetime
from datetime import date
from random import randint
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


db = MySQLdb.connect(host = "yoda",user = "root", passwd = "mysql", db = "devusbfica")
cur = db.cursor()

cur.execute("SELECT DISTINCT clientID FROM fisagl")
allClientData = cur.fetchall()[0:]
exClientID = []

cur.execute("UPDATE algo_exclude_accounts SET effective = \'N\'")
db.commit()


for row in allClientData:
    exClientID.append(row[0])

cur.execute("UPDATE algo_exclude_clients SET effective = \'N\'")
db.commit()
    
totalClientCount = int(len(exClientID)/30)
#totalClientCount = len(exClientID)
numClientToExclude = randint(0,totalClientCount-1)

for i in range(numClientToExclude):
    index = randint(0,totalClientCount-1)
    cur.execute("UPDATE algo_exclude_clients SET effective = \'Y\' WHERE clientID = " + exClientID[index])
    db.commit()

cur.execute("SELECT * FROM algo_exclude_clients where effective = \'Y\'")
b = cur.fetchall()[0:]

#get the client level allocation before the Daily
cur.execute("SELECT clientid, subacctid, SUM(amount) AS sumamt FROM fisagl WHERE account = 1001 GROUP BY clientid, subacctid ORDER BY sumamt ")
db.commit()
beforeTrans = cur.fetchall()[0:]

cur.close()

db.close()

"""
URL = "http://localhost:8080/Falcon/Falcon.html"
driver = webdriver.Chrome()
driver.get(URL)
driver.switch_to_window(driver.current_window_handle)
inputElement = driver.find_element_by_name("User ID")
inputElement.send_keys('admin')
inputElement = driver.find_element_by_id("password")
inputElement.send_keys('test')
inputElement.submit()
"""




