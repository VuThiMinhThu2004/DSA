SELECT CONCAT_WS(char(10),CONCAT_WS('; ', contactLastName, contactFirstName),addressLine1, addressLine2,
                 CONCAT_WS(' ', postalCode, city), country,		    
				 CONCAT_WS(char(10), ''))
AS customerAddress
FROM customers;


UPDATE products
SET productDescription  = REPLACE(productDescription, 'abuot', 'about');



SELECT customerNumber, customerName,
	   IF(state IS NULL, 'N/A', state) state,
       country
FROM customers;


SELECT SUM(IF(status = 'shipped', 1, 0)) AS Shipped,
	   SUM(IF(status= 'Cancelled', 1, 0)) AS Cancelled
FROM orders;
           
		

CREATE TABLE tbl(
id INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
 description varchar(250) NOT NULL
);
Sau đó, chúng ta sử dụng hàm LAST_INSERT_ID () để có được ID mới chèn.
INSERT INTO tbl(description)
VALUES('MySQL last_insert_id');
Thực hiện truy vấn: 
SELECT LAST_INSERT_ID();           
		


SELECT DATEDIFF('2011-08-17','2011-08-08');

/* Để tính toán số ngày còn lại giữa ngày vận chuyển và ngày yêu cầu để trong đơn 
đặt hàng, chúng ta sử dụng DATEDIFF như sau*/
SELECT orderNumber,
DATEDIFF(requiredDate, shippedDate) AS daysLeft
FROM orders
ORDER BY daysLeft DESC
LIMIT 25;


/*Hàm ADDDATE: trả về một giá trị thời gian là kết quả của thao tác trên một giá trị thời gian 
khác*/
/*Ví dụ: đưa ra ngày tháng sau ngày giờ hiện tại 30 ngày:*/
SELECT ADDDATE(NOW(), INTERVAL 30 DAY);

/*Ví dụ: đưa ra các đơn đặt hàng trong khoảng 30 ngày tính từ ngày 1/5/2005*/
/*đưa ra các đơn đặt hàng trong khoảng 30 ngày tính từ ngày 1/5/2005*/
SELECT orderNumber, orderDate
FROM orders
WHERE orderDate >='2005-05-01' AND orderDate < ADDDATE('2005-05-01', INTERVAL 30 DAY);


/*đưa ra các đơn đặt hàng tính từ trước ngày 1/5/2005, 30 ngày đến ngày 1/5/2005
Nếu thời gian cộng vào là tháng, năm thì từ khóa tương ứng được sử dụng là MONTH, 
YEAR. */
SELECT * 
FROM orders
WHERE orderDate<= '2005-5-1' AND orderDate > ADDDATE('2005-5-1', INTERVAL -30 DAY);

SELECT *
FROM orders
WHERE orderDate <= '2005-05-01' AND orderDate >= ADDDATE('2005-05-01', INTERVAL - 1 MONTH);


/*Hàm EXTRACT: tách ra các giá trị như ngày, tháng, năm từ một giá trị có kiểu thời 
gian*/
SELECT EXTRACT(MONTH FROM '2004-12-31 23:59:59');
MONTH('2004-12-31 23:59:59');

SELECT EXTRACT(MONTH FROM '2004-12-31 23:59:59');


/*đưa ra các đơn hàng đặt năm 2005*/
SELECT orderNumber
FROM orders
WHERE EXTRACT(YEAR FROM orderDate) = 2005;
WHERE YEAR(orderDate) = 2005;

SELECT orderNumber
FROM orders
WHERE EXTRACT(YEAR FROM orderDate) = 2005 AND EXTRACT(MONTH FROM orderDate) = 5;



/*Bài tập thực hành:
1. Lấy ra 50 ký tự đầu tiên của phần mô tả sản phẩm, đặt tên là ‘Title of products’
*/
SELECT SUBSTRING(productDescription, 1, 50)  AS titleOfProducts
FROM products

SELECT LEFT(productDescription, 50) AS titleOfProducts
FROM products;


/*
2. Đưa ra mô tả về các nhân viên theo định dạng ‘Fullname, jobTitle.’*/
SELECT CONCAT(LastName,' ', Firstname, ' - ', jobTitle) as DESCRIPTION
FROM employees;
/*3. Update the employees’ information whose jobTitle is ‘Sales Rep’ to ‘Sales 
Representative’.*/
UPDATE employees
SET jobTitle = REPLACE(jobTitle, 'Sales Rep', 'Sales Representative');

