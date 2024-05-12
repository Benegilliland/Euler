# 333 < c < 500
# c/sqrt(2) < b < c

import math
root2 = math.sqrt(2)

def find_triplet():
	for c in range(334, 500):
		c_sq = c * c
		for b in range(int(c / root2), c):
			a = 1000 - b - c

			if a * a + b * b == c_sq:
				return a, b, c

	return a, b, c

a, b, c = find_triplet()
print(f"{a * b * c}")
