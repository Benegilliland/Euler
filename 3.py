import math

def largest_prime_factor(n):
	root = math.floor(math.sqrt(n))

	for i in range(2, root + 1):
		if n % i == 0:
			return largest_prime_factor(n // i)

	return n

print(largest_prime_factor(600851475143))