/*4. Tìm 5 đơn hàng được vận chuyển sớm nhất so với ngày yêu cầu hẹn.
Get 5 orders shipped sooner than the required date*/
SELECT orderNumber, requiredDate, shippedDate,
	(requiredDate - shippedDate) as dayleft
FROM orders
WHERE shippedDate IS NOT NULL
ORDER BY dayLeft DESC
LIMIT 5;


SELECT orderNumber, requiredDate, shippedDate,
	DATEDIFF(requiredDate, shippedDate) as timeLeft
FROM orders
ORDER BY timeLeft DESC
LIMIT 5;

/*5. Đưa ra các đơn đặt hàng trong tháng 5 năm 2005 và có ngày chuyển hàng đến 
chưa xác định.
5. Get the orders in May 2005 with an unspecified shipped date.*/
SELECT *
FROM orders
WHERE shippedDate is NULL;



/*bai tap them*/
(SELECT productCode, productName, buyPrice, MSRP,
		(MSRP - buyPrice)/buyPrice AS rate,
        "Highest" AS Note
FROM products
ORDER BY rate DESC
LIMIT 1)

UNION

(SELECT productCode, productName, buyPrice, MSRP,
		(MSRP - buyPrice)/buyPrice AS rate,
        "Lowest" AS Note
FROM products
ORDER BY rate ASC
LIMIT 1);

/*Thu2*/
SELECT lastName, fullName, salary
FROM employees
WHERE salary > (
	SELECT AVERAGE(salary) as AVG_Salary
	FROM employees
	ORDER BY DESC LIMIT 1;
)
/*CONCAT_WS(seperator, , ..., )
CONCAT_WS("---", addressLine1, addressLine2, phoneNumber) AS Infor
WS: with seperator: dinh nghia san dau phan cach giua cac truong trong ham CONCAT_WS
XU li dc ca giu lieu NULL. Neu du lieu NULL thi no se tu loai bo
nhu vd kia thi addressLine2 co the NULL

- Con ham CONCAT thi khong tu xu li dc du lieu NULL -> khi ker hop voi 1 cai du lieu NULL-> ket qua se hien thi NULL luon
Xu li dieu kien thi co Ham IF neu dung concat
IF(addressLine2 IS NULL, addressLine1, CONCAT(addressLine1," ---- ", addressLine2))

IF(expr, if_true, if_false)

DATEDIFF(date1, date2) = date1-date2
*/

SELECT orderDate, shippedDate,
	DATEDIFF(shippedDate, orderDate) AS DAYLEFT
    FROM orders
    WHERE status = "Shipped"
    ORDER BY DAYLEFT ASC;

/*Ngay yeu thich duoc dat hang nhieu nhat tren he thong*/
SELECT SUBSTR(productDescription, 1, 50) 
FROM products;

SELECT CONCAT_WS(" - ", LastName, Firstname, jobTitle) as Information
FROM employees;

SELECT orderNumber, DATEDIFF(requiredDate, shippedDate) AS dayLeft
FROM orders
ORDER BY dayLeft DESC LIMIT 5;

SELECT orderNumber, orderDate, shippedDate
FROM orders
WHERE shippedDate IS NULL AND YEAR(orderDate) = 2005 AND MONTH(orderDate) = 5;

/*bai tap them De 1*/
/*cau 4*/
SELECT CONCAT_WS(',', contactLastName, contactFirstName) AS fullName,
	   CONCAT_WS('-', addressLine1, addressLine2, city, country, postalCode) as Infor
FROM customers;


/*cau 5: dayLeft khong phai 1 truong du lieu nen phai dung HAVING*/
SELECT orderNumber, orderDate, requiredDate,
	LEFT(comments, 20) as comments,
	DATEDIFF(requiredDate, orderDate) as dayLeft
	   
FROM orders
WHERE comments IS NOT NULL AND YEAR(orderDate) = 2003 AND (MONTH(orderDate) = 3 OR MONTH(orderDate) = 4)
HAVING dayLeft < 15;

/*Cau 6*/
SELECT  MSRP, productLine, (MSRP - buyPrice)/MSRP*100 AS rate
	  
FROM products
ORDER BY rate;


/*bai tap them de 2*/

(SELECT productCode, sum(quantityOrdered)), "best_buy" AS Note

MIN(sum(quantityOrdered)), "worst_buy" AS Note
FROM orderdetails