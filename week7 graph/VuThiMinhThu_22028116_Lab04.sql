/*cau1*/
SELECT *
FROM customers
WHERE city IN ('Nantes', 'Lyon');

SELECT *
FROM customers
WHERE city = 'Nantes' OR city = 'Lyon';


/*cau2*/
SELECT *
FROM orders
WHERE shippedDate BETWEEN "2003/01/10" AND "2003/03/10";

SELECT *
FROM orders
WHERE shippedDate >= "2003/01/10" AND shippedDate <= "2003/03/10";


/*Cau3*/
SELECT *
FROM productlines
WHERE productLine LIKE "%Cars%";


/*Cau4*/
SELECT *
FROM products
ORDER BY quantityInstock DESC
LIMIT 10;




/*Bai tap kiem tra*/
/*Cau 2.2*/
SELECT employeeNumber, jobTitle
FROM employees
WHERE jobTitle IN ('Sales Rep', 'Sales Manager (APAC)', 'Sale Manager (EMEA)')
ORDER BY employeeNumber ASC;


/*Cau3*/
SELECT productName, productCode
FROM products
WHERE productCode = 'S24' AND MSRP BETWEEN 150 AND 200
ORDER BY buyPrice ASC, productName ASC
LIMIT 20;


/*BT them: tinh rate = (MSRP - buyPrice)/buyPrice va hien thi ten cua no, co rate cao nhat tren he thong */
SELECT productName, (MSRP - buyPrice)/buyPrice as rate
FROM products
ORDER BY rate DESC
LIMIT 1;


SELECT productName, AVG((MSRP - buyPrice)/buyPrice) as rate
FROM products
ORDER BY rate ASC;

/*Hien thi cac san pham co rate > rateTrungBinh SQL08 */
SELECT productName, (MSRP - buyPrice)/buyPrice as rate, AVG((MSRP - buyPrice)/buyPrice) as rateTB
FROM products
WHERE rate > rateTB
ORDER BY rate ASC;