SELECT city, COUNT(customerNumber) AS quantityCustomer 
FROM customers
GROUP BY city;


SELECT orderDate, COUNT(*) AS Total
FROM orders
WHERE orderDate BETWEEN "2005/03/01" AND "2005/03/31"
GROUP BY orderDate;
/*12 don,)
*/



 /*tong so don hang trong thang 3 nam 2005*/
 SELECT orderDate, COUNT(*) AS Total
FROM orders
WHERE YEAR(orderDate) = 2005 AND MONTH(orderDate) = 3;

/*lay don hang moi thang trong nam 2005: tu1->5*/
SELECT orderDate, COUNT(*) AS Total
FROM orders
WHERE YEAR(orderDate) = 2005
GROUP BY MONTH(orderDate);


/*  q3: lay ra so lg cac don hang cua moi thang cua moi nam */
SELECT EXTRACT(YEAR_MONTH FROM orderDate) AS date, COUNT(*) AS Total
FROM orders
GROUP BY date;

/*cach 2*/
SELECT MONTH(orderDate) AS month, YEAR(orderDate) AS year, COUNT(*) AS Total
FROM orders
GROUP BY month, year;


SELECT orderNumber, SUM(quantityOrdered * priceEach) AS Cost
FROM orderdetails
GROUP BY orderNumber
ORDER BY Cost DESC
LIMIT 10;

SELECT productLine, SUM(quantityInStock) AS Total
FROM products 
GROUP BY productLine;


SELECT customerNumber, SUM(amount) AS TotalAmount
FROM payments
GROUP BY customerNumber;


/*Su dung group by luu y ham group_func vi no la dieu kien de gom nhom

SELECT productLine, AVG(buyPrice) AS AVGPrice
FROM products
GROUP BY productLine
HAVING AVGPrice > 50;

*/

SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency
FROM orders
GROUP BY customerNumber;



SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency, COUNT(*) AS frequency
FROM orders
GROUP BY customerNumber
HAVING recency <= 7;

cau6
SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency
FROM orders
GROUP BY customerNumber
ORDER BY recency ASC;


cau 8
SELECT LEFT(checkNumber, 1) AS checkNo, SUBSTRING(checkNumber, 2, 1) AS nextNo, COUNT(*)
FROM payments
GROUP BY nextNo
HAVING checkNo = "E";

SELECT LEFT(checkNumber, 1) AS checkNo, SUBSTRING(checkNumber, 2, 1) AS BANK, COUNT(*)
FROM payments
GROUP BY BANK
HAVING checkNo = "E";


SELECT SUBSTRING(checkNumber, 2, 1) AS BANK, COUNT(*)
FROM payments
WHERE LEFT(checkNumber, 1) = "E"
GROUP BY BANK;

cau 6
SELECT SUBSTR(productName, 1, 4) AS year, COUNT(*) AS total
FROM products
GROUP BY year
order by total DESC;

cau 5