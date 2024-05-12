def is_palindrome(n):
	x = 0
	temp = n

	while temp > 0:
		x = 10 * x + temp % 10
		temp //= 10

	return x == n

def largest_palindrome(n, m):
	max = 0;

	for i in range(n, m):
		for j in range(n, i):
			num = i * j
			if is_palindrome(num) and num > max:
				max = num

	return max

print(largest_palindrome(100, 1000))
