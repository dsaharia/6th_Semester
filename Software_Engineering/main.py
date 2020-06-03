from wgs_full_skewness import main as wgs_main
from codon_to_AA_converter_file import main as file_main
from codon_to_AA_converter import main as db_main

while True:
    print("\n1. Save the Amino acid sequence to text file")
    print("2. Save the Amino acid sequence to database and plot the percentage")
    print("3. Plot the G-C and A-T skewness of wgs file")
    print("4. Exit\n")
    choice = int(input("Enter a valid Choice:"))

    if choice == 1:
        file_main()
    elif choice == 2:
        db_main()
    elif choice == 3:
        wgs_main()
    elif choice == 4:
        exit()
