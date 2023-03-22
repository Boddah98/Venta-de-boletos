CREATE DATABASE dbBoleteria;
use dbBoleteria;

CREATE TABLE Sitios(
	NombreSitio VARCHAR (50) PRIMARY KEY,
    Ubicacion VARCHAR (50),
    SitioWeb VARCHAR (50)
);

CREATE TABLE Sectores(
	IdSector INT AUTO_INCREMENT PRIMARY KEY,
	NombreSitio VARCHAR (50), 
    MontoSector INT,
    NombreSector VARCHAR(10),
    FOREIGN KEY (NombreSitio) REFERENCES Sitios (NombreSitio)
);
CREATE TABLE Eventos(
	IdEvento INT AUTO_INCREMENT PRIMARY KEY,
    NombreEvento VARCHAR (50),
    NombreSitio VARCHAR (50), 
    FechaInicio DATE,
    Productora VARCHAR (30),
    FOREIGN KEY (NombreSitio) REFERENCES Sitios (NombreSitio)    
);

CREATE TABLE Asientos(
	IdAsiento INT AUTO_INCREMENT PRIMARY KEY,
    IdSector INT,
    Numeracion VARCHAR(10),
    Estado VARCHAR (10),
    FOREIGN KEY (IdSector) REFERENCES Sectores (IdSector)
);

CREATE TABLE Boletos(
	IdBoleto INT AUTO_INCREMENT PRIMARY KEY,
    IdAsiento INT, 
    Monto INT,
    FOREIGN KEY (IdAsiento) REFERENCES Asientos (IdAsiento)
);
CREATE TABLE Facturas(
	IdFactura INT AUTO_INCREMENT PRIMARY KEY,
    FechaCompra DATE,
    NombreComprador VARCHAR (30), 
    CedulaComprador INT,
    IdEvento INT, 
    Subtotal INT,
    CostoServicio INT,
    Total INT,
    FOREIGN KEY (IdEvento) REFERENCES Eventos (IdEvento)
);
CREATE TABLE FacturasXbBoletos(
	IdFacturaXBoleto INT AUTO_INCREMENT PRIMARY KEY,
    IdBoleto INT,
    IdFactura INT,
    FOREIGN KEY (IdBoleto) REFERENCES Boletos (IdBoleto),
    FOREIGN KEY (IdFactura) REFERENCES Facturas (IdFactura)
);


use dbBoleteria



use dbBoleteria
-- Este procedure crea el sector y asigna la cantidad de asientos según la cantidad ingresada, además de que genera 
-- la numeración por cada asiento  
DELIMITER //
CREATE PROCEDURE CrearSector (
    IN pNombreSitio VARCHAR(50), 
    IN pNombreSector VARCHAR(10), 
    IN pCantidadEspacios INT, 
    IN pMontoSector INT, 
    IN pInicial CHAR(1)
)

BEGIN
	DECLARE Contador INT;
    DECLARE IdSectorAgregado INT;    
    
    INSERT INTO Sectores(NombreSitio, MontoSector, NombreSector)
    VALUES (pNombreSitio, pMontoSector, pNombreSector);
    
    SET IdSectorAgregado = LAST_INSERT_ID();
    SET Contador = 1;
    
    WHILE Contador <= pCantidadEspacios DO
    
		SET @Numeracion = CAST(Contador AS CHAR);
        SET @NumeracionAsiento = CONCAT( pInicial, @Numeracion);
        
		INSERT INTO Asientos(IdSector, Numeracion, Estado)
        VALUES(IdSectorAgregado, @NumeracionAsiento,"Disponible");
		 
		SET Contador = Contador + 1;
    END WHILE;

    
END; //

DELIMITER ;



select * from Asientos where Asientos.idSector == 1

insert into Sitios(NombreSitio, Ubicacion,SitioWeb) values("El Mirador","Guápiles","ElMirador.com");

CALL CrearSector("El Mirador", "VIP1", 25, 5000, "A");
