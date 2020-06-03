from codon_to_AA_converter import code_table

combined_aa_string = ""
AA_seq = []
codon_seq = []
start_seq = 0
sl_number = 0
#stop = 0

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
            #start_seq = 0
            # print(f"{gene_information} and {AA_seq}")
        else:
            if stop_bit == 1:
                error_remark = "Middle Stop"
                stop_bit = 0
                start_seq = 0
                write_output(gene_information, remarks=error_remark)
                AA_seq.clear()
                codon_seq.clear()
                return
            else:
                AA_seq.append(acid)
        protein = ""

    if stop_bit == 1:
        global combined_aa_string
        # count = ''
        codon_string = ''.join(codon_seq)
        # print(codon_string)
        count_A = codon_string.count('A')
        count_T = codon_string.count('T')
        count_G = codon_string.count('G')
        count_C = codon_string.count('C')
        amino_string = ''.join(AA_seq)
        combined_aa_string += amino_string
        codon_len = len(codon_string)
        write_output(gene_information, codon_seq = codon_seq, AA_seq = AA_seq)
        print(codon_string)
        AA_seq.clear()
        codon_seq.clear()
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
                    write_output(gene_information, remarks=error_remark)
                    start_seq = 0
                elif line[0] != '\n':
                    parse(line, gene_information)
        start_seq = 0
def main():
    input_file = "data/Ecol_K12_MG1655_.ena"
    read_file(input_file)


if __name__ == '__main__':
    main()