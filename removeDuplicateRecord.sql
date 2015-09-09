SELECT *  FROM bankbalanceshistory_shantest WHERE  ID IN ( SELECT id FROM  (( SELECT MAX(ID)  AS id  FROM bankbalanceshistory_shantest WHERE postingdate = '2015-07-29' GROUP BY bankaba )  AS shan))
