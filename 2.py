max = 4000000
b = 2
a = 1
sum = 0

while (b <= max):
	if b % 2 == 0:
		sum += b
	b, a = b + a, b

print(sum)
