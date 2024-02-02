SELECT name FROM Customer
WHERE IFNULL(referee_id, 1) <> 2;