-- 코드를 입력하세요
-- 아직 입양을 못간 동물들 
-- ins 테이블에는 있지만 outs 테이블에는 없는 동물들 
SELECT AI.NAME,AI.DATETIME
from ANIMAL_INS as AI
left outer join ANIMAL_OUTS as AO
on AI.ANIMAL_ID = AO.ANIMAL_ID
where AO.ANIMAL_ID is null
order by AI.DATETIME limit 3
