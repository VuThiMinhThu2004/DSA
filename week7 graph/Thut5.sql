Cau 1:
SELECT SUBSTR(productCode,2,2) as product_Scale, COUNT(*)
FROM products 
GROUP BY product_Scale;



Cau 2:
SELECT customerNumber, DATEDIFF("2005-06-12", MAX(orderDate)) AS recency, COUNT(*) AS frequency
FROM orders
GROUP BY customerNumber
HAVING recency < 50 OR frequency > 20;



Cau 3:
SELECT customerName, phone
FROM customers
WHERE creditLimit > 200000 AND (phone LIKE '%00000%' OR phone LIKE '%11111%' OR phone LIKE '%22222%' OR
phone LIKE '%33333%' OR phone LIKE '%44444%' OR phone LIKE '%55555%' 
OR phone LIKE '%66666%' OR phone LIKE '%77777%' OR phone LIKE '%88888%' 
OR phone LIKE '%99999%');


Cau 4:
SELECT productLine, SUM(quantityInStock * buyPrice) AS totalInventoryMoney
FROM products
GROUP BY productLine
ORDER BY totalInventoryMoney
LIMIT 1;


Cau 5:
SELECT
CASE
WHEN SUBSTR(customerName, -2) = 'Co' or 
SUBSTR(customerName, -3) = 'Co.' THEN 'Co'
WHEN SUBSTR(customerName, -3) = 'Ltd' or
SUBSTR(customerName, -4) = 'Ltd.' THEN 'Ltd'
WHEN SUBSTR(customerName, -3) = 'Inc' or 
SUBSTR(customerName, -4) = 'Inc.' THEN 'Inc'
ELSE 'Other' END AS business_cat,
COUNT(*) total
FROM customers 
GROUP BY business_cat;


Cau 6:
CREATE DATABASE sampleDatabase;
USE sampleDatabase;



Cau 7:
SELECT salesRepEmployeeNumber, COUNT(customerNumber) AS CustomerCount
FROM customers
WHERE salesRepEmployeeNumber IS NOT NULL
GROUP BY salesRepEmployeeNumber
HAVING COUNT(customerNumber) > 9;


Cau 8:
SELECT orderNumber, (quantityOrdered * priceEach > 60000;) AS total 
FROM orderdetails
WHERE quantityOrdered * priceEach > 60000;
