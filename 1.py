def count_multiples(multiple, max):
	n = (max - 1) // multiple
	return int(n * (1 + n) * multiple / 2)

print(count_multiples(3, 1000) + count_multiples(5, 1000) - count_multiples(15, 1000))
