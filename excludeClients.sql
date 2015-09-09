SELECT * FROM algo_exclude_accounts

CREATE TABLE algo_exclude_clients
(
clientID VARCHAR(45),
subacctID VARCHAR(45),
effective VARCHAR(1),
reason VARCHAR(255)
)
SELECT * FROM algo_exclude_clients
 
INSERT INTO algo_exclude_clients (clientID, subacctID, effective, reason) VALUE ('104791109861', '', 'Y', '')

DROP TABLE algo_exclude_clients

