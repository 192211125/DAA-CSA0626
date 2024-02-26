#include <stdio.h>

#define MAX 10

int final[MAX];
int count = 0;

void subset_sum(int arr[], int n, int sum, int curr_sum, int curr_index) {
    if (curr_sum == sum) {
        printf("Subset %d: ", ++count);
        for (int i = 0; i < curr_index; i++) {
            printf("%d ", final[i]);
        }
        printf("\n");
        return;
    }
    if (curr_index == n || curr_sum > sum) {
        return;
    }
    final[curr_index] = arr[curr_index];
    subset_sum(arr, n, sum, curr_sum + arr[curr_index], curr_index + 1);
    subset_sum(arr, n, sum, curr_sum, curr_index + 1);
}

int main() {
    int n, arr[MAX], sum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the desired sum: ");
    scanf("%d", &sum);

    printf("Subsets with sum %d:\n", sum);
    subset_sum(arr, n, sum, 0, 0);

    return 0;
}
