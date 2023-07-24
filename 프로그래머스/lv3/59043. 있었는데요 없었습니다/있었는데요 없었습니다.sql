-- 코드를 입력하세요
-- 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회
-- 보호시작일이 빠른 순으로 조회 
SELECT AI.ANIMAL_ID,AI.NAME
from ANIMAL_INS as AI
inner join 
ANIMAL_OUTS as AO
on AI.ANIMAL_ID=AO.ANIMAL_ID
where AI.datetime>AO.datetime
order by AI.datetime