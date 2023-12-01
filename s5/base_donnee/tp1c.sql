DROP DATABASE IF EXISTS TP1;
CREATE DATABASE TP1;
USE TP1;

DROP TABLE IF EXISTS VOL;
DROP TABLE IF EXISTS PILOTE;
DROP TABLE IF EXISTS AVION;

-- I. Création d’une base de données 
-- 1)
DROP TABLE IF EXISTS PILOTE;
CREATE TABLE PILOTE (
	-- plnum NUMBER(2),
	plnum DECIMAL(2),
	plnom VARCHAR(30),
	plprenom VARCHAR(30),
	ville VARCHAR(30),
	-- salaire NUMBER(8,2)
	salaire DECIMAL(8,2)
);

DROP TABLE IF EXISTS AVION;
CREATE TABLE AVION (
	-- avnum NUMBER(2),
	avnum DECIMAL(2),
	avnom VARCHAR(30),
	-- capacite NUMBER(3),
	capacite DECIMAL(3),
	localisation VARCHAR(30)
);

-- 2)

ALTER TABLE PILOTE
ADD CONSTRAINT pilote_cle_pri PRIMARY KEY(plnum);
ALTER TABLE AVION
ADD CONSTRAINT avion_cle_pri PRIMARY KEY(avnum);

INSERT INTO PILOTE VALUES (1, 'Zighed', 'Djamel', 'Paris', 21000);
INSERT INTO PILOTE VALUES (2, 'Boussaid', 'Omar', 'Toulouse', 21000);
INSERT INTO PILOTE VALUES (3, 'Viallaneix', 'Jacques', 'Nice', 18000);
INSERT INTO PILOTE VALUES (4, 'Nicolloyannis', 'Nicolas', 'Paris', 17000);
INSERT INTO PILOTE VALUES (5, 'Darmont', 'Jerome', 'Toulouse', 19000);
INSERT INTO PILOTE VALUES (6, 'Lallich', 'Stephane', 'Paris', 18000);
INSERT INTO PILOTE VALUES (7, 'Rakotomalala', 'Ricco', 'Nice', 17000);
INSERT INTO PILOTE VALUES (8, 'Chauchat', 'Jean-Hughes', 'Lyon', 15000);
INSERT INTO PILOTE VALUES (9, 'Muhboubi', 'Hadj', 'Nice', 18000);
INSERT INTO PILOTE VALUES (10, 'Bentayeb', 'Fadila', 'Paris', 20000);

INSERT INTO AVION VALUES(1, 'A300', 300, 'Nice');
INSERT INTO AVION VALUES(2, 'A310', 300, 'Nice');
INSERT INTO AVION VALUES(3, 'B707', 250, 'Paris');
INSERT INTO AVION VALUES(4, 'A300', 280, 'Lyon');
INSERT INTO AVION VALUES(5, 'Concorde', 160, 'Nice');
INSERT INTO AVION VALUES(6, 'B747', 460, 'Paris');
INSERT INTO AVION VALUES(7, 'B707', 250, 'Paris');
INSERT INTO AVION VALUES(8, 'A310', 300, 'Toulouse');
INSERT INTO AVION VALUES(9, 'Mercure', 180, 'Lyon');
INSERT INTO AVION VALUES(10, 'Concorde', 160, 'Paris');

-- 3)
DROP TABLE IF EXISTS VOL;
CREATE TABLE VOL (
	-- volnum NUMBER(2),
	volnum DECIMAL(2),
	-- plnum NUMBER(2),
	plnum DECIMAL(2), 
	-- avnum NUMBER(2),
	avnum DECIMAL(2), 
	villedep VARCHAR(30), 
	villearr VARCHAR(30), 
	-- heuredep NUMBER(10),
	heuredep DECIMAL(10), 
	-- heurearr NUMBER(10)
	heurearr DECIMAL(10)
);

-- 4)
ALTER TABLE VOL
ADD (
CONSTRAINT vol_pk PRIMARY KEY(volnum),
CONSTRAINT vol_fk1 FOREIGN KEY(plnum) REFERENCES PILOTE(plnum) ON DELETE CASCADE,
CONSTRAINT vol_fk2 FOREIGN KEY(avnum) REFERENCES AVION(avnum) ON DELETE CASCADE
);

