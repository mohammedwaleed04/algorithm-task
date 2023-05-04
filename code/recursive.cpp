#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diagonalSumDiff(int matrix[][100], int n, int i, int leftsumdiagonal, int rightsumdiagonal) {
    // Base case
    if (n == i) {
        return abs(leftsumdiagonal - rightsumdiagonal);
    }
    if (i < n) {
        leftsumdiagonal += matrix[i][i];
        rightsumdiagonal += matrix[i][n - i - 1];
        i++;
        return diagonalSumDiff(matrix, n, i, leftsumdiagonal, rightsumdiagonal);
    }
}

int main() {
    int n, i, j;
    printf("Enter the size of the matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid matrix size.\n");
        return -1;
    }
    int matrix[100][100];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1 || matrix[i][j] < -100 || matrix[i][j] > 100) {
                printf("Invalid matrix element.\n");
                return -1;
            }
        }
    }
    int diff = diagonalSumDiff(matrix, n, 0, 0, 0);
    printf("Absolute difference between the sums of the diagonals: %d\n", diff);
    return 0;
}
