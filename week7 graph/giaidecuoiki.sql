/*Đề Nhóm 1*/
Cau 2: Liệt kê khách hàng chưa từng đặt mua sản phẩm (Viết 2 cách): 24 tuple
OPTION 1: subquery 
SELECT c.customerName, c.customerNumber
FROM customers c 
WHERE c.customerNumber NOT IN (SELECT customerNumber
                               FROM orders);

OPTION 2: JOIN TABLE 
SELECT c.customerName, c.customerNumber
FROM customers c
LEFT JOIN orders o ON c.customerNumber = o.customerNumber
WHERE o.customerNumber IS NULL;

Cau 3: Liệt kê tên các sản phẩm được bán với giá nhỏ hơn 80% so với MSRP.
KQ: 110 tuple 
SELECT *
FROM products 
WHERE buyPrice < 0.8 * MSRP;

Cau 4: Viết câu truy vấn để trả lời cho câu hỏi:
    có sản phẩm nào xuất hiện trong tất cả các đơn đặt hàng hay không ?
KQ: 0 tuple 
SELECT od.productCode, COUNT(*) AS totalOrder, (SELECT COUNT(orderNumber)
                                                FROM orders) AS totalOrderNumber
FROM orderdetails od
GROUP BY od.productCode
HAVING totalOrder >= totalOrderNumber;

Cau 5: Viết câu truy vấn để đưa ra các khách hàng đã mua sản phẩm bán chạy nhất.
KQ: 40 tuple

SELECT *
FROM customers
WHERE customerNumber IN (
    SELECT DISTINCT customerNumber
    FROM orders
    WHERE orderNumber IN (
        SELECT orderNumber
        FROM orderdetails
        WHERE productCode = (
            SELECT productCode
            FROM (
                SELECT productCode, SUM(quantityOrdered) as total
                FROM orderdetails
                GROUP BY productCode
                ORDER BY total DESC
                LIMIT 1
            ) AS max_ordered_product
        )
    )
);

SELECT *
FROM customers
WHERE customerNumber IN (SELECT DISTINCT customerNumber
                         FROM orders
                         WHERE orderNumber IN (SELECT orderNumber
                                               FROM orderdetails
                                               WHERE productCode = (SELECT productCode
                                                                    FROM (SELECT productCode, SUM(quantityOrdered) as total
                                                                        FROM orderdetails
                                                                        GROUP BY productCode
                                                                        ORDER BY total DESC
                                                                        LIMIT 1) AS max_ordered_product)));

/*Đề Nhóm 2*/
Cau 2: Liệt kê mã số và tên họ của tất cả các nhân viên chưa có khách hàng nào (Viết 2 cách).
KQ: 8 tuple
option1: subquery
SELECT concat_ws(" - ", lastname, firstname) as fullname, employeeNumber
FROM employees
WHERE NOT EXISTS (SELECT salesRepEmployeeNumber
                FROM customers c
                WHERE c.salesRepEmployeeNumber = employeeNumber);

option2: join table
SELECT concat_ws(" - ", lastname, firstname) as fullname, employeeNumber
FROM employees 
LEFT JOIN customers ON employeeNumber = salesRepEmployeeNumber
WHERE salesRepEmployeeNumber IS NULL;

Cau 3: Viết câu truy vấn để đưa ra các sản phẩm và lợi nhuận mà đơn vị bán hàng thu được từ những sản phẩm đó.
sai:
SELECT p.productCode, SUM(p.buyPrice) AS totalBuy, 
	(SELECT SUM(priceEach)
    FROM orderdetails
    WHERE productCode = p.productCode) AS totalEach
FROM products p
GROUP BY p.productCode;

dung:
SELECT p.productCode, SUM(od.priceEach - p.buyPrice) AS LoiNhuan
FROM products p
INNER JOIN orderdetails od ON od.productCode = p.productCode
GROUP BY p.productCode;

DUNG
SELECT 
    p.productCode,
    SUM(p.buyPrice) AS totalBuy,
    SUM(od.priceEach) AS totalEach,
    (SUM(od.priceEach) - SUM(p.buyPrice)) AS LoiNhuan
FROM 
    products p
INNER JOIN 
    orderdetails od ON p.productCode = od.productCode
GROUP BY 
    p.productCode;

Cau 4: Viết câu truy vấn để tìm ra ít nhất một khách hàng đã đặt hàng cùng một sản phẩm với một khách hàng khác.
SELECT DISTINCT c.customerNumber, c.customerName
FROM customers c
INNER JOIN orders o ON o.customerNumber = c.customerNumber  
INNER JOIN orderdetails od ON od.orderNumber = o.orderNumber
WHERE od.productCode IN (
	SELECT conditi.productCode
	FROM (SELECT od1.productCode
         FROM orderdetails od1
         INNER JOIN orders o1 ON o1.orderNumber = od1.orderNumber
         GROUP BY od1.productCode
         HAVING (COUNT(o1.customerNumber)) >= 2) AS conditi);



Cau: tim ra don hang co nhieu hon 2 nguoi dat
SELECT p.productCode,
    (SELECT COUNT(*)
    FROM orders o
    WHERE o.orderNumber IN (
        SELECT od.orderNumber
        FROM orderdetails od 
        WHERE od.productCode = p.productCode
    )) AS QuantityCustomer
FROM 
    products p
HAVING QuantityCustomer > 2;

Cau 5:
Viết câu truy vấn để đưa ra các nhân viên đang làm việc dưới quyền người quản lý, 
mà trong đó người quản lý này lại quản lý số lượng nhân viên nhiều nhất.

SELECT *
FROM employees e 
WHERE e.reportsTo IN (SELECT e.reportsTo
                      FROM employees e
                      GROUP BY e.reportsTo
                      HAVING (COUNT(e.employeeNumber)) = (SELECT MAX(tmp.quantity)
                                                          FROM (SELECT COUNT(DISTINCT employeeNumber) AS quantity
                                                                FROM employees 
                                                                GROUP BY reportsTo) AS tmp));
