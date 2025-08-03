create database Test2110;

use Test2110;

create table A
(
 NAME varchar(40) not null
);

insert into A values('Smith');
insert into A values('Allen');
insert into A values('Scott');

create table B
(
 RULE varchar(40) not null
);

insert into B values('S%');
insert into B values('%t%');

select count(*) cnt from a cross join b where a.name like b.rule;


