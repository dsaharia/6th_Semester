def read_file(input_file):
    with open(input_file) as file:
        for line in file:
            line = line.strip()
            if line[0] == '>':
                gene_information = line
                print(gene_information)
        #print(type(line))

def main():
    input_file1 = "data/Ecol_K12_MG1655_.ena"
    input_file2 = "data/Ecol_K12_MG1655_.wgs"
    read_file(input_file1)

if __name__ == '__main__':
    main()