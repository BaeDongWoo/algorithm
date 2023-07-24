-- 코드를 입력하세요
-- 온라인 상품 판매 정보를 담은 ONLINE_SALE 
-- 오프라인 상품 판매 정보를 담은 OFFLINE_SALE
-- 판매 날짜, 상품 ID , 유저 ID, 판매량 , 2022년 3월

select date_format(sales_date,'%Y-%m-%d') as SALES_DATE, PRODUCT_ID,USER_ID,SALES_AMOUNT
     from (select sales_date,PRODUCT_ID,USER_ID,SALES_AMOUNT
     from ONLINE_SALE where sales_date like '2022-03%') as A
        union 
     
     (select sales_date,PRODUCT_ID,NULL as USER_ID,SALES_AMOUNT
     from OFFLINE_SALE where sales_date like '2022-03%')

order by SALES_DATE,PRODUCT_ID,USER_ID

# select *from OFFLINE_SALE