-- 코드를 입력하세
select CAR_TYPE,count(car_type) as CARS
from CAR_RENTAL_COMPANY_CAR
where OPTIONS like "%가죽시트%" or OPTIONS like "%통풍시트%"  or OPTIONS like "%열선시트%"
group by car_type
order by car_type