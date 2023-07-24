-- 코드를 입력하세요
-- ANIMAL_OUTS 테이블에는 있지만 ANIMAL_INS 테이블에는 없는 동물 찾기
SELECT AO.ANIMAL_ID,AO.NAME
from ANIMAL_OUTS as AO
left outer join 
ANIMAL_INS as AI
on AO.ANIMAL_ID=AI.ANIMAL_ID
where AI.ANIMAL_ID is null
order by AO.ANIMAL_ID