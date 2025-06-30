#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int **matrix, int rows, int cols, const char *name) {
    printf("Enter values for matrix %s (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

int** allocate_matrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(int));
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
}

void multiply_and_save(int **A, int m, int n, int **B, int j, int k) {
    if (n != j) {
        printf("Invalid dimensions: %dx%d cannot be multiplied by %dx%d\n", m, n, j, k);
        return;
    }

    int **result = allocate_matrix(m, k);
    for (int i = 0; i < m; i++)
        for (int l = 0; l < k; l++) {
            result[i][l] = 0;
            for (int z = 0; z < n; z++)
                result[i][l] += A[i][z] * B[z][l];
        }

    FILE *file = fopen("matrix_result.txt", "w");
    for (int i = 0; i < m; i++) {
        for (int l = 0; l < k; l++)
            fprintf(file, "%d\t", result[i][l]);
        fprintf(file, "\n");
    }
    fclose(file);
    free_matrix(result, m);
}

int main() {
    int m, n, j, k;
    printf("Enter dimensions m and n for Matrix A: ");
    scanf("%d %d", &m, &n);
    int **A = allocate_matrix(m, n);
    fill_matrix(A, m, n, "A");

    printf("Enter dimensions j and k for Matrix B: ");
    scanf("%d %d", &j, &k);
    int **B = allocate_matrix(j, k);
    fill_matrix(B, j, k, "B");

    multiply_and_save(A, m, n, B, j, k);

    free_matrix(A, m);
    free_matrix(B, j);

    return 0;
}
