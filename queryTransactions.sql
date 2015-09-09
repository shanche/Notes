SELECT * FROM transactions WHERE Postingdate LIKE '%2013%'  AND Amount < 0
SELECT * FROM transactions WHERE clientid = 104790617526 AND Amount < 0
SELECT DISTINCT postingdate FROM transactions WHERE  Amount < 0
SELECT SUM(amount) FROM transactions WHERE  Amount < 0
