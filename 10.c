#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Number of primes not passed to script\n");
		exit(1);
	}

	unsigned long long N = strtoull(argv[1], NULL, 10);
	bool *nums = malloc(N * sizeof(bool));

	for (unsigned long long i = 0; i < N; i++)
		nums[i] = true;

	unsigned long long root = (unsigned long long)sqrt(N);

	for (unsigned long long i = 2; i <= root; i++)
		if (nums[i])
			for (unsigned long long j = i * i; j < N; j += i)
				nums[j] = false;


	unsigned long long sum = 0;
	for (unsigned long long i = 2; i < N; i++)
		if (nums[i])
			sum += i;

	printf("%lld\n", sum);

	free(nums);
	return 0;
}
