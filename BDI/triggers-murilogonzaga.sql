-- 
-- Murilo Tomaz Gonzaga
-- RA: 241024684
-- Banco de Dados I
-- Exercícios Triggers
--
CREATE TABLE autor (
    cpf       CHAR(11)     PRIMARY KEY,
    nome      VARCHAR(100) NOT NULL,
    sexo      CHAR(1)      CHECK (sexo IN ('M', 'F')),
    data_nasc DATE
);

CREATE TABLE livro (
    isbn       CHAR(13)     PRIMARY KEY,
    titulo     VARCHAR(200) NOT NULL,
    editora    VARCHAR(30)  NOT NULL,
    ano_edicao SMALLINT
);

CREATE TABLE escreve (
    cpf  CHAR(11) REFERENCES autor(cpf),
    isbn CHAR(13) REFERENCES livro(isbn),
    PRIMARY KEY (cpf, isbn)
);

CREATE TABLE livraria (
    cnpj     CHAR(14)     PRIMARY KEY,
    nome     VARCHAR(100) NOT NULL,
    endereco VARCHAR(200) NOT NULL,
    cidade   VARCHAR(50)  NOT NULL
);

CREATE TABLE vende (
    cnpj CHAR(14) REFERENCES livraria(cnpj),
    isbn CHAR(13) REFERENCES livro(isbn),
    preco NUMERIC(10,2) NOT NULL,
    PRIMARY KEY (cnpj, isbn)
);

CREATE TABLE leitor (
    rg        CHAR(9)      PRIMARY KEY,
    nome      VARCHAR(100) NOT NULL,
    endereco  VARCHAR(200) NOT NULL,
    sexo      CHAR(1)      CHECK (sexo IN ('M', 'F')),
    data_nasc DATE
);

CREATE TABLE le (
    rg   CHAR(9)  REFERENCES leitor(rg),
    isbn CHAR(13) REFERENCES livro(isbn),
    PRIMARY KEY (rg, isbn)
);

CREATE TABLE compra (
    rg   CHAR(9)  REFERENCES leitor(rg),
    cnpj CHAR(14),
    isbn CHAR(13),
    FOREIGN KEY (cnpj, isbn) REFERENCES vende(cnpj, isbn),
    PRIMARY KEY (rg, cnpj, isbn)
);

-- 1b

-- AUTOR
INSERT INTO autor VALUES ('12345678901', 'Aristotle',     'M', '0384-03-22');
INSERT INTO autor VALUES ('23456789012', 'Plato',         'M', '0428-05-01');
INSERT INTO autor VALUES ('34567890123', 'Immanuel Kant', 'M', '1724-04-22');
INSERT INTO autor VALUES ('45678901234', 'Martin Heidegger', 'M', '1889-09-26');
INSERT INTO autor VALUES ('56789012345', 'Georg Hegel',      'M', '1770-08-27');

-- LIVRO
INSERT INTO livro VALUES ('9780140449334', 'Nicomachean Ethics',        'Penguin Classics', 1998);
INSERT INTO livro VALUES ('9780872202351', 'The Republic',               'Hackett',          1992);
INSERT INTO livro VALUES ('9780521657297', 'Critique of Pure Reason',    'Cambridge',        1998);
INSERT INTO livro VALUES ('9780679724650', 'Being and Time',             'Harper Perennial', 1962);
INSERT INTO livro VALUES ('9780521297127', 'Phenomenology of Spirit',    'Cambridge',        1977);

-- ESCREVE
INSERT INTO escreve VALUES ('12345678901', '9780140449334');
INSERT INTO escreve VALUES ('23456789012', '9780872202351');
INSERT INTO escreve VALUES ('34567890123', '9780521657297');
INSERT INTO escreve VALUES ('45678901234', '9780679724650');
INSERT INTO escreve VALUES ('56789012345', '9780521297127');

-- LIVRARIA
INSERT INTO livraria VALUES ('00111222000101', 'Bauru Book Store',   'Rua Batista de Carvalho, 100', 'Bauru');
INSERT INTO livraria VALUES ('00222333000102', 'Philosophy House',   'Av. Nações Unidas, 200',       'São Paulo');
INSERT INTO livraria VALUES ('00333444000103', 'Great Books SP',     'Rua da Consolação, 300',       'São Paulo');
INSERT INTO livraria VALUES ('00444555000104', 'Classic Reads',      'Av. Beira Mar, 400',           'Rio de Janeiro');
INSERT INTO livraria VALUES ('00555666000105', 'The Reading Corner', 'Rua XV de Novembro, 500',      'Curitiba');

-- VENDE
INSERT INTO vende VALUES ('00111222000101', '9780140449334', 89.90);
INSERT INTO vende VALUES ('00222333000102', '9780872202351', 75.50);
INSERT INTO vende VALUES ('00333444000103', '9780521657297', 120.00);
INSERT INTO vende VALUES ('00444555000104', '9780679724650', 95.00);
INSERT INTO vende VALUES ('00555666000105', '9780521297127', 110.00);

