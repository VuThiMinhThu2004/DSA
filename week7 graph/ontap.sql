Cau 5:
op1:
(SELECT "Co" AS Note, COUNT(*)
FROM customers
WHERE SUBSTR(customerName, -3) IN ('Co ', 'Co.', ' Co'))
UNION
SELECT "Ltd" AS Note, COUNT(*)  
FROM customers
WHERE SUBSTR(customerName, -4) IN ('Ltd ', 'Ltd.', ' Ltd')
UNION
SELECT "Inc" AS Note, COUNT(*)
FROM customers
WHERE SUBSTR(customerName, -4) IN ('Inc ', 'Inc.', ' Inc')
UNION 
(SELECT "Other" AS Note, COUNT(*)
FROM customers
WHERE SUBSTR(customerName, -3) NOT IN ('Co ', 'Co.', ' Co')
  AND SUBSTR(customerName, -4) NOT IN ('Ltd ', 'Ltd.', ' Ltd', 'Inc ', 'Inc.', ' Inc'));

op2:
(SELECT "Co" AS Note, COUNT(*)
FROM `customers`
WHERE SUBSTR(customerName, -3) = 'Co.' OR SUBSTR(customerName, -2) = "Co")
UNION
SELECT "Ltd" AS Note, COUNT(*)  
FROM `customers`
WHERE SUBSTR(customerName, -4) = 'Ltd.' OR  SUBSTR(customerName, -4) = ' Ltd'
UNION
SELECT "Inc" AS Note, COUNT(*)
FROM `customers`
WHERE SUBSTR(customerName, -4) = 'Inc.' OR  SUBSTR(customerName, -3) ='Inc'
UNION 
(SELECT "Other" AS Note, COUNT(*)
FROM `customers`
WHERE SUBSTR(customerName, -3) NOT IN ('Co.', 'Ltd', 'Inc') 
    AND SUBSTR(customerName, -2) NOT IN('Co')
    AND SUBSTR(customerName, -4) NOT IN ('Ltd.', 'Inc.'));

op3:
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


Cau 5cs lien tiep:
SELECT customerName, phone
FROM customers
WHERE creditLimit > 200000 AND (phone LIKE '%00000%' OR phone LIKE '%11111%' OR  phone LIKE '%22222%' OR
phone LIKE '%33333%' OR phone LIKE '%44444%' OR phone LIKE '%55555%' 
OR phone LIKE '%66666%'  OR phone LIKE '%77777%' OR phone LIKE '%88888%' 
OR phone LIKE '%99999%');


SELECT COUNT(*) AS VIP_Customer_Count
FROM customers
WHERE
    creditLimit > 200000
    AND (
        phone LIKE '%00000%' OR phone LIKE '%11111%' OR  phone LIKE '%22222%' OR
        phone LIKE '%33333%' OR phone LIKE '%44444%' OR phone LIKE '%55555%' 
        OR phone LIKE '%66666%'  OR phone LIKE '%77777%' OR phone LIKE '%88888%' 
        OR phone LIKE '%99999%'
    );


cau6
SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency
FROM orders
GROUP BY customerNumber
ORDER BY recency ASC;


SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency, COUNT(*) AS frequency
FROM orders
GROUP BY customerNumber
HAVING recency <= 7;

cau2: RFM
SELECT customerNumber, DATEDIFF("2005-06-12", MAX(orderDate)) AS recency, COUNT(*) AS frequency
FROM orders
GROUP BY customerNumber
HAVING recency < 50 OR frequency > 20;

Cau 4:Which product line has the least inventory money?
Know that inventory money = quantity of inventory * purchase price.
(Dòng sản phẩm nào có ít tiền tồn kho nhất?
Biết rằng tiền tồn kho = số lượng tồn kho * giá mua.)
OA. Train
B. Classic Cars
OC. Vintage Cars
D. Trucks and Buses

SELECT
    productLine,
    SUM(quantityInStock * buyPrice) AS totalInventoryMoney
FROM
    products
GROUP BY
    productLine
ORDER BY
    totalInventoryMoney
LIMIT 1;


Cau 1:
SELECT
    SUBSTRING(productCode, 2, 2) AS ProductScale,
    SUM(quantityOrdered) AS TotalSales
FROM
    orderdetails
GROUP BY
    ProductScale
ORDER BY
    TotalSales DESC
LIMIT 1;


da: 18