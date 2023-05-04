/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, leftSumDiagonal = 0, rightSumDiagonal = 0;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] < -100 || arr[i][j] > 100)
                return -1;
        }
    }
    for (i = 0; i < n; i++) {
        leftSumDiagonal += arr[i][i];
        rightSumDiagonal += arr[i][n - i - 1];
    }
    int diff = abs(leftSumDiagonal - rightSumDiagonal);
    printf("The absolute difference between the sums of the diagonals is %d\n", diff);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int diagonalSumDiff(int matrix[][100], int n) {
    // Base case
    if (n == 1) {
        return 0;
    }
    int diff = 0;
    int i;
    for (i = 0; i < n; i++) {
        diff += matrix[i][i] - matrix[i][n-1-i];
    }
    diff = abs(diff);
    int secound_diff = diagonalSumDiff(matrix+1, n-2);
    return diff + secound_diff;
}

int main() {
    int n, i, j;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int matrix[100][100];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
             if(matrix[i][j] < -100 || matrix[i][j] > 100) {
                return -1;
            }
        }
    }
    int diff = diagonalSumDiff(matrix, n);
    printf("Absolute difference between the sums of the diagonals: %d\n", diff);
    return 0;
}*/


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