-- LEITOR
INSERT INTO leitor VALUES ('123456789', 'Carlos Souza',   'Rua das Flores, 10',    'M', '1995-03-15');
INSERT INTO leitor VALUES ('234567890', 'Ana Lima',       'Av. Brasil, 200',        'F', '1990-07-22');
INSERT INTO leitor VALUES ('345678901', 'Pedro Martins',  'Rua do Comércio, 30',   'M', '1988-11-05');
INSERT INTO leitor VALUES ('456789012', 'Julia Ferreira', 'Rua das Palmeiras, 40', 'F', '2000-01-30');
INSERT INTO leitor VALUES ('567890123', 'Lucas Oliveira', 'Av. Paulista, 500',     'M', '1997-06-18');

-- LE
INSERT INTO le VALUES ('123456789', '9780140449334');
INSERT INTO le VALUES ('234567890', '9780872202351');
INSERT INTO le VALUES ('345678901', '9780521657297');
INSERT INTO le VALUES ('456789012', '9780679724650');
INSERT INTO le VALUES ('567890123', '9780521297127');

-- COMPRA
INSERT INTO compra VALUES ('123456789', '00111222000101', '9780140449334');
INSERT INTO compra VALUES ('234567890', '00222333000102', '9780872202351');
INSERT INTO compra VALUES ('345678901', '00333444000103', '9780521657297');
INSERT INTO compra VALUES ('456789012', '00444555000104', '9780679724650');
INSERT INTO compra VALUES ('567890123', '00555666000105', '9780521297127');

-- 1c

SELECT
    leitor.nome   AS leitor,
    livraria.nome AS livraria,
    livro.titulo  AS livro
FROM compra
JOIN leitor   ON compra.rg   = leitor.rg
JOIN vende    ON compra.cnpj = vende.cnpj AND compra.isbn = vende.isbn
JOIN livraria ON vende.cnpj  = livraria.cnpj
JOIN livro    ON vende.isbn  = livro.isbn
WHERE vende.preco > 50.00;

SELECT DISTINCT leitor.nome
FROM leitor
JOIN le    ON leitor.rg  = le.rg
JOIN livro ON le.isbn    = livro.isbn
WHERE (
    SELECT AVG(preco)
    FROM vende
    WHERE vende.isbn = livro.isbn
) > (
    SELECT AVG(preco)
    FROM vende
);

SELECT leitor.nome
FROM leitor
WHERE NOT EXISTS (
    SELECT isbn
    FROM escreve
    JOIN autor ON escreve.cpf = autor.cpf
    WHERE autor.nome = 'Jorge Amado'
    AND isbn NOT IN (
        SELECT isbn
        FROM le
        WHERE le.rg = leitor.rg
    )
);

-- 2
ALTER TABLE leitor
ADD COLUMN nlivroslidos INTEGER DEFAULT 0;

-- 3
UPDATE leitor
SET nlivroslidos = (
    SELECT COUNT(*)
    FROM le
    WHERE le.rg = leitor.rg
);

-- 4

CREATE FUNCTION update_nlivroslidos()
RETURNS TRIGGER AS $$
BEGIN
	IF TG_OP = 'INSERT' THEN
		UPDATE leitor
		SET nlivroslidos = nlivroslidos + 1
		WHERE rg = NEW.rg;
		RETURN NEW;

	ELSIF TG_OP = 'DELETE' THEN
		UPDATE leitor
		SET nlivroslidos = GREATEST(nlivroslidos - 1, 0)
		WHERE rg = OLD.rg;
		RETURN OLD;
	
	ELSIF TG_OP = 'UPDATE' THEN
        UPDATE leitor
        SET nlivroslidos = nlivroslidos - 1
        WHERE rg = OLD.rg;
        UPDATE leitor
        SET nlivroslidos = nlivroslidos + 1
        WHERE rg = NEW.rg;
        RETURN NEW;
    END IF;
END;
$$ LANGUAGE plpgsql;

-- criando TRIGGER

CREATE TRIGGER trigger_nlivroslidos
AFTER INSERT OR DELETE OR UPDATE ON le
FOR EACH ROW
EXECUTE FUNCTION update_nlivroslidos();

-- 5
INSERT INTO le VALUES ('234567890', '9780140449334');
SELECT rg, nome, nlivroslidos FROM leitor WHERE rg = '234567890'; 

DELETE FROM le WHERE rg = '234567890' AND isbn = '9780140449334';
SELECT rg, nome, nlivroslidos FROM leitor WHERE rg = '234567890'; 

UPDATE le SET rg = '345678901' WHERE rg = '123456789' AND isbn = '9780140449334';
SELECT rg, nome, nlivroslidos FROM leitor WHERE rg IN ('123456789', '345678901'); 

-- 7.
-- Os valores foram atualizados corretamente em todos os testes realizados.
-- A única inconsistência possível seria o atributo nlivroslidos ficar negativo
-- caso um registro fosse deletado da tabela le quando seu valor já fosse 0.
-- Para evitar isso, utilizamos GREATEST(nlivroslidos - 1, 0) na função do trigger,
-- garantindo que o atributo nunca assuma valores negativos.