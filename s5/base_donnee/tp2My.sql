-- 0)  if not use update cascade use prof solution
DROP DATABASE IF EXISTS bd_yassin2_cirque;
CREATE DATABASE bd_yassin2_cirque;
USE bd_yassin2_cirque;

DROP TABLE IF EXISTS PERSONNEL ;
DROP TABLE IF EXISTS NUMERO;
DROP TABLE IF EXISTS ACCESSOIRE;
DROP TABLE IF EXISTS UTILISATION;

-- 1)
CREATE TABLE PERSONNEL(
   nom VARCHAR(20),
   role VARCHAR(20),
   CONSTRAINT personnel_pk PRIMARY KEY (nom)
);

CREATE TABLE NUMERO(
   titre VARCHAR(30),
   nature VARCHAR(20),
   responsable VARCHAR(20),
   CONSTRAINT numero_pk PRIMARY KEY (titre),
   CONSTRAINT numero_fk FOREIGN KEY (responsable) REFERENCES PERSONNEL(nom)
);

CREATE TABLE ACCESSOIRE(
   nom VARCHAR(30),
   couleur VARCHAR(10),
   volume DECIMAL(5,2),
   ratelier DECIMAL(2),
   camion DECIMAL(1),
   CONSTRAINT accessoire_pk PRIMARY KEY (nom)
);

CREATE TABLE UTILISATION(
   titre VARCHAR(30),
   utilisateur VARCHAR(20),
   accessoire VARCHAR(30),
   CONSTRAINT utilisation_pk PRIMARY KEY(titre,utilisateur,accessoire),
   CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre),
   CONSTRAINT utilisation_fk2 FOREIGN KEY(utilisateur) REFERENCES PERSONNEL(nom),
   CONSTRAINT utilisation_fk3 FOREIGN KEY(accessoire) REFERENCES ACCESSOIRE(nom)
);

-- 2)
INSERT INTO PERSONNEL VALUES('Clovis', 'Jongleur');
INSERT INTO PERSONNEL VALUES('Reine de May', 'Ecuyer');
INSERT INTO PERSONNEL VALUES('Louche', 'Clown');
INSERT INTO PERSONNEL VALUES('Attention', 'Equilibriste');
INSERT INTO PERSONNEL VALUES('Partition', 'Musicien');
INSERT INTO PERSONNEL VALUES('Crinière', 'Dompteur');
INSERT INTO PERSONNEL VALUES('Jerry', 'Clown');
INSERT INTO PERSONNEL VALUES('Bal', 'Jongleur');
INSERT INTO PERSONNEL VALUES('Final', 'Musicien');
INSERT INTO PERSONNEL VALUES('Louis', 'Jongleur');
INSERT INTO PERSONNEL VALUES('Léo', 'Jongleur');
INSERT INTO PERSONNEL VALUES('Lulu', 'Ecuyer');
INSERT INTO PERSONNEL VALUES('Coloquinte', 'Equilibriste');
INSERT INTO PERSONNEL VALUES('Grostas', 'Jongleur');
INSERT INTO PERSONNEL VALUES('Sangtrèspur', 'Dompteur');

INSERT INTO NUMERO VALUES('Les Zoupalas', 'Jonglerie', 'Clovis');
INSERT INTO NUMERO VALUES('Le coche infernal', 'Equitation', 'Reine de May');
INSERT INTO NUMERO VALUES('Les fauves', 'Clownerie', 'Louche');
INSERT INTO NUMERO VALUES('Les Smilers', 'Equilibre', 'Attention');
INSERT INTO NUMERO VALUES('La passoire magique', 'Lion', 'Crinière');
INSERT INTO NUMERO VALUES('Les Zozos', 'Clownerie', 'Jerry');
INSERT INTO NUMERO VALUES('Les Tartarins', 'Jonglerie', 'Bal');

