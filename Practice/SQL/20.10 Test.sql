/*
2020.10 정보처리기사 실기
*/
create database Test2010;

/*2305에서 문제와 답 그대로 제출됨*/

use Test2010;

create Table 학생
(
 이름 varchar(40) not null,
 학번 int
);

insert into 학생 values('민수', 1);
insert into 학생 values('철수', 2);
insert into 학생 values('영희', 3);
insert into 학생 values('바둑이', 4);

select * from 학생;
delete from 학생 where 이름 = '민수';
select * from 학생;

create table 성적
(
 학번 varchar(40) not null,
 과목번호 int not null,
 과목이름 varchar(40) not null,
 학점 int not null,
 점수 int not null 
);

select * from 성적;
insert into 성적 values('a2001', 101, '컴퓨터구조', 6, 95);
insert into 성적 values('a2002', 101, '컴퓨터구조', 6, 84);
insert into 성적 values('a2003', 302, '데이터베이스', 5, 89);
insert into 성적 values('a2004', 201, '인공지능', 5, 92);
insert into 성적 values('a2005', 302, '데이터베이스', 5, 100);
insert into 성적 values('a2006', 302, '데이터베이스', 5, 88);
insert into 성적 values('a2007', 201, '인공지능', 5, 93);
select * from 성적;

select 과목번호, min(점수) as 최소점수, max(점수) as 최대점수 from 성적 group by 과목이름 having avg(점수)>=90;

select @@sql_mode;
SET SESSION sql_mode = 'STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

create table 속성정의서
(
 속성명 char(10) unique,
 이름 varchar(8) not null,
 주민번호 char(13),
 학과 varchar(16),
 학년 int
);

alter table 속성정의서 add 주소 varchar(20);
