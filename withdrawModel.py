import MySQLdb
import datetime
from datetime import date 
import matplotlib.pyplot as plt

db = MySQLdb.connect(host = "yoda",user = "root", passwd = "mysql", db = "devusbfica")
cur = db.cursor()
cur.execute("SELECT * FROM transactions  WHERE  amount<0 ")
transData = cur.fetchall()[0:]
earliest = date.today()
freqWithdrawClient = []
##########client level withdraws ########################################################
clientData = {} # ID:transaction
drawCount = {}
clientStayLength = {}
ID = ""
transaction = {}
entry = {"":{}}
countClient = {}
for row in transData:
    if earliest > row[3]: earliest = row[3]

for row in transData:
    ID = row[4] + "|" +row[5]
    
    transaction = {(row[3]-earliest).days :row[6]} # transaction = date:withdraw amt
    entry = {ID:transaction}

    if ID in clientData:
        clientData[ID].update(transaction)
        drawCount[ID] = drawCount[ID] + 1
    else:
        clientData.update(entry)
        drawCount.update({ID:1})

for key in clientData:
    clientStayLength.update({key:max(clientData[key].keys())})


for key in drawCount.keys():
    if (drawCount[key] > 30) :
        freqWithdrawClient.append(key)
        

##########total withdraw#######################################################
totalData = {}

draw = float(0.0)
for row in transData:
    date = (row[3]-earliest).days
    draw = float(row[6])
    if date in totalData:
        totalData[date] = totalData[date] + draw
        countClient[date] = countClient[date] + 1
    else:
        totalData.update({date:draw})
        countClient.update({date:1})
#plot total###############################################################
        """
x = []
y = []
z = []
for key in totalData.keys():
    x.append(key)
    y.append(totalData[key])
    z.append(countClient[key])
    
z = [3000000*a for a in z] 

plt.scatter(x,y, color='red')
plt.scatter(x,z)
"""
#plot each client ############################################################

x = []
y = []
dic = clientData[freqWithdrawClient[27]]
for key in dic.keys():
    x.append(key)
    y.append(dic[key])

plt.scatter(x,y, color='red')
"""
x = []
y = []
z = []

k= 0
for key in clientStayLength.keys():
    if (k<820):
        k=k+1
        x.append(key)
        y.append(clientStayLength[key])
        z.append(drawCount[key])
   
plt.bar(range(len(x)),z, align = 'center')
"""
#plt.bar(range(len(x)),z, align = 'center')

#plt.xticks(range(len(totalData)), list(totalData.keys()))

plt.show()

