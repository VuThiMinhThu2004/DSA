Cau1:
a) recency
SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency
FROM orders O 
GROUP BY customerNumber;

b) frequency
SELECT customerNumber, DATEDIFF("2005-06-02", MAX(orderDate)) AS recency,
        COUNT(*) frequency
FROM orders 
GROUP BY customerNumber
ORDER BY frequency DESC;

c) Monetary: 98kq
M: so tien da thanh toan(amount)
SELECT C.customerName, C.customerNumber, 
        DATEDIFF("2005-06-02", MAX(O.orderDate)) AS recency,
        COUNT(*) frequency,
        SUM(p.amount) as Monetary
FROM orders O 
INNER JOIN customers C ON O.customerNumber = C.customerNumber
INNER JOIN payments p ON p.customerNumber = C.customerNumber
GROUP BY C.customerNumber
ORDER BY frequency DESC;

NEU M: so tien da order// chac la sai: 98 truy van
SELECT C.customerName, C.customerNumber, 
        DATEDIFF("2005-06-02", MAX(O.orderDate)) AS recency,
        COUNT(*) frequency,
        SUM(od.quantityOrdered * od.priceEach) as Monetary
FROM orders O 
INNER JOIN orderdetails od ON od.orderNumber = O.orderNumber
INNER JOIN customers C ON O.customerNumber = C.customerNumber
GROUP BY C.customerNumber
ORDER BY frequency DESC;

Cau 2: res: 14 kq
SELECT C.customerName, C.customerNumber, 
        DATEDIFF("2005-06-02", MAX(O.orderDate)) AS recency,
        COUNT(*) frequency,
        SUM(od.quantityOrdered * od.priceEach) as Monetary
FROM orders O 
INNER JOIN orderdetails od ON od.orderNumber = O.orderNumber
INNER JOIN customers C ON O.customerNumber = C.customerNumber
GROUP BY C.customerNumber
HAVING (recency <= 5 AND frequency >= 5) OR Monetary >= 500000
ORDER BY frequency DESC;

Cau3:
01 câu truy vấn hiển thị tên, nội dung mô tả và tổng số lượng sản phẩm của dòng sản phẩm có
tổng số lượng sản phẩm lớn hơn 50.000. Sắp xếp theo thứ tự số lượng giảm dần.
(Gợi ý: tổng số lượng sản phẩm trong kho đã bán)
SELECT pl.productLine, pl.textDescription,
SUM(DISTINCT p.quantityInStock) + IF(SUM(o.quantityOrdered) IS NOT NULL, SUM(o.quantityOrdered), 0) AS total
FROM products p
LEFT JOIN orderdetails o ON p.productCode = o.productCode
INNER JOIN productlines pl ON p.productLine = pl.productLine
GROUP BY pl.productLine
ORDER BY total DESC;

SUA
SELECT 
    pl.productLine, 
    pl.textDescription,
    SUM(p.quantityInStock) + COALESCE(o.totalOrdered, 0) AS total//tach ra thi sai vi cai sau k co tinh tong theo groupby
Sửa:SUM(p.quantityInStock) + SUM(IF(o.totalOrdered IS NOT NULL, o.totalOrdered, 0)) AS total
Hoặc:
    SUM(p.quantityInStock+ IF(o.totalOrdered IS NOT NULL, o.totalOrdered, 0)) AS total

FROM 
    products p
LEFT JOIN 
    (
        SELECT 
            productCode, 
            SUM(quantityOrdered) AS totalOrdered
        FROM 
            orderdetails
        GROUP BY 
            productCode
    ) o ON p.productCode = o.productCode
INNER JOIN 
    productlines pl ON p.productLine = pl.productLine
GROUP BY 
    pl.productLine
HAVING total > 50000
ORDER BY 
    total DESC;

HUONG
SELECT pl.productLine, pl.textDescription,
 SUM(p.quantityInStock + IF(od.soldAmount IS NOT NULL, od.soldAmount, 0)) AS total
FROM productlines pl 
INNER JOIN products p ON pl.productLine = p.productLine
LEFT JOIN (
    SELECT productCode, SUM(quantityOrdered) AS soldAmount
    FROM orderdetails
    GROUP BY productCode
) od ON od.productCode = p.productCode
GROUP BY pl.productLine
HAVING total > 50000
ORDER BY total DESC;




Truy van con: la mot truy van duoc goi trong 1 truy van khac
- Khong tuong quan: truy van con thuc hien 1 lan duy nhat
- Tuong quan: co lien ket voi truong du lieu cua truy van ben ngoai, truy van con thuc hien N lan (N bo cua truy van ben ngoai)

cau 1:
SELECT * 
FROM products p
WHERE p.productCode IN ( SELECT DISTINCT productCode FROM orderdetails WHERE orderNumber IN (
 ( SELECT orderNumber FROM orders WHERE orderDate >= "2005/03/01" AND orderDate <= "2005/03/31")));

SELECT DISTINCT p.productCode
FROM products p
INNER JOIN orderdetails od ON p.productCode = od.productCode
INNER JOIN orders o ON o.orderNumber = od.orderNumber
WHERE o.orderDate >= "2005/03/01" AND o.orderDate <= "2005/03/31";

cau 2: kq: 15 total, ve dung join de check lai
SELECT *
FROM orders 
WHERE MONTH(orderDate) = (SELECT MONTH(MAX(orderDate)) FROM orders)
    AND YEAR(orderDate) = (SELECT YEAR(MAX(orderDate)) FROM orders);


