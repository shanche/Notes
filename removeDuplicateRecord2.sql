BEGIN
DROP TABLE IF EXISTS Max_ID_shan ;
END;
BEGIN
CREATE TABLE Max_ID_shan (SELECT MAX(ID) FROM bankbalanceshistory_shantest WHERE postingdate = '2015-07-29' GROUP BY bankaba) ;
END;
BEGIN
SELECT *  FROM bankbalanceshistory_shantest WHERE  ID IN (SELECT *  FROM Max_ID_shan);
END;
BEGIN
DROP TABLE IF EXISTS devusbfica.Max_ID_shan ;
END;