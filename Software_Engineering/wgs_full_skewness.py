from gene_plotting import AA_histogram
from gene_skewness import fragment
from codon_to_AA_converter import code_table

AA_seq = []
codon_seq = []
# STOP words are in the middle
# length % 3 != 0
# STOP words not in end

def parse(line, gene_information):
    line = line.strip()
    protein = ""
    for i in range(0, len(line), 3):
        protein += line[i:i+3]
        protein = protein.upper()
        codon_seq.append(protein)
        acid = code_table.get(protein)
        AA_seq.append(acid)       
        protein = ""

def read_file(input_file):
    with open(input_file) as file:
        for line in file:
            # global start_seq
            if line[0] == '>':
                gene_information = line[1:].strip()

            else:
                parse(line, gene_information)
        # print(list(filter(None, test_list)))
        #AA_histogram(list(filter(None, AA_seq)))
        codon_string = ''.join(codon_seq)
        fragment(codon_string)
def main():
    input_file = "data/Ecol_K12_MG1655_.wgs"
    read_file(input_file)
    # AA_histogram(combined_aa_string)


if __name__ == '__main__':
    main()