INSERT INTO ACCESSOIRE VALUES('Ballon', 'Rouge', 0.3, 15, 5);
INSERT INTO ACCESSOIRE VALUES('Barre', 'Blanc', 0.6, 19, 5);
INSERT INTO ACCESSOIRE VALUES('Fouet', 'Marron', 0.2, 11, 3);
INSERT INTO ACCESSOIRE VALUES('Bicyclette à éléphant', 'Vert', 0.4, 27, 8);
INSERT INTO ACCESSOIRE VALUES('Trompette', 'Rouge', 0.2, 2, 1);
INSERT INTO ACCESSOIRE VALUES('Cercle magique', 'Magique',  0.2, 1, 1);
INSERT INTO ACCESSOIRE VALUES('Boule', 'Cristal', 0.2,  88, 1);
INSERT INTO ACCESSOIRE VALUES('Cage à lions', 'Noir', 10.0, 0, 2);
INSERT INTO ACCESSOIRE VALUES('Chaise longue de lion', 'Bleu',  0.9, 11, 5);
INSERT INTO ACCESSOIRE VALUES('Peigne de chimpanzé', 'Jaune', 0.2, 23, 3);
INSERT INTO ACCESSOIRE VALUES('Etrier', NULL, NULL, NULL, NULL);

INSERT INTO UTILISATION VALUES('Les Zoupalas', 'Louis', 'Ballon');
INSERT INTO UTILISATION VALUES('Les Zoupalas', 'Léo','Ballon');
INSERT INTO UTILISATION VALUES('Les Zoupalas', 'Louis','Barre');
INSERT INTO UTILISATION VALUES('Le coche infernal', 'Grostas', 'Bicyclette à éléphant');
INSERT INTO UTILISATION VALUES('Le coche infernal', 'Lulu', 'Fouet');
INSERT INTO UTILISATION VALUES('Les fauves', 'Jerry', 'Trompette');
INSERT INTO UTILISATION VALUES('Les Smilers', 'Attention', 'Cercle magique');
INSERT INTO UTILISATION VALUES('Les Smilers', 'Attention', 'Boule');
INSERT INTO UTILISATION VALUES('Les Smilers', 'Coloquinte', 'Bicyclette à éléphant');
INSERT INTO UTILISATION VALUES('La passoire magique', 'Crinière', 'Cage à lions');
INSERT INTO UTILISATION VALUES('La passoire magique', 'Crinière', 'Chaise longue de lion');
INSERT INTO UTILISATION VALUES('Les Zozos', 'Jerry', 'Bicyclette à éléphant');
INSERT INTO UTILISATION VALUES('Les Zozos', 'Jerry', 'Peigne de chimpanzé');
INSERT INTO UTILISATION VALUES('Les Tartarins', 'Grostas', 'Bicyclette à éléphant');
INSERT INTO UTILISATION VALUES('Le coche infernal', 'Sangtrèspur', 'Etrier');

-- #### projection
-- #1
SELECT nature 
FROM NUMERO;

-- #2
SELECT distinct nature 
FROM NUMERO;

-- #3
select camion,volume 
from ACCESSOIRE
order by camion,volume desc;

-- ### restriction
-- #1
select * from ACCESSOIRE
where volume >= 0.3 or couleur = 'rouge';

-- #2
select * from ACCESSOIRE
where volume between 0.3 and 0.6;

-- #3
select * from ACCESSOIRE where ratelier = camion; -- /ACCESSOIRE.ratelier = ACCESSOIRE.camion;

-- ### mis a jour
-- #1
alter table UTILISATION 
drop CONSTRAINT utilisation_fk3 ;

alter table UTILISATION 
add CONSTRAINT utilisation_fk3 FOREIGN KEY(accessoire) REFERENCES ACCESSOIRE(nom) on update CASCADE;

update ACCESSOIRE 
set nom = 'Trapèze pour lion'
where nom = 'Chaise longue de lion';

/*  -- du prof de cour 
insert into accessoire values('Trapèze pour lion', 'Bleu', 0.9, 11, 5); 
update utilisation set accessoire='Trapèze pour lion' where accessoire='Chaise longue de lion'; 
delete from accessoire where nom='Chaise longue de lion';
*//* puisque nom*/

-- #2
update ACCESSOIRE
set volume = volume + 10
where nom = 'Cage à lions';

