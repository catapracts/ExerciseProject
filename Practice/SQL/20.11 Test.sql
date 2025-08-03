/*
2020.11 4,5회 정보처리기사 실기

*/
create database Test;

use Test;

create table 학생
(
	학번 int not null,
    이름 varchar(40) not null,
    학년 int not null,
    학과 varchar(40) not null,
    주소 varchar(40)
);

select * from 학생;

insert into 학생(학번, 이름, 학년, 학과, 주소) values(1,'aaa',1,'전기','서울');
insert into 학생(학번, 이름, 학년, 학과, 주소) values(2,'bbb',2,'전자','대전');
insert into 학생(학번, 이름, 학년, 학과, 주소) values(3,'ccc',3,'정보','대구');
insert into 학생(학번, 이름, 학년, 학과, 주소) values(4,'ddd',2,'통신','부산');
insert into 학생(학번, 이름, 학년, 학과, 주소) values(5,'eee',1,'전기','전주');

select 학과, count(*) as 학과별튜플수 from 학생 group by 학과;



