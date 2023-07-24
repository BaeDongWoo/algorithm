-- 코드를 입력하세요
-- 중고거래 게시판 정보를 담은 USED_GOODS_BOARD
-- 중고거래 게시판 첨부파일 정보를 담은 USED_GOODS_REPLY
SELECT b.TITLE,b.BOARD_ID,r.REPLY_ID,r.WRITER_ID,r.CONTENTS,date_format(r.CREATED_DATE,"%Y-%m-%d") CREATED_DATE
from USED_GOODS_BOARD b, USED_GOODS_REPLY r 

where b.BOARD_ID = r.BOARD_ID and
date_format(b.CREATED_DATE,"%Y%m")=202210 

order by r.CREATED_DATE ,b.TITLE