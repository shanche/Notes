# set all the clients to removed as "N", not effective
import MySQLdb
from random import randint

db = MySQLdb.connect(host = "yoda",user = "root", passwd = "mysql", db = "devusbfica")
cur = db.cursor()
randSelect = False

cur.execute("SELECT DISTINCT clientID, subacctid FROM fisagl")
allClientData = cur.fetchall()[0:]
exClientID = []
exSubacctID = []

cur.execute("DROP TABLE algo_exclude_clients")

cur.execute("CREATE TABLE algo_exclude_clients(clientID VARCHAR(45),subacctID VARCHAR(45),effective VARCHAR(1),reason VARCHAR(255))")

for row in allClientData:
    if (bool(row[0])):
        cur.execute("INSERT INTO algo_exclude_clients (clientID, subacctID, effective, reason) VALUE (\'" + row[0] + "\', \'" + row[1] + "\', \'N\', \'\')")        
        exClientID.append(row[0])
        exSubacctID.append(row[1])
        db.commit()

if (randSelect) :
        
    totalClientCount = int(len(exClientID)/2)
    numClientToExclude = randint(0,totalClientCount-1)

    for i in range(numClientToExclude):
        index = randint(0,totalClientCount-1)
        cur.execute("UPDATE algo_exclude_clients SET effective = \'Y\' WHERE clientID = \'" + exClientID[index] + "\'AND subacctID = \'" + exSubacctID[index] + "\'")
        db.commit()

else:
    cur.execute("SELECT bankaba,bankaccount, clientid, subacctid, availablebalance  FROM clients WHERE availablebalance < 10000 ")
    db.commit()
    ClientToExclude = cur.fetchall()[0:]
    exClientID = []
    exSubacctID = []
    for row in ClientToExclude:
        if (bool(row[2])):
            exClientID.append(row[2])
            exSubacctID.append(row[3])            

    for i in range(len(exClientID)):
        cur.execute("UPDATE algo_exclude_clients SET effective = \'Y\' WHERE clientID = \'" + exClientID[i] + "\'AND subacctID = \'" + exSubacctID[i] + "\'")
        db.commit()
    
    

cur.execute("SELECT * FROM algo_exclude_clients where effective = \'Y\'")
b = cur.fetchall()[0:]

cur.close()

db.close()



