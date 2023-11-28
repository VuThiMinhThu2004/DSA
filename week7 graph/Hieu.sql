
USE clASsicmodels;

/* Câu 1: Tạo bảng dữ liệu mới tên new_employees có cấu trúc giống như bảng employees.
Thêm vào bảng vừa tạo các dòng của bảng employees có văn phòng nằm ở Mỹ
*/
DROP TABLE IF EXISTS new_employees;
CREATE TABLE new_employees AS (
	SELECT * FROM employees WHERE employeeNumber IN (
		SELECT employeeNumber FROM employees e
        INNER JOIN offices o ON e.officeCode = o.officeCode
        WHERE country = 'USA'
    )
);
-- SELECT * FROM new_employees;

/* Câu 2: Liệt kê mã số và tên họ của tất cả các nhân viên chưa có khách hàng nào (Viết 2 cách).
*/
-- Cách 1
SELECT e.employeeNumber, concat(e.firstName, ' ', e.lAStName) AS fullname FROM employees e WHERE employeeNumber NOT IN (
	SELECT salesRepEmployeeNumber FROM customers WHERE salesRepEmployeeNumber IS NOT NULL
);

-- Cách 2
SELECT e.employeeNumber, concat(e.firstName, ' ', e.lAStName) AS fullname FROM employees e
LEFT JOIN customers c ON e.employeeNumber = c.salesRepEmployeeNumber
WHERE c.customerNumber IS NULL;


/* Câu 3: Viết câu truy vấn để đưa ra các sản phẩm và lợi nhuận mà đơn vị bán hàng thu được từ những sản phẩm đó
*/
SELECT p.productName, p.productCode, sum(od.quantityOrdered * (od.priceEach - p.buyPrice)) AS loinhuan FROM products p
INNER JOIN orderdetails od ON p.productCode = od.productCode
GROUP BY productCode;

/* Câu 4: Viết câu truy vấn để tìm ra ít nhất một khách hàng đã đặt hàng cùng một sản phẩm với một khách hàng khác.
*/
SELECT DISTINCT c.customerNumber, c.customerName FROM customers c
INNER JOIN orders o ON c.customerNumber = o.customerNumber
INNER JOIN orderdetails od ON o.orderNumber = od.orderNumber
WHERE od.productCode IN (
	SELECT tmpTable.productCode FROM (
		SELECT productCode FROM orderdetails od1
        INNER JOIN orders o1 ON od1.orderNumber = o1.orderNumber
        GROUP BY productCode
        HAVING count(productCode) > 1
    ) AS tmpTable
);

/* Câu 5: Viết câu truy vấn để đưa ra các nhân viên đang làm việc dưới quyền người quản lý, mà trong đó người quản lý này lại quản lý số lượng nhân viên nhiều nhất
*/
SELECT * FROM employees WHERE reportsTo in (
	SELECT reportsTo FROM employees
	GROUP BY reportsTo
	HAVING count(reportsTo) = (
		SELECT max(tmptable.countRPT) FROM (
			SELECT count(reportsTo) AS countRPT FROM employees
			GROUP BY reportsTo 
		) AS tmptable
	)
)

/* Câu 1: Tạo bảng dữ liệu mới tên new_employees có cấu trúc giống như bảng employees.
Thêm vào bảng vừa tạo các dòng của bảng employees có văn phòng nằm ở Mỹ
*/
drop table if exists new_employees;
create table new_employees as (
	select * from employees where employeeNumber in (
		select employeeNumber from employees e
        inner join offices o on e.officeCode = o.officeCode
        where country = 'USA'
    )
);
select * from new_employees;

cau 2:
op1:
SELECT e.employeeNumber, CONCAT(e.firstName, ' ', e.lastName) as fullname
FROM employees e
WHERE NOT EXISTS (
    SELECT 1
    FROM customers c
    WHERE c.salesRepEmployeeNumber = e.employeeNumber
);
op2:
SELECT e.employeeNumber, concat(e.firstName, ' ', e.lAStName) AS fullname FROM employees e
LEFT JOIN customers c ON e.employeeNumber = c.salesRepEmployeeNumber
WHERE c.customerNumber IS NULL;

cau 3:
SELECT p.productCode, p.productName , SUM(od.quantityOrdered* (od.priceEach - p.buyPrice)) AS loi_nhuan
FROM products p 
INNER JOIN orderdetails od ON od.productCode = p.productCode
GROUP BY od.productCode;

cau 4:
SELECT DISTINCT c.customerNumber , c.customerName
FROM customers c 
JOIN orders o ON o.customerNumber = c.customerNumber
JOIN orderdetails od ON od.orderNumber = o.orderNumber
WHERE od.productCode IN (
    SELECT conditi.productCode
    FROM (
        SELECT od1.productCode
        FROM orderdetails od1
        JOIN orders o ON o.orderNumber = od1.orderNumber
        GROUP BY od1.productCode
        HAVING COUNT(o.customerNumber) > 1
    ) AS conditi
);

cau 5:
kq: 12 tuple
SELECT *
FROM employees e 
WHERE e.reportsTo IN (
    SELECT e.reportsTo
    FROM employees e 
    GROUP BY e.reportsTo 
    HAVING COUNT(DISTINCT e.employeeNumber) = (
        SELECT MAX(t1.cnt) 
        FROM (
            SELECT COUNT(DISTINCT employeeNumber) AS cnt 
            FROM employees 
            GROUP BY reportsTo
        ) AS t1
    )
);