-- #3
update ACCESSOIRE
set nom = 'balle'
where nom = 'Ballon'
   and volume % 2 = 0
   and ratelier = 7
   and camion = 8;

-- #4
alter table NUMERO
drop constraint numero_fk;

alter table NUMERO 
add CONSTRAINT numero_fk FOREIGN KEY (responsable) REFERENCES PERSONNEL(nom) on delete cascade;

alter table UTILISATION 
drop CONSTRAINT utilisation_fk1,
drop CONSTRAINT utilisation_fk2;

alter table UTILISATION
add CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre) on delete cascade,
add CONSTRAINT utilisation_fk2 FOREIGN KEY(utilisateur) REFERENCES PERSONNEL(nom) on delete cascade;

delete from PERSONNEL
where nom = 'Crinière ';

-- #5

alter table UTILISATION 
drop CONSTRAINT utilisation_fk1,

alter table UTILISATION
add CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre) on delete cascade,

-- #6
commit; -- validation des mis a jour // affectation de update or alter or delete...
delete from NUMERO
where titre = 'Les Smilers'

-- #7
rollback; -- return anuler last operation but not change any result in mysql
INSERT INTO NUMERO VALUES('Les Smilers', 'Equilibre', 'Attention'); -- i use this

-- ### jointures
-- #1
select distinct u.accessoire
from UTILISATION u,PERSONNEL p
where u.utilisateur = p.nom and p.role = 'jongleur';

-- #2
select distinct  u1.accessoire 
from UTILISATION u1,UTILISATION u2
where u1.accessoire=u2.accessoire and u1.titre <> u2.titre;

-- #3
select distinct  a.camion
from UTILISATION u,PERSONNEL p,ACCESSOIRE a
where a.nom=u.accessoire and u.utilisateur = p.nom and p.role = 'jongleur';

-- #4
insert into ACCESSOIRE values('Trash', 'Blue', 99, 1, 1);
select *
from ACCESSOIRE 
where nom not in (select accessoire from UTILISATION);

-- ###agregation
-- #1
select count(*)
from NUMERO;

-- #2
select count(distinct titre)
from UTILISATION
where accessoire in ('Ballon','Ball');

-- #3 
select sum(a.volume) as vt,avg(a.volume) as vm
from ACCESSOIRE a;

-- #4  is question 2 of jointure;
   --$
      select nom
      from ACCESSOIRE
      where (select count(distinct titre)
         from UTILISATION
         where accessoire=nom) > 1;
   --$
      select accessoire
      from UTILISATION
      group by accessoire
      having count(distinct titre) > 1;
   --$   
      select distinct u.accessoire
      from UTILISATOIN u1,UTILISATION u2
      where u.accessoire = a.accessoire and u1.titre<>u2.titre;

-- #5 operations ensemblistes
-- #1
select nom
from ACCESSOIRE a
where nom not in(select accessoire
                  from UTILISATION
               );
/* -- for oracle , prof cour.
      select nom from ACCESSOIRE 
      minus
      select distinct accessoire from UTILISATION;    */
-- #2
select utilisateur
from UTILISATION 
where accessoire='Boule'
union
select nom 
from PERSONNEL
where role='jongleur';

-- #3 -- replace balle with Ballon
   select utilisateur from UTILISATION where accessoire='Ballon'
   and in (select nom from PERSONNEL where role='jongleur'); 
    -- or
   select nom from PERSONNEL where role='jongleur'
   and in (select utilisateur from UTILISATION where accessoire='Ballon'); 
      
select distinct utilisateur -- machi sure 
from UTILISATION,PERSONNEL
where accessoire='Ballon'
and PERSONNEL.role='jongleur';

/* -- for oracle , prof cour.
select nom from PERSONNEL where role='jongleur'
intersect
select utilisateur from UTILISATION where accessoire='balle';
*/

-- #4
select nom from PERSONNEL where role='jongleur'
and not in (select utilisateur from UTILISATION where accessoire='Balle'); 

/* -- for oracle , prof cour.
select nom from PERSONNEL where role='jongleur'
minus
select utilisateur from UTILISATION where accessoire='balle';
*/



