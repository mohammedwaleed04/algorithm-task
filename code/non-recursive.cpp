#include <stdio.h>
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
}
