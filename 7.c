#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 105000
#define PRIME 10001

int main(int argc, char *argv[])
{
	bool *nums = malloc(N * sizeof(bool));

	for (int i = 0; i < N; i++)
		nums[i] = true;

	int root = (int)sqrt(N);

	for (int i = 2; i <= root; i++) {
		if (nums[i]) {
			for (int j = i * i; j < N; j += i)
				nums[j] = false;
		}
	}

	int i, prime = 0;
	for (i = 2; i < N && prime < PRIME; i++) {
		if (nums[i])
			prime++;
	}

	if (prime == PRIME)
		printf("%d\n", --i);
	else
		printf("N too low\n");

	free(nums);
	return 0;
}
