#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Otherwise, two choices:
    // 1. Include nth item
    // 2. Exclude nth item
    else
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),  // include
            knapsack(W, wt, val, n - 1)                            // exclude
        );
}

int main() {
    int val[] = {60, 100, 120};   // Values of items
    int wt[] = {10, 20, 30};      // Weights of items
    int W = 50;                   // Capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));

    return 0;
}
