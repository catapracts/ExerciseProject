create database Test2210;

use Test2210;

create table 부서
(
 부서코드 int primary key,
 부서명 varchar(20)
);

create table 직원
(
 직원코드 int primary key,
 부서코드 int,
 직원명 varchar(20),
 foreign key(부서코드) references 부서(부서코드) on delete cascade
);

insert into 부서 values(10, '영업부');
insert into 부서 values(20, '기획부');
insert into 부서 values(30, '개발부');

insert into 직원 values(1001, 10, '이진수');
insert into 직원 values(1002, 10, '곽연경');
insert into 직원 values(1003, 20, '김선길');
insert into 직원 values(1004, 20, '최민수');
insert into 직원 values(1005, 20, '이용갑');
insert into 직원 values(1006, 30, '박종일');
insert into 직원 values(1007, 30, '이미경');

select distinct count(부서코드) from 직원 where 부서코드 = 20;
delete from 부서 where 부서코드 = 20;
select distinct count(부서코드) from 직원;

