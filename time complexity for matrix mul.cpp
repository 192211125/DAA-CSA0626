#include <stdio.h>
#include <time.h>
#define N 100
void multiplyMatrices(int mat1[][N], int mat2[][N], int result[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int mat1[N][N], mat2[N][N], result[N][N];
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    clock_t start = clock();
    multiplyMatrices(mat1, mat2, result, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
