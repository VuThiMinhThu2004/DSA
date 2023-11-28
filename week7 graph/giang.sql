select max(Recency) from RFM_model;
select min(Recency) from RFM_model where Recency is not null;
select max(Frequency) from RFM_model;
select min(Frequency) from RFM_model;

-- Phan này em chưa biết alter và update sao cho hợp lý ạ tại nó báo lỗi không được specify target chính bảng đấy khi update
-- Vì những khách hàng chưa thực hiện giao dịch khả năng là khách hàng mới nên em sẽ để họ có recency là 5 ạ
-- Phần segment em có làm ở dưới. (line 36 ạ)
(select CustomerName, Recency, Frequency, Monetary,
	(case
		when (Recency is null) then 5
		when (Recency >= min_recency and Recency < min_recency + (max_recency - min_recency) * 1 / 5) then 5
        when (Recency >= min_recency + (max_recency - min_recency) * 1 / 5 and Recency < min_recency + (max_recency - min_recency) * 2 / 5) then 4
        when (Recency >= min_recency + (max_recency - min_recency) * 2 / 5 and Recency < min_recency + (max_recency - min_recency) * 3 / 5) then 3
        when (Recency >= min_recency + (max_recency - min_recency) * 3 / 5 and Recency < min_recency + (max_recency - min_recency) * 4 / 5) then 2
        when (Recency >= min_recency + (max_recency - min_recency) * 4 / 5 and Recency <= max_recency) then 1
	end) as recency_score,
	(case
		when (Frequency = 0) then 1
		when (Frequency >= min_frequency and Frequency < min_frequency + (max_frequency - min_frequency) * 1 / 5) then 1
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 1 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 2 / 5) then 2
		when (Frequency >= min_frequency + (max_frequency - min_frequency) * 2 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 3 / 5) then 3
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 3 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 4 / 5) then 4
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 4 / 5 and Frequency <= max_frequency) then 5
	end) as frequency_score
from (
    select *,
		(select min(recency) from RFM_model)  as min_recency,
        (select max(recency) from RFM_model)  as max_recency,
        (select min(frequency) from RFM_model) as min_frequency,
        (select max(frequency) from RFM_model) as max_frequency
    from RFM_model
) as t1);


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
	(case
		when (Recency is null) then 5
		when (Recency >= min_recency and Recency < min_recency + (max_recency - min_recency) * 1 / 5) then 5
        when (Recency >= min_recency + (max_recency - min_recency) * 1 / 5 and Recency < min_recency + (max_recency - min_recency) * 2 / 5) then 4
        when (Recency >= min_recency + (max_recency - min_recency) * 2 / 5 and Recency < min_recency + (max_recency - min_recency) * 3 / 5) then 3
        when (Recency >= min_recency + (max_recency - min_recency) * 3 / 5 and Recency < min_recency + (max_recency - min_recency) * 4 / 5) then 2
        when (Recency >= min_recency + (max_recency - min_recency) * 4 / 5 and Recency <= max_recency) then 1
	end) as recency_score,
	(case
		when (Frequency = 0) then 1
		when (Frequency >= min_frequency and Frequency < min_frequency + (max_frequency - min_frequency) * 1 / 5) then 1
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 1 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 2 / 5) then 2
		when (Frequency >= min_frequency + (max_frequency - min_frequency) * 2 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 3 / 5) then 3
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 3 / 5 and Frequency < min_frequency + (max_frequency - min_frequency) * 4 / 5) then 4
        when (Frequency >= min_frequency + (max_frequency - min_frequency) * 4 / 5 and Frequency <= max_frequency) then 5
	end) as frequency_score
from (
    select *,
		(select min(recency) from RFM_model)  as min_recency,
        (select max(recency) from RFM_model)  as max_recency,
        (select min(frequency) from RFM_model) as min_frequency,
        (select max(frequency) from RFM_model) as max_frequency
    from RFM_model
) as t1) as t2
group by segment;