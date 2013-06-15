"""
K&R Exercise 1-13.
Print a histogram of the lengths of words in stdin.

"""
import sys
from collections import defaultdict

MAX_LENGTH = 20

def main():
    hist = defaultdict(int)
    for L in (len(w) for w in sys.stdin.read().split()):
        hist[min(L, MAX_LENGTH)] += 1

    for i in range(1, MAX_LENGTH + 1):
        line = ['%2d%s | ' % (i, '+' if i == MAX_LENGTH else ' ')]
        line.append('#' * min(hist[i], 70))
        if hist[i] > 70:
            line.append('+')
        print ''.join(line)

if __name__ == '__main__':
    main()
