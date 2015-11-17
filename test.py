import MySQLdb
import datetime
from datetime import date
from random import randint


db = MySQLdb.connect(host = "yoda",user = "root", passwd = "mysql", db = "devusbfica")
cur = db.cursor()

cur.execute("SELECT * FROM algo_exclude_clients")
a = cur.fetchall()[0:]
