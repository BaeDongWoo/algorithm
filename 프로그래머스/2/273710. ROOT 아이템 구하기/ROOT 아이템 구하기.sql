-- 코드를 작성해주세요
SELECT II.ITEM_ID , II.ITEM_NAME
FROM ITEM_INFO AS II
JOIN 
    (SELECT ITEM_ID 
    FROM ITEM_TREE 
    WHERE PARENT_ITEM_ID IS NULL) AS IT
ON II.ITEM_ID = IT.ITEM_ID
ORDER BY II.ITEM_ID