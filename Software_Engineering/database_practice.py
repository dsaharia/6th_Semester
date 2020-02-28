import sqlite3


# Queries - 
# CREATE TABLE Genetic_Sequence (sl_number INTEGER PRIMARY KEY,gene_information TEXT NOT NULL, codon_sequence TEXT NOT NULL, amino_acid_sequence)
connection = sqlite3.connect('dev.db')
cursor = connection.cursor()
# cursor.execute('CREATE TABLE Genetic_Sequence (sl_number INTEGER PRIMARY KEY,gene_information TEXT NOT NULL);')
cursor.execute("INSERT INTO Genetic_Sequence VALUES (1,'>Ecol_K12_MG1655:|1|thrL')")
connection.commit()
connection.close()