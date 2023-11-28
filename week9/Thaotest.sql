
Cau 6: chua kịp t tra chatgpt
SELECT
    c.customerName AS TenKhachHang,
    c.customerNumber AS MaKhachHang,
    SUM(IFNULL(pay.amount, 0)) AS SoTienDaTra,
    SUM(IFNULL(od.priceEach * od.quantityOrdered, 0)) AS SoTienDaMua,
    (SUM(IFNULL(pay.amount, 0)) - SUM(IFNULL(od.priceEach * od.quantityOrdered, 0))) AS SoTienConNo,
    COUNT(DISTINCT o.orderNumber) AS SoDonHangDaThucHien
FROM
    customers c
LEFT JOIN
    orders o ON c.customerNumber = o.customerNumber
LEFT JOIN
    orderdetails od ON o.orderNumber = od.orderNumber
LEFT JOIN
    payments pay ON c.customerNumber = pay.customerNumber
GROUP BY
    c.customerName, c.customerNumber
HAVING
    COUNT(DISTINCT o.orderNumber) >= 5
    AND (SUM(IFNULL(pay.amount, 0)) - SUM(IFNULL(od.priceEach * od.quantityOrdered, 0)) < 50000)
ORDER BY
    MaKhachHang;


Cau 5:
SELECT
    c.customerName,
    (c.creditLimit - IFNULL(SUM(p.amount), 0)) AS SoTienConNo
FROM
    customers c
LEFT JOIN
    payments p ON c.customerNumber = p.customerNumber
GROUP BY
    c.customerName, c.creditLimit
HAVING
    SoTienConNo > 0
ORDER BY
    SoTienConNo DESC;



Cau1:
SELECT
    c.customerNumber,
    c.customerName
FROM
    customers c
LEFT JOIN
    payments p ON c.customerNumber = p.customerNumber
WHERE
    p.customerNumber IS NULL;

Cau 2:
a)
SELECT
    c.customerNumber,
    c.customerName,
    MAX(p.paymentDate) AS lastPaymentDate
FROM
    customers c
JOIN
    payments p ON c.customerNumber = p.customerNumber
GROUP BY
    c.customerNumber, c.customerName
ORDER BY
    lastPaymentDate DESC
LIMIT 10;


b)
SELECT
    orderNumber,
    status
FROM
    orders
WHERE
    status != 'Shipped';


Cau 3:
Tạo bảng new_products sao chép cấu trúc từ bảng products:
CREATE TABLE new_products AS
SELECT * FROM products
WHERE 1 = 0;
thêm dữ liệu cho bảng new_products bằng cách sử dụng câu lệnh INSERT INTO 

sao chép dữ liệu từ bảng products vào bảng new_products:
INSERT INTO new_products (productCode, productName, productLine, productDescription)
SELECT productCode, productName, productLine, productDescription
FROM products;


Cau 4:
truy van con:
SELECT
    productLine,
    (
        SELECT COUNT(*)
        FROM orderdetails od
        WHERE od.productCode IN (
            SELECT productCode
            FROM products p
            WHERE p.productLine = products.productLine
        )
    ) AS SoLuongDatHang
FROM
    products
GROUP BY
    productLine
ORDER BY
    SoLuongDatHang DESC;


Noi bang:
SELECT
    p.productLine,
    COUNT(od.orderNumber) AS SoLuongDatHang
FROM
    products p
LEFT JOIN
    orderdetails od ON p.productCode = od.productCode
GROUP BY
    p.productLine
ORDER BY
    SoLuongDatHang DESC;
