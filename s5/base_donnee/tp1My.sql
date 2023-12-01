-- 0)

drop database if exists bd_yassin;
CREATE DATABASE bd_yassin;
USE bd_yassin;

drop table if exists pilote;
drop table if exists avion;
drop table if exists vol;


-- 1)

create table pilote (
   plnum int primary key,
   plnom varchar(40),
   plprenom varchar(20),
   ville varchar(40),
   salaire decimal(9,3)
      );

create table avion (
   avnum int primary key,
   avnom varchar(40),
   capacite int,
   localisation varchar(40)
      );

create table vol(
   volnum int primary key,
   plnum int references pilote (plnum),
   avnum int references avion (avnum),
   villedep varchar(40),
   villearr varchar(40),
   heurdep int,
   heurarr int
      );

-- 2)


INSERT INTO pilote VALUES (1, 'Zighed', 'Djamel', 'Paris', 21000);
INSERT INTO pilote VALUES (2, 'Boussaid', 'Omar', 'Toulouse', 21000);
INSERT INTO pilote VALUES (3, 'Viallaneix', 'Jacques', 'Nice', 18000);
INSERT INTO pilote VALUES (4, 'Nicolloyannis', 'Nicolas', 'Paris', 17000);
INSERT INTO pilote VALUES (5, 'Darmont', 'Jerome', 'Toulouse', 19000);
INSERT INTO pilote VALUES (6, 'Lallich', 'Stephane', 'Paris', 18000);
INSERT INTO pilote VALUES (7, 'Rakotomalala', 'Ricco', 'Nice', 17000);
INSERT INTO pilote VALUES (8, 'Chauchat', 'Jean-Hughes', 'Lyon', 15000);
INSERT INTO pilote VALUES (9, 'Muhboubi', 'Hadj', 'Nice', 18000);
INSERT INTO pilote VALUES (10, 'Bentayeb', 'Fadila', 'Paris', 20000);

INSERT INTO avion VALUES(1, 'A300', 300, 'Nice');
INSERT INTO avion VALUES(2, 'A310', 300, 'Nice');
INSERT INTO avion VALUES(3, 'B707', 250, 'Paris');
INSERT INTO avion VALUES(4, 'A300', 280, 'Lyon');
INSERT INTO avion VALUES(5, 'Concorde', 160, 'Nice');
INSERT INTO avion VALUES(6, 'B747', 460, 'Paris');
INSERT INTO avion VALUES(7, 'B707', 250, 'Paris');
INSERT INTO avion VALUES(8, 'A310', 300, 'Toulouse');
INSERT INTO avion VALUES(9, 'Mercure', 180, 'Lyon');
INSERT INTO avion VALUES(10, 'Concorde', 160, 'Paris');


INSERT INTO vol VALUES  (1, 1, 1, 'Nice', 'Toulouse', 11, 12);
INSERT INTO vol VALUES  (2, 1, 8, 'Paris', 'Toulouse', 17, 18);
INSERT INTO vol VALUES  (3, 2, 1, 'Toulouse', 'Lyon', 14, 16);
INSERT INTO vol VALUES  (4, 5, 3, 'Toulouse', 'Lyon', 18, 20);
INSERT INTO vol VALUES  (5, 9, 1, 'Paris', 'Nice', 6, 8);
INSERT INTO vol VALUES  (6, 10, 2, 'Lyon', 'Nice', 11, 12);
INSERT INTO vol VALUES  (7, 1, 4, 'Paris', 'Lyon', 8, 9);
INSERT INTO vol VALUES  (8, 8, 4, 'Nice', 'Paris', 7, 8);
INSERT INTO vol VALUES  (9, 1, 8, 'Nantes', 'Lyon', 9, 15);
INSERT INTO vol VALUES  (10, 8, 2, 'Nice', 'Paris', 12, 13);
INSERT INTO vol VALUES  (11, 9, 2, 'Paris', 'Lyon', 15, 16);
INSERT INTO vol VALUES  (12, 1, 2, 'Lyon', 'Nantes', 16, 20);
INSERT INTO vol VALUES  (13, 4, 5, 'Nice', 'Lens', 11, 14);
INSERT INTO vol VALUES  (14, 3, 5, 'Lens', 'Paris', 15, 16);
INSERT INTO vol VALUES  (15, 8, 9, 'Paris', 'Toulouse', 17, 18);
INSERT INTO vol VALUES  (16, 7, 5, 'Paris', 'Toulouse', 18, 19);


-- II 
      -- 1)
INSERT INTO vol VALUES (17, 5, 8, 'Bordeaux', 'Clermont-Fd', 12 , 13),(18, 10, 7, 'Paris', 'Lille', 11, 12);

      -- 2)
update vol
set villedep = 'Lille', heurarr = 17
where volnum = 14;

      --3)
delete from vol
where volnum = 17;

-- III 
      -- 1)
select plnom from pilote;

      -- 2)
select plnom 
from pilote 
order by plnom asc;

      -- 3)
select plnom,salaire 
from pilote 
order by salaire desc, plnom;

      -- 4)
select avg (salaire) 
from pilote;

      -- 5)
select ville,avg(salaire) 
from pilote 
group by ville;

      -- 6)
select DISTINCT avnom 
from avion 
order by avnom;

      -- 7)
select count(*) 
from avion 
where localisation = 'Paris'; -- */loclisation/avnom or any column in avion in count()

      -- 8)
select count(*) 
from avion 
where localisation <> 'Paris';

      -- 9)
select max(sm) as max_salaire
from (select ville,avg(salaire) as sm
      from pilote 
      group by ville) pilote;  -- pilote/tttt/shdf/sup/ any thing not *;

   /*
select ville,avg(salaire) as max_salaire
from pilote
group by ville
order by max_salaire desc
limit 1;

    */
     -- 10)
select ville,avg(salaire) as avg_salaire
from pilote
group by ville
order by avg_salaire desc
limit 1;
   /*
select ville,max(sm) as max_Salaire
from (select ville,avg(salaire) as sm
      from pilote 
      group by ville) tttt
group by ville 
order by max_Salaire desc
limit 1;
   */
      
