create database Test2205;

use Test2205;

create table 성적
(
	name varchar(40) not null,
    class varchar(40) not null,
    score int not null
);

insert 성적 values('정기찬', 'A', 85);
insert 성적 values('이영호', 'C', 74);
insert 성적 values('환정형', 'C', 95);
insert 성적 values('김지수', 'A', 90);
insert 성적 values('최은영', 'B', 82);

select * from 성적;
select name, score from 성적 order by score desc;