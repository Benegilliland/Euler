#include <stdio.h>
#include <set>

// We can use the binary method to get an upper bound
int binary_method(unsigned char n)
{
	int sum = n & 1;

	while (n >>= 1) {
		sum += n & 1;
		sum += 1;
	}

	return sum - 1;
}

// Recursive depth first search
int check_move(int n, int upper_bound, int moves, std::set<int> &powers)
{
	/*for (int num : powers)
		printf("%d ", num);
	printf("\n");*/
	// If we already reached the upper bound, end this branch
	if (moves >= upper_bound)
		return upper_bound;

	int min = upper_bound;
	for (int i : powers) {
		for (int j : powers) {
			int sum = i + j;

			if (sum == n) {
				/*printf("List: ");
				for (int num : powers)
					printf("%d ", num);
				printf("%d\n", n);*/
				return moves + 1;
			}

			if (!powers.contains(sum) && sum <= n) {
				powers.insert(sum);
				int x = check_move(n, upper_bound, moves + 1, powers);
				powers.erase(sum);

				if (x < min)
					min = x;
			}
		}
	}

	return min;
}

int minimum_moves(unsigned char n)
{
	int upper_bound = binary_method(n);
	printf("Upper bound: %d\n", upper_bound);
	std::set<int> powers;
	powers.insert(1);
	return check_move(n, upper_bound, 0, powers);
}

int main(int argc, char *argv[])
{
	printf("Result: %d\n", minimum_moves(100));
	return 0;
}
