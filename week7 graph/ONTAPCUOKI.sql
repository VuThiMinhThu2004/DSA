Cau 1: Model RFM:
-giai thich: Tinh dua tren khach hang -> customerNumber
+ R = recency: khoang thoi gian gan day nhat 
+ F = frequency: tan suat mua hang 
+ M: tong so tien da thanh toan
option1: truy van con:
SELECT o.customerNumber, DATEDIFF("2005-06-02", MAX(o.orderDate)) AS recency,
	COUNT(*) AS frequency,
    (SELECT SUM(amount)
    FROM payments
    WHERE customerNumber = o.customerNumber) AS monetary
FROM orders o 
GROUP BY o.customerNumber
ORDER BY frequency DESC;

option2: noi bang
SELECT C.customerName, C.customerNumber, 
        DATEDIFF("2005-06-02", MAX(O.orderDate)) AS recency,
        COUNT(*) frequency,
        SUM(p.amount) as Monetary
FROM orders O 
INNER JOIN customers C ON O.customerNumber = C.customerNumber
INNER JOIN payments p ON p.customerNumber = C.customerNumber
GROUP BY C.customerNumber
ORDER BY frequency DESC;

cau1: co chua tren bang orderdetails nhung MONETARY la payments:
SELECT c.customerNumber,
    (SELECT DATEDIFF("2005/06/02", MAX(orderDate))
    FROM orders
    WHERE customerNumber = c.customerNumber) AS recency,
    (SELECT COUNT(*)
    FROM orders 
    WHERE customerNumber = c.customerNumber) AS frequency,
    (SELECT SUM(amount)
    FROM payments  
    WHERE customerNumber = c.customerNumber) AS monetary
FROM customers c
GROUP BY c.customerNumber
ORDER BY frequency DESC;

Cau 2: 2 cach cau 2 ra dap an khac nhau: subquery dung
SELECT o.customerNumber, DATEDIFF("2005-06-02", MAX(o.orderDate)) AS recency,
	COUNT(*) AS frequency,
    (SELECT SUM(amount)
    FROM payments
    WHERE customerNumber = o.customerNumber) AS monetary
FROM orders o 
GROUP BY o.customerNumber
HAVING (recency <= 5 AND frequency >= 5) OR monetary >= 500000
ORDER BY frequency DESC;



Cau 3: total quantity of product of productLine
Hint: total quantity product = instock + sold = trong kho + da ban

SELECT pl.productLine, pl.textDescription,
	(SELECT SUM(quantityInstock)
    FROM products
    WHERE productLine = pl.productLine) AS totalInstock,
    (SELECT SUM(quantityOrdered)
    FROM orderdetails
    WHERE productCode IN (SELECT productCode
                         FROM products
                         WHERE productLine = pl.productLine)) AS totalSold,
    (SELECT (totalInstock + totalSold)) AS totalQuantityProduct
FROM productlines pl
GROUP BY productLine
HAVING totalQuantityProduct > 50000
ORDER BY totalQuantityProduct DESC;

/*TINH TOTALCANCELLED*/
SELECT pl.productLine, pl.textDescription,
	(SELECT SUM(quantityInstock)
    FROM products
    WHERE productLine = pl.productLine) AS totalInstock,
    (SELECT SUM(quantityOrdered)
    FROM orderdetails
    WHERE productCode IN (SELECT productCode
                         FROM products
                         WHERE productLine = pl.productLine)) AS totalSold,
    (SELECT SUM(quantityOrdered)
    FROM orderdetails
    WHERE orderNumber IN (SELECT orderNumber
                         FROM orders
                         WHERE status = "Cancelled")) AS totalCancelled,
    (SELECT (totalInstock + totalSold)) AS totalQuantityProduct
FROM productlines pl
GROUP BY productLine
HAVING totalQuantityProduct > 50000
ORDER BY totalQuantityProduct DESC;


Cau 4:
SELECT c.customerName, (SELECT SUM(quantityOrdered * priceEach)
                       FROM orderdetails
                       WHERE orderNumber IN (SELECT orderNumber
                                            FROM orders
                                            WHERE customerNumber = c.customerNumber)) AS totalPurchase,
	(SELECT SUM(amount)
    FROM payments
    WHERE customerNumber = c.customerNumber) AS totalPaid,
    (SELECT IF(totalPurchase IS NULL, 0, totalPurchase) - IF(totalPaid IS NULL, 0, totalPaid)) AS totalDebt
FROM customers c
HAVING totalPurchase < 100000
ORDER BY totalDebt DESC;

Cau 6: Inventory Money: could be caculated using buy price

SELECT pl.productLine, pl.textDescription, 
	(SELECT SUM(p.quantityInStock * p.buyPrice)
    FROM products p 
    WHERE p.productLine = pl.productLine) AS InventoryMoney
FROM productlines pl 
GROUP BY pl.productLine
ORDER BY InventoryMoney DESC;



CÔ chữa:
SELECT c.customerNumber,
    (SELECT DATEDIFF("2005/06/02", MAX(orderDate))
    FROM orders
    WHERE customerNumber = c.customerNumber) AS recency,
    (SELECT COUNT(*)
    FROM orders 
    WHERE customerNumber = c.customerNumber) AS frequency,
    (SELECT SUM(quantityOrdered * priceEach)
    FROM orderdetails
    WHERE orderNumber IN (SELECT orderNumber
                        FROM orders
                        WHERE customerNumber = c.customerNumber)) AS monetary
FROM customers c
GROUP BY c.customerNumber
ORDER BY frequency DESC;