-- 코드를 입력하세요
SELECT FH.FLAVOR
FROM FIRST_HALF AS FH 
JOIN ICECREAM_INFO AS II
ON FH.FLAVOR = II.FLAVOR
AND FH.TOTAL_ORDER > 3000 AND II.INGREDIENT_TYPE = 'fruit_based';


# SELECT FLAVOR 
# FROM FIRST_HALF AS A 
# WHERE A.TOTAL_ORDER > 3000