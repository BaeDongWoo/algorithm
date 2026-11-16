-- 코드를 입력하세요
select b.book_id, a.author_name, b.published_date
from (select * from book b where category = '경제') b
join author a
on b.author_id = a.author_id
order by b.published_date