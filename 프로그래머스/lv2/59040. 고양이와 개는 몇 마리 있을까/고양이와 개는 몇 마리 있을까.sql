-- 코드를 입력하세요
SELECT ANIMAL_TYPE,count(ANIMAL_TYPE) as count
from ANIMAL_INS 
where ANIMAL_TYPE='cat' or ANIMAL_TYPE='dog'
group by ANIMAL_TYPE
order by ANIMAL_TYPE