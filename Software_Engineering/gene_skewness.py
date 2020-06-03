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
    return cumulative_ratio

def fragment(codon_string):
    codon_count = {}
    skewness_gc = []
    skewness_at = []
    ids = []
    for idx in range(0, len(codon_string)//100 + 1):
        fragment = codon_string[idx*100:(idx*100)+100]
        codon_count = Counter(fragment)
        print(f"Codon Count for fragment number {idx}: {codon_count}")
        g_minus_c = codon_count.get('G') - codon_count.get('C')
        g_plus_c = codon_count.get('G') + codon_count.get('C')
        a_minus_t = codon_count.get('A') - codon_count.get('T')
        a_plus_t = codon_count.get('A') + codon_count.get('T')
        skewness_gc.append(g_minus_c / g_plus_c)
        skewness_at.append(a_minus_t / a_plus_t)
        ids.append(idx)
        
    #print(skewness)
    cumulative_skewness_gc = compute_cumulative(skewness_gc)
    cumulative_skewness_at = compute_cumulative(skewness_at)
    cumulative_max_index_at = cumulative_skewness_at.index(max(cumulative_skewness_at))
    cumulative_min_index_at = cumulative_skewness_at.index(min(cumulative_skewness_at))

    cumulative_max_index_gc = cumulative_skewness_gc.index(max(cumulative_skewness_gc))
    cumulative_min_index_gc = cumulative_skewness_gc.index(min(cumulative_skewness_gc))
    # For G-C skewness
    plt.plot(cumulative_skewness_gc)
    plt.plot(cumulative_max_index_gc, max(cumulative_skewness_gc), c='r', markersize=10, marker='o')
    plt.plot(cumulative_min_index_gc, min(cumulative_skewness_gc), c='b', markersize=10, marker='o')
    plt.title("G-C Skewness")
    plt.xlabel("Fragment Number")
    plt.ylabel("Cumulative Ratio")
    plt.savefig('skewness_gc.png', bbox_inches = "tight")
    plt.show()
    # For A-T skewness
    plt.plot(cumulative_skewness_at)
    plt.plot(cumulative_max_index_at, max(cumulative_skewness_at), c='r', markersize=10, marker='o')
    plt.plot(cumulative_min_index_at, min(cumulative_skewness_at), c='b', markersize=10, marker='o')
    plt.title("A-T Skewness")
    plt.xlabel("Fragment Number")
    plt.ylabel("Cumulative Ratio")
    plt.savefig("skewness_at.png", bbox_inches = "tight")
    plt.show()
    print(f"G-C Skewness\nPositive Slope Fragment Number: {cumulative_max_index_gc} and Cumulative ratio: {max(cumulative_skewness_gc)}")
    print(f"Negative Slope Fragment Number: {cumulative_min_index_gc} and Cumulative ratio: {min(cumulative_skewness_gc)}")

if __name__ == '__main__':
    fragment(codon_string)