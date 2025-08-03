/*
21년 04월 실기

*/
create database Test2104;

use Test2104;

create table EMP_TBL
(
 EMPNO int not null,
 SAL int not null
);

insert into EMP_TBL values(100, 1500);
insert into EMP_TBL values(200, 3000);
insert into EMP_TBL values(300, 2000);

select * from EMP_TBL;
select count(*) from emp_tbl where empno>100 and sal >=3000 or empno = 200;






