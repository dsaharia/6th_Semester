import matplotlib
matplotlib.use("TKAgg")
from matplotlib import pyplot as plt
from collections import Counter
matplotlib.style.use('fivethirtyeight')


def percentage(count):
    AA_percentage = {}
    AA_total = sum(count.values())
    for key, value in count.items():
        percentage = value * 100.0 / AA_total
        AA_percentage[key] = percentage
    return AA_percentage
    

def AA_histogram(combined):
    count = Counter(combined)
    AA_percentage = percentage(count)
    plt.bar(AA_percentage.keys(), AA_percentage.values())
    plt.title('Amino Acid Percentage')
    plt.xlabel('Amino Acids')
    plt.ylabel('Percentage')
    plt.savefig('percentage.png', bbox_inches = "tight")
    plt.show()

if __name__ == '__main__':
    AA_histogram(amino_string)