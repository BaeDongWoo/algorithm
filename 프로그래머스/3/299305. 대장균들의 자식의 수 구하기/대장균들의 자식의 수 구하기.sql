-- 코드를 작성해주세요
# SELECT ED.ID , CC.PARENT_COUNT
# FROM ECOLI_DATA AS ED JOIN 
# (SELECT PARENT_ID , COUNT(PARENT_ID) AS PARENT_COUNT
# FROM ECOLI_DATA 
# GROUP BY PARENT_ID
# HAVING PARENT_ID IS NOT NULL) AS CC
# ON ED.ID = CC.PARENT_ID
SELECT ED1.ID , COUNT(ED2.PARENT_ID) AS CHILD_COUNT
FROM ECOLI_DATA AS ED1 LEFT JOIN ECOLI_DATA AS ED2
ON ED1.ID = ED2.PARENT_ID
GROUP BY ED1.ID
ORDER BY ED1.ID