import sys

list_n = [line.split()[1] for line in sys.stdin]
print(list_n)
print("length: ", len(list_n))