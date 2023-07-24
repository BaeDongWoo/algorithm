-- 코드를 입력하세요
SELECT 
FLOOR(price/10000)*10000 as pr, count(PRODUCT_ID)
from product
group by pr 
order by pr