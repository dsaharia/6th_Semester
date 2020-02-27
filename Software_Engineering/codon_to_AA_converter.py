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

def parse(line, gene_information):
    line = line.strip()
    protein = ""
    for i in range(0, len(line), 3):
        protein += line[i:i+3]
        protein = protein.upper()
        codon_seq.append(protein)
        acid = code_table.get(protein)
        if code_table.get(protein) == '*':
            AA_seq.append('*')
            # print(f"{gene_information} and {AA_seq}")
            write_output(gene_information, codon_seq = codon_seq, AA_seq = AA_seq)
            return
        else:
            AA_seq.append(acid)

        protein = ""


start_seq = 0
sl_number = 0

def write_output(gene_information, codon_seq='X', AA_seq='X', remarks='Success'):
    global sl_number;
    sl_number += 1
    output_file = open('output.txt', 'a')
    output_line = [sl_number, gene_information, codon_seq, AA_seq, remarks]
    output_file.write(str(output_line))
    output_file.write('\n')
    output_file.close()


def read_file(input_file):
    with open(input_file) as file:
        for line in file:
            if line[0] == '>':
                gene_information = line[1:].strip()
                start_seq = 1
            elif start_seq == 1:
                if line[0] == '\n':
                    error_remark = "New Line Encountered after Information"
                    write_output(gene_information, remarks=error_remark)
                    break
                parse(line, gene_information)

def main():
    # input_file1 = "data/Ecol_K12_MG1655_.ena"
    input_file1 = "data/test.ena"
    input_file2 = "data/Ecol_K12_MG1655_.wgs"
    read_file(input_file1)

if __name__ == '__main__':
    main()