INSERT INTO VOL VALUES  (1, 1, 1, 'Nice', 'Toulouse', 11, 12);
INSERT INTO VOL VALUES  (2, 1, 8, 'Paris', 'Toulouse', 17, 18);
INSERT INTO VOL VALUES  (3, 2, 1, 'Toulouse', 'Lyon', 14, 16);
INSERT INTO VOL VALUES  (4, 5, 3, 'Toulouse', 'Lyon', 18, 20);
INSERT INTO VOL VALUES  (5, 9, 1, 'Paris', 'Nice', 6, 8);
INSERT INTO VOL VALUES  (6, 10, 2, 'Lyon', 'Nice', 11, 12);
INSERT INTO VOL VALUES  (7, 1, 4, 'Paris', 'Lyon', 8, 9);
INSERT INTO VOL VALUES  (8, 8, 4, 'Nice', 'Paris', 7, 8);
INSERT INTO VOL VALUES  (9, 1, 8, 'Nantes', 'Lyon', 9, 15);
INSERT INTO VOL VALUES  (10, 8, 2, 'Nice', 'Paris', 12, 13);
INSERT INTO VOL VALUES  (11, 9, 2, 'Paris', 'Lyon', 15, 16);
INSERT INTO VOL VALUES  (12, 1, 2, 'Lyon', 'Nantes', 16, 20);
INSERT INTO VOL VALUES  (13, 4, 5, 'Nice', 'Lens', 11, 14);
INSERT INTO VOL VALUES  (14, 3, 5, 'Lens', 'Paris', 15, 16);
INSERT INTO VOL VALUES  (15, 8, 9, 'Paris', 'Toulouse', 17, 18);
INSERT INTO VOL VALUES  (16, 7, 5, 'Paris', 'Toulouse', 18, 19);

-- II. Mise à jour de la base de données
-- 1)
INSERT INTO VOL VALUES (17, 5, 8, 'Bordeaux', 'Clermont-Fd', 12 , 13),
						(18, 10, 7, 'Paris', 'Lille', 11, 12);
-- 2)
UPDATE VOL
SET VILLEDEP = 'Lille', HEUREARR = 17
WHERE VOLNUM = 14;

-- 3)
DELETE FROM VOL
WHERE VOLNUM = 17;

-- III. Interrogation de la base de données 
-- 1) Noms des pilotes.
SELECT PLNOM
FROM PILOTE;

-- 2) Noms des pilotes triés par ordre alphabétique.
SELECT PLNOM
FROM PILOTE
ORDER BY PLNOM;

-- 3) Noms des pilotes triés par salaire décroissant et par ordre alphabétique.
SELECT PLNOM
FROM PILOTE
ORDER BY SALAIRE DESC, PLNOM;

-- 4) Salaire moyen des pilotes.
SELECT AVG(SALAIRE)
FROM PILOTE;

-- 5) Salaire moyen par ville. 
SELECT ville, AVG(SALAIRE)
FROM PILOTE
GROUP BY ville;

-- 6) Noms des avions, triés par ordre alphabétique et sans doublon.
SELECT DISTINCT avnom
FROM AVION
ORDER BY avnom;

-- 7) Nombre d’avions localisés à Paris.
SELECT COUNT(*)
FROM AVION
WHERE localisation = 'Paris';

-- 8) Nombre d’avions différents localisés à Paris. 
SELECT COUNT(*)
FROM AVION
WHERE localisation != 'Paris';

-- 9) Maximum des salaires moyens par ville.
SELECT MAX(averege)
FROM (
	SELECT ville, AVG(SALAIRE) AS averege
	FROM PILOTE
	GROUP BY ville
) sup;

-- 10) Ville dont le salaire moyen est le plus élevé.
SELECT ville, AVG(SALAIRE) AS averege
FROM PILOTE
GROUP BY ville
ORDER BY averege DESC
LIMIT 1;
