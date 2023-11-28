/*INNER JOIN so sánh từng dòng trong bảng products và OrderDetails để tìm một cặp bản 
ghi có cùng productCode. Nếu một cặp bản ghi có cùng mã sản phẩm, khi đó tên sản 
phẩm và số thứ tự cũng sẽ được kết hợp thành một hàng để trả lại kết quả.*/
SELECT products.productCode, products.productName, orderdetails.orderNumber
FROM products
INNER JOIN orderdetails on products.productCode = orderdetails.productCode;

/*Bí danh (Alias): có thể tạo bí danh của bảng tbl_A là A và tham chiếu đến cột M là A.M , 
như vậy không mất công gõ lại tên bảng nữa. Ví dụ trên có thể viết lại như sau:*/
SELECT p.productCode, p.productName, o.orderNumber
FROM products p
INNER JOIN orderDetails o on p.productCode = o.productCode;

/*Lưu ý: Bên cạnh phép nối trong sử dụng mệnh đề INNER JOIN .. ON, có thể nối trong 
hai bảng bằng cách đưa điều kiện nối vào mệnh đề WHERE. Ví dụ trên có thể viết lại 
như sau:*/
SELECT p.productCode, p.productName, o.orderNumber
FROM products p, orderDetails o
WHERE p.productCode = o.productCode;

SELECT cus.customerName, emp.firstName as employeeName 
FROM customers cus JOIN employees emp ON cus.salesRepEmployeeNumber = emp.employeeNumber;


SELECT p1.productLine, p1.textDescription, sum(quantityInStock)
FROM productlines p1 JOIN products p2  ON p1.productLine = p2.productLine
GROUP BY p1.productLine;


SELECT p.productCode, p.productName, SUM(quantityOrdered * priceEach) AS total
FROM products p JOIN orderdetails o ON p.productCode = o.productCode
GROUP BY productCode 
ORDER BY total ASC;


SELECT p.productCode, p.productName, SUM(quantityOrdered * priceEach) AS total
FROM products p 
INNER JOIN orderdetails o ON p.productCode = o.productCode
GROUP BY productCode 
ORDER BY total ASC;

/*Đưa ra tên các khách hàng và tổng giá trị các đơn hàng của các khách hàng đó*/
SELECT C.customerName, sum(OD.priceEach * OD.quantityOrdered) AS total
FROM customers C
INNER JOIN orders O ON C.customerNumber = O.customerNumber
INNER JOIN orderdetails OD ON OD.orderNumber = O.orderNumber
GROUP BY C.customerNumber;


/*Đưa ra các đơn hàng, tên các khách hàng và tổng giá trị của đơn hàng đó.*/
SELECT O.orderNumber, C.customerName, SUM(quantityOrdered * priceEach) AS total
FROM orders O 
INNER JOIN orderdetails OD ON O.orderNumber = OD.orderNumber
INNER JOIN customers C ON O.customerNumber = C.customerNumber
GROUP BY O.orderNumber;

/*Mệnh đề LEFT JOIN sẽ được thực hiện như sau: khi một hàng từ bảng bên trái phù hợp 
với một hàng từ bảng bên phải dựa trên điều kiện nối, nội dung của hàng đó sẽ được lựa 
chọn như một dòng trong kết quả đầu ra. Khi một hàng trong bảng bên trái không tìm 
được hàng nào phù hợp trong bảng nối, nó vẫn được xuất hiện trong kết quả đầu ra, 
nhưng kết hợp với một hàng "giả" từ bảng bên phải với giá trị NULL cho tất cả các cột.*/
SELECT C.customerNumber, C.customerName,  O.orderNumber, O.status
FROM orders O 
LEFT JOIN customers C ON O.customerNumber = C.customerNumber;

SELECT C.customerNumber, customerName, orderNumber, O.status
FROM customers C
LEFT JOIN orders O ON O.customerNumber = C.customerNumber
WHERE orderNumber IS  NULL;



SELECT *
FROM employees e 
LEFT JOIN customers C ON e.employeeNumber = C.salesRepEmployeeNumber
WHERE customerNumber IS NULL;

/*
1. Đưa ra thông tin về các nhân viên và tên văn phòng nơi họ làm việc.
 Đưa ra thông tin về tên khách hàng và tên các sản phẩm họ đã mua.
2. Đưa ra thông tin về các mặt hàng chưa có ai đặt mua.
3. Đưa ra thông tin về các đơn hàng trong tháng 3/2005 (gồm orderDate, 
requiredDate, Status) và tổng giá trị của mỗi đơn hàng .
4. Đưa ra thông tin về các dòng sản phẩm và số lượng sản phẩm của dòng sản phẩm 
đó. Sắp xếp theo thứ tự số lượng giảm dần.
5. Ten khach hang va so tien ma ho da tra
*/
1:
SELECT e.employeeNumber, CONCAT(e.lastName, " ", e.firstName), Of.officeCode
FROM employees e
INNER JOIN offices Of ON e.officeCode = Of.officeCode;

SELECT *
FROM employees NATURAL JION offices;

SELECT C.customerNumber, c.customerName, OD.productCode, p.productName
FROM customers C 
INNER JOIN orders O ON C.customerNumber = O.customerNumber
INNER JOIN orderdetails OD ON O.orderNumber = OD.orderNumber
INNER JOIN products p ON OD.productCode = p.productCode;


SELECT O.orderNumber
FROM orders O 
LEFT JOIN orderdetails OD ON O.orderNumber = OD.orderNumber;

2:
SELECT p.productCode, p.productName, od.quantityOrdered
FROM products p LEFT JOIN orderdetails od ON  p.productCode = od.productCode
WHERE od.quantityOrdered is NULL;
    
3:
SELECT o.orderNumber, o.orderDate, o.requiredDate, o.shippedDate, SUM(od.quantityOrdered * od.priceEach) as total
FROM orders o INNER JOIN orderdetails od ON o.orderNumber = od.orderNumber
WHERE o.orderDate >= "2003/03/01" AND o.orderDate <= "2003/03/31"
GROUP BY o.orderNumber
ORDER BY total DESC;


4:
SELECT pl.productLine, pl.textDescription, pl.htmlDescription, COUNT(*) AS total 
FROM products p INNER JOIN productlines pl ON p.productLine = pl.productLine
GROUP BY p.productLine
ORDER BY total ASC;

5:
SELECT c.customerNumber, SUM(amount) AS total
FROM customers c, payments p
WHERE c.customerNumber = p.customerNumber
GROUP BY c.customerNumber;
           
6: tinh them so tien no 



1.SELECT Employees.*, Offices.addressLine1 FROM Employees INNER JOIN Offices ON Offices.officeCode = Employees.officeCode
2.SELECT Customers.*, Products.productLine FROM Customers INNER JOIN Orders ON Orders.customerNumber = Customers.customerNumber INNER JOIN OrderDetails ON Orders.orderNumber = OrderDetails.orderNumber INNER JOIN Products ON OrderDetails.productCode = Products.productCode
3.
SELECT Products.productLine, products.productName FROM Products LEFT JOIN OrderDetails ON Products.productCode = OrderDetails.productCode WHERE OrderDetails.quantityOrdered IS NULL
4.
SELECT orderDate, requiredDate, status, (OrderDetails.quantityOrdered*OrderDetails.priceEach) AS TotalMoney FROM Orders INNER JOIN OrderDetails ON Orders.orderNumber = OrderDetails.orderNumber
5.
SELECT productLine, COUNT(*) AS Total FROM Products GROUP BY productLine ORDER BY Total DESC 


