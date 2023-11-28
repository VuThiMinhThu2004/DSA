CREATE DATABASE classicmodels;
USE classicmodels;

CREATE TABLE productlines (
    productLine VARCHAR(50) NOT NULL PRIMARY KEY,
    textDescription VARCHAR(4000),
    htmlDescription MEDIUMTEXT,
    image MEDIUMBLOB
);

CREATE TABLE products (
    productCode VARCHAR(15) NOT NULL PRIMARY KEY,
    productName VARCHAR(70) NOT NULL,
    productLine VARCHAR(50) NOT NULL,
    productScale VARCHAR(10) NOT NULL,
    productVendor VARCHAR(50) NOT NULL,
    quantityInstock SMALLINT(6) NOT NULL,
    buyPrice DOUBLE NOT NULL,
    MSRP DOUBLE NOT NULL
);

CREATE TABLE orderdetails (
    orderNumber INT(11) NOT NULL AUTO_INCREMENT,
    productCode VARCHAR(15) NOT NULL,
    quantityOrdered INT(11) NOT NULL,
    priceEach DOUBLE NOT NULL,
    orderLineNumber SMALLINT(6) NOT NULL,
    PRIMARY KEY(orderNumber, productCode)
);

CREATE TABLE orders (
    orderNumber INT(11) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    orderDate DATETIME NOT NULL,
    requiredDate DATETIME NOT NULL,
    shippedDate DATETIME,
    status VARCHAR(15) NOT NULL,
    comments TEXT,
    customerNumber INT(11) NOT NULL
);

CREATE TABLE customers (
    customerNumber INT(11) NOT NULL PRIMARY KEY,
    customerName VARCHAR(50) NOT NULL,
    contactLastName VARCHAR(50) NOT NULL,
    contactFirstName VARCHAR(50) NOT NULL,
    phone VARCHAR(50) NOT NULL,
    addressLine1 VARCHAR(50) NOT NULL,
    addressLine2 VARCHAR(50),
    city VARCHAR(50) NOT NULL,
    state VARCHAR(50),
    postalCode VARCHAR(50),
    country VARCHAR(50) NOT NULL,
    salesRepEmployeeNumber INT(11),
    creditLimit DOUBLE
);

CREATE TABLE employees (
    employeeNumber INT(11) NOT NULL PRIMARY KEY,
    lastName VARCHAR(50) NOT NULL,
    firstName VARCHAR(50) NOT NULL,
    extension VARCHAR(10) NOT NULL,
    email VARCHAR(100) NOT NULL,
    officeCode VARCHAR(10) NOT NULL,
    reportsTo INT(11),
    jobTitle VARCHAR(50) NOT NULL 
);

CREATE TABLE offices (
    officeCode VARCHAR(10) NOT NULL PRIMARY KEY,
    city VARCHAR(50) NOT NULL,
    phone VARCHAR(50) NOT NULL,
    addressLine1 VARCHAR(50) NOT NULL,
    addressLine2 VARCHAR(50),
    state VARCHAR(50),
    country VARCHAR(50) NOT NULL,
    postalCode VARCHAR(50) NOT NULL,
    territory VARCHAR(10) NOT NULL 
);

CREATE TABLE payments (
    customerNumber INT(11) NOT NULL AUTO_INCREMENT,
    checkNumber VARCHAR(50) NOT NULL,
    paymentDate DATETIME NOT NULL,
    amount DOUBLE NOT NULL,
    PRIMARY KEY(customerNumber, checkNumber)
);

ALTER TABLE products ADD CONSTRAINT fk_products_productlines FOREIGN KEY (productLine) REFERENCES productlines(productLine) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE orderdetails ADD CONSTRAINT fk_orderdetails_products FOREIGN KEY (productCode) REFERENCES products(productCode) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE orderdetails ADD CONSTRAINT fk_orderdetails_orders FOREIGN KEY (orderNumber) REFERENCES orders(orderNumber) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE orders ADD CONSTRAINT fk_orders_customers FOREIGN KEY (customerNumber) REFERENCES customers(customerNumber) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE payments ADD CONSTRAINT fk_payments_customers FOREIGN KEY (customerNumber) REFERENCES customers(customerNumber) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE employees ADD CONSTRAINT fk_employees_offices FOREIGN KEY (officeCode) REFERENCES offices(officeCode) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE customers ADD CONSTRAINT fk_customers_employees FOREIGN KEY (salesRepEmployeeNumber) REFERENCES employees(employeeNumber) ON DELETE RESTRICT ON UPDATE CASCADE;

ALTER TABLE employees ADD CONSTRAINT fk_employees_employees FOREIGN KEY (reportsTo) REFERENCES employees(employeeNumber) ON DELETE RESTRICT ON UPDATE CASCADE;

/*EXAMPLE*/

/*1. Get a list of employees with unspecified reportsTo field
de trn 1 line: SELECT * FROM employees WHERE reportsTo;
*/
SELECT *
FROM employees
WHERE reportsTo IS NULL;

/*2. Get a list of CustomerNumber that has made transactions*/
SELECT customerNumber FROM customers WHERE customerNumber IS NOT NULL;

/*3. Get a list of orders that have shipped on 18 Jan, 2003. Note: MySQL stores datetime 
data in the format of year/month/day (YYYY/MM/DD). 
Đưa ra danh sách các đơn hàng có ngày yêu cầu vận chuyển là "18/1/2003". Lưu 
ý: MySQL lưu dữ liệu ngày tháng theo định dạng năm/tháng/ngày => 2003-01-18*/
SELECT * FROM orders WHERE shippedDate = "2003-01-18";

/*4. Get a list of orders with the date placed in April 2005 and have status of ‘Shipped’.
Đưa ra danh sách các đơn hàng có ngày đặt trong tháng 4 năm 2005 và có trạng 
thái là ‘Shipped’*/
SELECT * FROM orders WHERE orderDate > "2005-04-00" AND orderDate < "2005-04-31" AND status = "Shipped";

/*5. Đưa ra danh sách các sản phẩm thuộc nhóm ‘Classic Cars’.
Get a list of products that are in the ‘Classic Cars’ category. */
SELECT * FROM products WHERE productLine = "Classic Cars";



/*EX*/
SELECT * FROM employees WHERE reportsTo IS NULL;


SELECT DISTINCT customerNumber FROM customers;


SELECT * FROM orders WHERE shippedDate = "2003-01-18";


SELECT * FROM orders WHERE (orderDate >= "2005-04-01" AND orderDate <= "2005-04-30") AND status = "Shipped";


SELECT * FROM products WHERE productLine = "Classic Cars";
SELECT DISTINCT productCode FROM products WHERE productLine = "Classic Cars";