cau 3:luu y co SUM thi phai co group by
SELECT o.orderNumber, o.status,
    (SELECT SUM(od.quantityOrdered * od.priceEach) as total
    FROM orderdetails od
    WHERE od.orderNumber = o.orderNumber
    GROUP BY od.orderNumber) as totalValue
FROM orders o;

Cau 4: So tien khach hang: have to pay 
SELECT C.customerName, (SELECT SUM(amount) 
                        FROM payments 
                        WHERE customerNumber = C.customerNumber
                        GROUP BY customerNumber) AS totalPaid,/*Tính tổng số tiền mà mỗi khách hàng đã thanh toán*/
                        (SELECT SUM(od.quantityOrdered * priceEach)
                        FROM orderdetails od
                        WHERE od.orderNumber IN (SELECT orderNumber                            
                                                FROM orders
                                                WHERE customerNumber = C.customerNumber)
                        GROUP BY C.customerNumber) AS totalPurchased,/*tổng số tiền mà mỗi khách hàng đã mua*/
                        (SELECT totalPurchased - totalPaid) AS totalDebt,/*tổng số nợ của mỗi khách hàng bằng cách trừ 'totalPaid' từ 'totalPurchased*/
                        (SELECT SUM(quantityOrdered * priceEach)
                        FROM orderdetails od
                        WHERE orderNumber IN (SELECT orderNumber
                                            FROM orders
                                            WHERE customerNumber = od.customerNumber AND status = "Cancelled")
                        GROUP BY c.customerNumber) AS totalCancelled,/*tổng số tiền của đơn hàng bị hủy của mỗi khách hàng*/
                        (SELECT totalDebt - IF(totalCancelled IS NULL, 0, totalCancelled)) AS actualDebt /*số nợ thực tế của mỗi khách hàng bằng cách trừ 'totalCancelled' từ 'totalDebt*/
FROM customers C
HAVING actualDebt > 0;/*no thuc te lon hon 0*/


cau 3:
SELECT pl.productLine, pl.textDescription,
        SUM(p.quantityInStock + IF(od.totalOrdered IS NULL,0,od.totalOrdered)) AS totalQuantity             
FROM productlines pl 
INNER JOIN products p ON p.productLine = pl.productLine
LEFT JOIN (
    SELECT productCode, SUM(quantityOrdered) as totalOrdered
    FROM orderdetails
    GROUP BY productCode) od ON od.productCode = p.productCode
GROUP BY pl.productLine
HAVING totalQuantity > 50000
ORDER BY totalQuantity DESC;

cau 3:
SELECT pl.productLine, (SELECT SUM(quantityInStock)
                        FROM products
                        WHERE productLine = pl.productLine) AS totalInstock,
                       (SELECT SUM(od.quantityOrdered)
                       FROM orderdetails od
                       WHERE od.productCode IN (SELECT productCode
                                               FROM products
                                               WHERE productLine = pl.productLine)) AS totalOrder,
                        (SELECT totalInstock + totalOrder) AS totalquantity
FROM productlines pl
HAVING totalquantity > 50000
ORDER BY totalquantity DESC;


Cau 4:
SELECT c.customerName, (SELECT SUM(quantityOrdered * priceEach)
                        FROM orderdetails 
                        WHERE orderNumber IN (SELECT orderNumber
                                              FROM orders
                                              WHERE customerNumber = c.customerNumber)
                        GROUP BY c.customerNumber) AS totalPurchased,
                        (SELECT SUM(amount)
                         FROM payments
                         WHERE customerNumber = c.customerNumber
                         GROUP BY customerNumber) as totalPaid,
                         (SELECT IF(totalPaid IS NULL, 
                                    IF(totalPurchased IS NULL, 0, totalPurchased),
                                    IF(totalPurchased IS NULL, 0, totalPurchased-totalPaid))) AS totalDebt
FROM customers c 
HAVING totalPurchased < 100000
ORDER BY totalDebt DESC;

Cau 5:
USE classicmodels;

DROP TABLE IF EXISTS new_payments;
CREATE TABLE new_payments (
    SELECT * 
    FROM payments 
    WHERE amount > 50000
);

cau 5.1:
CREATE TABLE usa_office LIKE offices;
INSERT INTO usa_office 
SELECT *
FROM offices
WHERE country = "USA";

Cau 6:
SELECT pl.productLine, pl.textDescription, (SELECT SUM(p.quantityInStock * p.buyPrice)
                                            FROM products p 
                                            WHERE p.productLine = pl.productLine) AS Inventorymoney
FROM productlines pl
GROUP BY Inventorymoney 
ORDER BY Inventorymoney DESC;


CAU 3: mo rong tinh totalCancelled

SELECT pl.productLine, (SELECT SUM(quantityInStock)
                        FROM products
                        WHERE productLine = pl.productLine) AS totalInstock,
                       (SELECT SUM(od.quantityOrdered)
                       FROM orderdetails od
                       WHERE od.productCode IN (SELECT productCode
                                               FROM products
                                               WHERE productLine = pl.productLine)) AS totalOrder,
                        (SELECT SUM(od.quantityOrdered)
                       FROM orderdetails od
                       WHERE od.productCode IN (SELECT productCode
                                               FROM products
                                               WHERE productLine = pl.productLine) AND
                         	od.orderNumber IN (SELECT orderNumber
                                               FROM orders
                                               WHERE status = "Cancelled")) AS totalCancelled,
                       (SELECT (totalInstock - totalOrder + IF(totalCancelled IS NULL, 0, totalCancelled))) AS totalQuantityProduct
FROM productlines pl;
