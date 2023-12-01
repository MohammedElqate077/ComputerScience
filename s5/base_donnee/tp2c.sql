DROP DATABASE IF EXISTS TP2_CIRQUE;
CREATE DATABASE IF NOT EXISTS TP2_CIRQUE;
USE TP2_CIRQUE;

DROP TABLE IF EXISTS UTILISATION;
DROP TABLE IF EXISTS ACCESSOIRE;
DROP TABLE IF EXISTS NUMERO;
DROP TABLE IF EXISTS PERSONNEL;

-- 1) Créer la structure des quatre tables de la base en intégrant les contraintes d’intégrité nécessaires (clés primaires, clés étrangères).
CREATE TABLE PERSONNEL (
	nom VARCHAR(20),
	role VARCHAR(20),
    CONSTRAINT personnel_pk PRIMARY KEY(nom)
);

CREATE TABLE NUMERO (
	titre VARCHAR(30),
	nature VARCHAR(20),
	responsable VARCHAR(20),
	CONSTRAINT numero_pk PRIMARY KEY(titre),
	CONSTRAINT numero_fk FOREIGN KEY(responsable) REFERENCES PERSONNEL(nom)
);

CREATE TABLE ACCESSOIRE (
	nom VARCHAR(30), 
	couleur VARCHAR(10), 
	volume DECIMAL(5,1), 
	ratelier DECIMAL(2), 
	camion DECIMAL(1),
	CONSTRAINT accessoire_pk PRIMARY KEY(nom)
);

CREATE TABLE UTILISATION (
	titre VARCHAR(30), 
	utilisateur VARCHAR(20),
	accessoire VARCHAR(30),
	CONSTRAINT utilisation_pk PRIMARY KEY(titre, utilisateur, accessoire),
	CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre),
	CONSTRAINT utilisation_fk2 FOREIGN KEY(utilisateur) REFERENCES PERSONNEL(nom),
	CONSTRAINT utilisation_fk3 FOREIGN KEY(accessoire) REFERENCES ACCESSOIRE(nom)
);

-- 2) Remplir les tables  
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

-- Projections
	-- • Nature de tous les numéros sans suppression des doubles.. 
		SELECT nature FROM NUMERO;

	-- • Nature de tous les numéros avec suppression des doubles. 
		SELECT DISTINCT nature
        FROM NUMERO;

	-- • Camions et volumes des accessoires, par ordre croissant des camions et, pour chaque camion, par ordre décroissant des volumes. 
		SELECT camion, volume
        FROM ACCESSOIRE
		ORDER BY camion, volume DESC;

-- Restrictions 
	-- • Accessoires de volume supérieur ou égal à 0,3 ou de couleur rouge. 
		SELECT *
        FROM ACCESSOIRE
		WHERE volume >= 0.3 OR couleur = 'Rouge';

	-- • Accessoires de volume compris entre 0,3 et 0,6.
		SELECT * FROM ACCESSOIRE
		WHERE volume BETWEEN 0.3 AND 0.6;

	-- • Accessoires rangés dans un râtelier dont le numéro est égal à son numéro de camion. 
		SELECT * FROM ACCESSOIRE
		WHERE ratelier = camion;

-- Mises A jour
	-- • Dans la table ACCESSOIRE, substitution d’un trapèze pour lion à la chaise longue de lion.
		ALTER TABLE UTILISATION
        DROP CONSTRAINT utilisation_fk3;
        
		ALTER TABLE UTILISATION
        ADD CONSTRAINT utilisation_fk3 FOREIGN KEY(accessoire) REFERENCES ACCESSOIRE(nom) ON UPDATE CASCADE;

        UPDATE ACCESSOIRE
        SET nom = 'Trapèze pour lion'
        WHERE nom = 'Chaise longue de lion';
        
        -- ALTER
        INSERT INTO ACCESSOIRE VALUES('Trapèze pour lion', 'Bleu', 0.9, 11, 5); 
        
		UPDATE UTILISATION
        SET accessoire = 'Trapèze pour lion' 
		WHERE accessoire = 'Chaise longue de lion';
        
		DELETE FROM ACCESSOIRE 
        WHERE nom = 'Chaise longue de lion';

	-- • Ajouter 10 au volume de la cage à lions.
		UPDATE ACCESSOIRE
		SET volume = volume + 10
		WHERE nom = 'Cage à lions';

	-- • Remplacer les ballons par des balles de volume divisé par deux et qui seront rangées dans le râtelier n° 7 du camion n° 8.
		UPDATE ACCESSOIRE
		SET nom = 'balle'
		WHERE nom = 'Ballon'
			AND volume % 2 = 0
			AND ratelier = 7
			AND camion = 8;
    
	-- • Supprimer Crinière, qui démissionne du cirque.
		ALTER TABLE NUMERO
        DROP CONSTRAINT numero_fk;
		ALTER TABLE NUMERO
        ADD CONSTRAINT numero_fk FOREIGN KEY(responsable) REFERENCES PERSONNEL(nom) ON DELETE CASCADE;
        
		ALTER TABLE UTILISATION
        DROP CONSTRAINT utilisation_fk1, 
        DROP CONSTRAINT utilisation_fk2;
		ALTER TABLE UTILISATION
        ADD CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre) ON DELETE CASCADE,
        ADD CONSTRAINT utilisation_fk2 FOREIGN KEY(utilisateur) REFERENCES PERSONNEL(nom) ON DELETE CASCADE;
        
		DELETE FROM PERSONNEL
        WHERE nom = 'Crinière';

	-- • Dans la table UTILISATION, détruire la contrainte de clé étrangère sur le TITRE, puis la recréer en lui ajoutant à la fin la clause ON DELETE CASCADE.
		ALTER TABLE UTILISATION
        DROP CONSTRAINT utilisation_fk1;
		ALTER TABLE UTILISATION
        ADD CONSTRAINT utilisation_fk1 FOREIGN KEY(titre) REFERENCES NUMERO(titre) ON DELETE CASCADE;

	-- • Valider les mises à jour précédentes, puis effacer le numéro « Les Smilers » dans la table NUMERO. Résultat dans NUMERO et UTILISATION ?
		DELETE FROM NUMERO
        WHERE titre = 'Les Smilers';
        
	-- • Annuler la suppression précédente.
		INSERT INTO NUMERO VALUES('Les Smilers', 'Equilibre', 'Attention');
        
