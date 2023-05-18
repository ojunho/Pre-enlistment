import sys
from collections import Counter

num_words = 1000
rank = 1

counter = Counter(word.lower()
                  for line in sys.stdin
                  for word in line.strip().split()
                  if word)

for word, count in counter.most_common(num_words):
    print("%d. %s\t%d" %(rank, word, count))
    rank += 1