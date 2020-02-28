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

def parse(line, gene_information):
    stop = 0
    line = line.strip()
    protein = ""
    for i in range(0, len(line), 3):
        protein += line[i:i+3]
        protein = protein.upper()
        codon_seq.append(protein)
        acid = code_table.get(protein)
        global start_seq

        if code_table.get(protein) == '*':
            AA_seq.append('*')
            stop = 1
            start_seq = 0
            # print(f"{gene_information} and {AA_seq}")
        else:
            if stop == 1:
                error_remark = "Middle Stop"
                stop = 0
                start_seq = 0
                write_output(gene_information, remarks=error_remark)
                AA_seq.clear()
                codon_seq.clear()
            elif stop != 1 and start_seq == 1:
                AA_seq.append(acid)
        protein = ""

        if stop == 1:
            write_output(gene_information, codon_seq = codon_seq, AA_seq = AA_seq)
            return


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
                    start_seq = 0
                else:
                    parse(line, gene_information)

def main():
    # input_file1 = "data/Ecol_K12_MG1655_.ena"
    input_file1 = "data/test.ena"
    input_file2 = "data/Ecol_K12_MG1655_.wgs"
    read_file(input_file1)

if __name__ == '__main__':
    main()