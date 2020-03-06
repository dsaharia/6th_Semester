import matplotlib
matplotlib.use("TKAgg")
from collections import Counter
import matplotlib.pyplot as plt


def compute_cumulative(skewness):
    step_total = 0
    cumulative_ratio = []
    for num in skewness:
        step_total += num
        cumulative_ratio.append(step_total)
    # print(cumulative_ratio)
    return cumulative_ratio

def fragment(codon_string):
    codon_count = {}
    skewness = []
    ids = []
    for idx in range(0, len(codon_string)//100 + 1):
        fragment = codon_string[idx*100:(idx*100)+100]
        codon_count = Counter(fragment)
        g_minus_c = codon_count.get('G') - codon_count.get('C')
        g_plus_c = codon_count.get('G') + codon_count.get('C')
        skewness.append(g_minus_c / g_plus_c)
        ids.append(idx)
        
    print(skewness)
    plt.plot(compute_cumulative(skewness))
    plt.show()

if __name__ == '__main__':
    # codon_string = 'atgaaacgcattagcaccaccattaccaccaccatcaccattaccacaggtaacggtgcgggctga'
    fragment(codon_string)