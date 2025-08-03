create database Test2107;

use Test2107;

create table 회원
(
 회원번호 int not null,
 이름 varchar(40) not null,
 성별 varchar(20) not null,
 가입일 varchar(40) not null
);

insert into 회원 values(1001, '이진성', '남', '2021-06-23');
insert into 회원 values(1002, '조이령', '여', '2021-06-24');
insert into 회원 values(1003, '최민수', '남', '2021-06-28');
insert into 회원 values(1004, '김차희', '여', '2021-07-03');
insert into 회원 values(1005, '이미경', '여', '2021-07-10');

delete from 회원 where 회원번호 = 1001;

select * from 회원;
select * from 회원 where 이름 like '이%' order by 가입일 desc;


create table 사원
(
 코드 int not null,
 이름 varchar(40) not null,
 부서 varchar(40)
);


insert into 사원 values(1601, '김명해', '인사');
insert into 사원 values(1602, '이진성', '경영지원');
insert into 사원 values(1731, '박영광', '개발');
insert into 사원 values(2001, '이수진', ' ');
select * from 사원;


create table 동아리
(
 코드 int not null,
 동아리명 varchar(40)
);

insert into 동아리 values(1601, '테니스');
insert into 동아리 values(1731, '탁구');
insert into 동아리 values(2001, '볼링');
select * from 동아리;

select a.코드, 이름, 동아리명 from 사원 a LEFT JOIN 동아리 b on a.코드 = b.코드;


create table 학부생
(
 학부 varchar(30) not null,
 학과번호 int not null,
 입학생수 int not null,
 담당관 varchar(30) not null
);

insert into 학부생 values('정경대학', 110, 300, '김해율');
insert into 학부생 values('공과대학', 310, 250, '김성수');
insert into 학부생 values('인문대학', 120, 400, '김해율');
insert into 학부생 values('정경대학', 120, 300, '김성수');
insert into 학부생 values('인문대학', 410, 180, '이율해');
select * from 학부생;

update 학부생 set 학과번호 = 999 where 입학생수 >= 300;


