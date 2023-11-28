/*Cau 1:*/
CREATE TABLE rfm_model (
    customerName VARCHAR(50) NOT NULL PRIMARY KEY,
    recency decimal(32,2),
    frequency decimal(32,2),
    monetary decimal(32,2)
);

/*Cau 2:*/
INSERT INTO rfm_model (customerName, recency, frequency, monetary)
SELECT c.customerName,
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

/*2.1: max recency = 547*/
SELECT max(recency) AS "recency max value"
FROM rfm_model;

/*2.2: min = 2*/
SELECT MIN(recency) AS "recency min value"
FROM rfm_model;

/*2.3 max frequency:*/
SELECT MAX(frequency) AS "frequency max value"
FROM rfm_model;

/*2.4*/
SELECT MIN(frequency) AS "frequency min value"
FROM rfm_model;

/*Cau 6:*/
ALTER TABLE rfm_model
ADD COLUMN recency_score decimal(32,2), -- Thêm cột recency_score kiểu INT (hoặc kiểu dữ liệu phù hợp)
ADD COLUMN frequency_score decimal(32,2); -- Thêm cột frequency_score kiểu INT (hoặc kiểu dữ liệu phù hợp)

UPDATE rfm_model
CROSS JOIN (
    SELECT 
        ((MAX(recency) - MIN(recency)) / 5) AS d1,
        ((MAX(frequency) - MIN(frequency)) / 5) AS d2,
        MIN(recency) AS d1m,
        MAX(frequency) AS d2m
    FROM rfm_model
) AS tmp
SET recency_score =
    CASE 
        WHEN recency > ((d1m + 4 * d1) / 5) THEN 1
        WHEN recency > ((d1m + 3 * d1) / 5) THEN 2
        WHEN recency > ((d1m + 2 * d1) / 5) THEN 3
        WHEN recency > ((d1m + 1 * d1) / 5) THEN 4
        ELSE 5
    END,
frequency_score =
    CASE 
        WHEN frequency > ((d2m + 4 * d2) / 5) THEN 5
        WHEN frequency > ((d2m + 3 * d2) / 5) THEN 4
        WHEN frequency > ((d2m + 2 * d2) / 5) THEN 3
        WHEN frequency > ((d2m + 1 * d2) / 5) THEN 2
        ELSE 1
    END;

/*Cau 7:*/
select 
	(case
    when (recency_score <= 2 and frequency_score <= 2) then "Hibernating"
    when (recency_score = 3 and frequency_score <= 2) then "About to sleep"
    when (recency_score = 4 and frequency_score = 1) then "Promising"
    when (recency_score = 5 and frequency_score = 1) then "New Customers"
    when (recency_score >= 4 and frequency_score >= 1 and frequency_score <= 2) then "Potential Loyalists"
    when (recency_score = 3 and frequency_score = 3) then "Need Attention"
    when (recency_score <= 2 and frequency_score >= 3 and frequency_score <= 4) then "At Risk"
	when (recency_score <= 2 and frequency_score = 5) then "Cannot Lose them"
    when (recency_score >= 3 and recency_score <= 4 and frequency_score >= 4) then "Loyal Customers"
    when (recency_score >= 4 and frequency_score >= 4) then "Champions"
    end
    ) as segment,
    count(*)
from 
(select CustomerName, Recency, Frequency, Monetary,
	recency_score, frequency_score
from RFM_model
) AS t1
group by segment;