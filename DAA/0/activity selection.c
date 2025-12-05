#include <stdio.h>

void sortActivities(int start[], int finish[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

void activitySelection(int start[], int finish[], int n) {
    sortActivities(start, finish, n);

    printf("Selected activities are:\n");

    int i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i = j;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, finish, n);

    return 0;
}
