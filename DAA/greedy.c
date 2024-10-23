#include <stdio.h>

// Function to perform the Activity Selection problem
void activitySelection(int start[], int finish[], int n) {
    int i, j;

    printf("Selected Activities: ");

    // The first activity is always selected
    i = 0;
    printf("%d ", i);

    // Consider the rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity's start time is greater or equal to the last selected activity's finish time
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j; // Update the index of the last selected activity
        }
    }
    printf("\n");
}

int main() {
    int n;

    // Input the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    // Input the start and finish times
    printf("Enter the start times of the activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Start time of activity %d: ", i + 1);
        scanf("%d", &start[i]);
    }

    printf("Enter the finish times of the activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Finish time of activity %d: ", i + 1);
        scanf("%d", &finish[i]);
    }

    // Sort activities by their finish time (if not already sorted)
    // Simple bubble sort for demonstration purposes (O(n^2) time complexity)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                // Swap finish times
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                // Swap start times to keep corresponding pairs
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    activitySelection(start, finish, n);
    return 0;
}