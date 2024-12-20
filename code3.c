/*Best time to sell a commodity: 
Given an array of positive integers that represent the 
price of a commodity on a given day, return two 
integers which represent the best day to buy and later, sell the commodity. 
*/

#include <stdio.h>
#include <limits.h>

void bestTimeToBuySell(int prices[], int size, int *buyDay, int *sellDay) {
	int minPrice = INT_MAX;
	int maxProfit = 0;
	int minDay = 0;

	for (int i = 0; i < size; i++) {
		if (prices[i] < minPrice) {
			minPrice = prices[i];
			minDay = i;
		}
		int profit = prices[i] - minPrice;
		if (profit > maxProfit) {
			maxProfit = profit;
			*buyDay = minDay;
			*sellDay = i;
		}
	}
}

int main() {
	int prices[] = {7, 1, 5, 3, 6, 4};
	int size = sizeof(prices) / sizeof(prices[0]);
	int buyDay = 0, sellDay = 0;

	bestTimeToBuySell(prices, size, &buyDay, &sellDay);

	printf("Best day to buy: %d\n", buyDay);
	printf("Best day to sell: %d\n", sellDay);

	return 0;
}
