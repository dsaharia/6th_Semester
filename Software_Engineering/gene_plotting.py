import matplotlib
matplotlib.use("TKAgg")
from matplotlib import pyplot as plt
from collections import Counter
matplotlib.style.use('fivethirtyeight')


def percentage(count):
    d = {}
    s = sum(count.values())
    for key, v in count.items():
        pct = v * 100.0 / s
        # print(f"Percentage: {key}, {pct}")
        d[key] = pct
    plt.bar(d.keys(), d.values())
    print(d)

def AA_histogram(combined):
    count = Counter(combined)
    print(count)
    percentage(count)
    plt.savefig('foo.png')
    plt.title('Amino Acid Frequency')
    plt.show()

if __name__ == '__main__':
    AA_histogram(amino_string)