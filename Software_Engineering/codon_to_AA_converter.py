import sqlite3
from gene_plotting import AA_histogram

combined_aa_string = ""
code_table = { 
        'ATA':'I', 'ATC':'I', 'ATT':'I', 'ATG':'M', 
        'ACA':'T', 'ACC':'T', 'ACG':'T', 'ACT':'T', 
        'AAC':'N', 'AAT':'N', 'AAA':'K', 'AAG':'K', 
        'AGC':'S', 'AGT':'S', 'AGA':'R', 'AGG':'R', 
        'CTA':'L', 'CTC':'L', 'CTG':'L', 'CTT':'L', 
        'CCA':'P', 'CCC':'P', 'CCG':'P', 'CCT':'P', 
        'CAC':'H', 'CAT':'H', 'CAA':'Q', 'CAG':'Q', 
        'CGA':'R', 'CGC':'R', 'CGG':'R', 'CGT':'R', 
        'GTA':'V', 'GTC':'V', 'GTG':'V', 'GTT':'V', 
        'GCA':'A', 'GCC':'A', 'GCG':'A', 'GCT':'A', 
        'GAC':'D', 'GAT':'D', 'GAA':'E', 'GAG':'E', 
        'GGA':'G', 'GGC':'G', 'GGG':'G', 'GGT':'G', 
        'TCA':'S', 'TCC':'S', 'TCG':'S', 'TCT':'S', 
        'TTC':'F', 'TTT':'F', 'TTA':'L', 'TTG':'L', 
        'TAC':'Y', 'TAT':'Y', 'TAA':'*', 'TAG':'*', 
        'TGC':'C', 'TGT':'C', 'TGA':'*', 'TGG':'W', 
    }

AA_seq = []
codon_seq = []
start_seq = 0
sl_number = 0
#stop = 0

def write_db(gene_information, codon_string='X', amino_string='X', codon_len=0, count_A=0, count_T=0, count_G=0, count_C=0):
    connection = sqlite3.connect('gene_info.db')
    cursor = connection.cursor()
    cursor.execute("INSERT INTO Gene_Information (gene_information, codon_sequence, amino_acid_sequence, seq_length, count_a, count_t, count_g, count_c, remarks) VALUES (?,?,?,?,?,?,?,?,?)", (gene_information, codon_string, amino_string, codon_len, count_A, count_T, count_G, count_C, 'Success'))
    connection.commit()
    connection.close()


def parse(line, gene_information):
    stop_bit = 0
    line = line.strip()
    protein = ""
    for i in range(0, len(line), 3):
        protein += line[i:i+3]
        protein = protein.upper()
        codon_seq.append(protein)
        acid = code_table.get(protein)
        global start_seq

        if acid == '*':
            AA_seq.append('*')
            stop_bit = 1
        else:
            if stop_bit == 1:
                error_remark = "Middle Stop"
                stop_bit = 0
                start_seq = 0
                AA_seq.clear()
                codon_seq.clear()
                return
            else:
                AA_seq.append(acid)
        protein = ""

    if stop_bit == 1:
        global combined_aa_string
        codon_string = ''.join(codon_seq)
        # print(codon_string)
        count_A = codon_string.count('A')
        count_T = codon_string.count('T')
        count_G = codon_string.count('G')
        count_C = codon_string.count('C')
        amino_string = ''.join(AA_seq)
        combined_aa_string += amino_string
        codon_len = len(codon_string)
        write_db(gene_information, codon_string, amino_string, codon_len, count_A, count_T, count_G, count_C)
        print(codon_string)
        AA_seq.clear()
        codon_seq.clear()
        return

def read_file(input_file):
    with open(input_file) as file:
        for line in file:
            global start_seq
            if line[0] == '>':
                gene_information = line[1:].strip()
                if len(gene_information) == 0:
                    error_remark = "No Info"
                    print(error_remark)
                    start_seq = 0
                else:
                    start_seq = 1
            elif start_seq == 1:
                if line[0] == '\n':
                    error_remark = "New Line Encountered after Information"
                    #write_output(gene_information, remarks=error_remark)
                    start_seq = 0
                elif line[0] != '\n':
                    parse(line, gene_information)
        start_seq = 0
def main():
    input_file = "data/Ecol_K12_MG1655_.ena"
    read_file(input_file)
    AA_histogram(combined_aa_string)


if __name__ == '__main__':
    main()