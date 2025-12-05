#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int graph[10][10];
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int visited[10] = {0};
    int current = 0;
    visited[current] = 1;

    int cost = 0;
    printf("\nGreedy Path: %d -> ", current);

    for (int count = 1; count < n; count++) {
        int next_city = -1;
        int min = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[current][j] < min && graph[current][j] > 0) {
                min = graph[current][j];
                next_city = j;
            }
        }

        visited[next_city] = 1;
        cost += min;
        current = next_city;

        printf("%d -> ", current);
    }

    cost += graph[current][0];
    printf("0");
    printf("\nTotal Greedy Cost = %d\n", cost);
    return 0;
}

