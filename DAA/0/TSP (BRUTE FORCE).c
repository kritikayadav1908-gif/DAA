#include <stdio.h>
#include <limits.h>

int graph[10][10];
int visited[10];
int n, cost = INT_MAX;

void tsp(int city, int count, int current_cost, int start) {
    if (count == n && graph[city][start] > 0) {
        int total_cost = current_cost + graph[city][start];
        if (total_cost < cost)
            cost = total_cost;
        return;
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next] && graph[city][next] > 0) {
            visited[next] = 1;
            tsp(next, count + 1, current_cost + graph[city][next], start);
            visited[next] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0, 0);

    printf("\nMinimum cost = %d\n", cost);

    return 0;
}
