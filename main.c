#include <stdio.h>
#include <stdlib.h>

// Enable or disable debug printing
// #define DEBUG

#ifdef DEBUG
#define display printf
#else
#define display
#endif

#define BIG_NUMBER 99999

int main(int argc, char *argv[]) {
    // Check if there are enough command line arguments
    if (argc != 2) {
        printf("Usage: %s <amountToPay>\n", argv[0]);
        return 1;
    }
	int amountToPay = atoi(argv[1]);

	// We keep track of the solution to each subproblem
	int* subResults = calloc((amountToPay+1), sizeof(int));
	int* additionalCoins = calloc((amountToPay+1), sizeof(int));
	for (int i = 0; i<=amountToPay; i++)
		subResults[i] = BIG_NUMBER;
	subResults[0] = 0;

	printf("How many types of coins are there?");
	int nCoins;
	scanf("%d", &nCoins);
	int* coins = malloc(sizeof(int) * nCoins);

	printf("Please give %d coin values now:", nCoins);
    for (int i = 0; i < nCoins; i++) 
		scanf("%d", coins+i);

	// Main algorithm here
	for (int i = 1; i<=amountToPay; i++){
		int bestSubResult = BIG_NUMBER;
		for (int j = 0; j < nCoins; j++)
			if (i - coins[j] >= 0 && subResults[i - coins[j]] + 1 < bestSubResult){
				bestSubResult = subResults[i - coins[j]] + 1;
				additionalCoins[i] = coins[j];
			}
		subResults[i] = bestSubResult;

		display("[%d]: %d coins. Last: %d\n", i,  bestSubResult, additionalCoins[i]);
	}

	if (additionalCoins[amountToPay] == 0)
		printf("No way possible!");
	else {
		printf("We need %d coins.\n", subResults[amountToPay]);
		while (amountToPay > 0){
		// Go in reverse and show how we got here
			printf("%d ", additionalCoins[amountToPay]);
			amountToPay = amountToPay - additionalCoins[amountToPay];

		}
	}
	


    printf("\n");
	free(coins);
	free(subResults);
	free(additionalCoins);
    return 0;
}
