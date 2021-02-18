-- 프로그래머스 SQL 고득점 Kit
-- 이름이 없는 동물의 아이디
SELECT ANIMAL_ID	
FROM ANIMAL_INS 
WHERE NAME IS NULL

-- 이름이 있는 동물의 아이디
SELECT ANIMAL_ID
FROM ANIMAL_INS 
WHERE NAME IS NOT NULL
ORDER BY ANIMAL_ID ASC