-- Jointures 
	-- • Accessoires servant aux jongleurs.###############
 	-- • Accessoires servant dans plusieurs numéros.
		SELECT a.nom
        FROM UTILISATION u
        JOIN NUMERO n
        ON n.titre = u.titre
		JOIN ACCESSOIRE a
        ON a.nom = u.accessoire
        GROUP BY a.nom
        HAVING COUNT(*) >= 2;

	-- • Camions contenant les accessoires servant aux jongleurs.###############
	-- • Liste des accessoires non-utilisés. Insérer un nouvel accessoire quelconque dans la table ACCESSOIRE pour tester la requête.
		SELECT *
        FROM ACCESSOIRE
        WHERE nom NOT IN (
			SELECT accessoire
            FROM UTILISATION
        );
        INSERT INTO ACCESSOIRE VALUES('OnePiece', 'Blue', 9999, 1, 1);

-- Agrégats et groupements 
	-- • Nombre de numéros.
		SELECT COUNT(*) AS 'Nombre de numéros'
        FROM NUMERO;
        
	-- • Nombre de numéros utilisant une balle ou un ballon.
		SELECT COUNT(*) AS 'Nombre denuméros utilisant une balle ou un ballon'
        FROM UTILISATION
        JOIN NUMERO
        ON NUMERO.titre = UTILISATION.titre
        WHERE UTILISATION.accessoire IN ('balle', 'ballon');
        
	-- • Volume total et volume moyen des accessoires.
		SELECT a.nom, SUM(a.volume), AVG(a.volume)
        FROM UTILISATION u
        JOIN ACCESSOIRE a
        on a.nom = u.accessoire
        GROUP BY a.nom;
        -- or
		SELECT
			SUM(volume) AS 'Volume total', 
            AVG(volume) 'Volume moyen'
        FROM ACCESSOIRE;
        
	-- • Accessoires servant dans plusieurs numéros.
		SELECT a.nom AS 'Accessoires servant dans plusieurs numéros'
        FROM UTILISATION u
        JOIN NUMERO n
        ON n.titre = u.titre
        JOIN ACCESSOIRE a
        ON a.nom = u.accessoire
        GROUP BY a.nom
        HAVING COUNT(*) >= 2;
 
-- Opérations ensemblistes
	-- • Liste des accessoires non-utilisés.
		SELECT *
        FROM ACCESSOIRE
        WHERE nom NOT IN (
			SELECT accessoire
            FROM UTILISATION
        );
        
	-- • Liste des jongleurs et des utilisateurs de boule.###############
	-- • Liste des jongleurs qui utilisent une balle.###############
	-- • Liste des jongleurs qui n’utilisent pas de balle.###############
 
-- Division 
	-- • Liste des accessoires utilisés dans tous les numéros. Insérer suffisamment de n-uplets dans la table UTILISATION pour tester la requête et proposer deux solutions différentes. 
		-- solution 1
        SELECT DISTINCT a.nom
		FROM UTILISATION u
        JOIN NUMERO n
        ON n.titre = u.titre
        JOIN ACCESSOIRE a
        ON a.nom = u.accessoire;
		-- solution 2
		SELECT a.nom
        FROM ACCESSOIRE a
        WHERE a.nom IN (
			SELECT accessoire
            FROM UTILISATION
		);