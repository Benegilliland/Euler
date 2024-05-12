import math

def is_prime(n):
	if n == 1:
		return False
	if n % 2 == 0:
		return True if n == 2 else False

	root = math.floor(math.sqrt(n))

	for i in range(3, root + 1):
		if n % i == 0:
			return False

	return True

def largest_prime_factor(n):
	for i in range(2, n // 2 + 1):
		if n % i == 0:
			factor = n // i;
			if is_prime(factor):
				return factor

	return -1

print(largest_prime_factor(600851475143))
