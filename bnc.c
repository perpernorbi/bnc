#include <stdio.h>
#include <stdlib.h>

const int const banknote[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
const int banknote_count = sizeof(banknote)/sizeof(int);

int main(int argc, char* argv[])
{
	printf("   Input");

	int i;
	for (i = 0; i < banknote_count; ++i) 
		printf("%6d", banknote[i]);
	printf("\n");

	int sum[banknote_count + 1];
	for (i = 0; i < banknote_count + 1; ++i) sum[i] = 0;

	for (i = 1; i < argc; ++i ) {
		int number = atoi(argv[i]);
		sum[banknote_count] += number;
		printf("%8d", number);
		
		int j;
		for (j = 0; j < banknote_count; ++j) {
			int needed = number/banknote[j];
			sum[j] += needed;
			printf("%6d", needed);
			number = number%banknote[j];
		}
		printf("\n");
	}

	printf("\n");
	printf("%8d", sum[banknote_count]);
	for (i = 0; i < banknote_count; ++i) 
		printf("%6d", sum[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
