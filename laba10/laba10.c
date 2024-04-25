#include <stdio.h>
void sortSecondaryDiagonal(int n, int matrix[][n]) {
int i, j, temp;

for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (i + j == n - 1) {
for (int k = 0; k < n; k++) {
if (matrix[i][i] < matrix[j][j]) {
temp = matrix[i][i];
matrix[i][i] = matrix[j][j];
matrix[j][j] = temp;
}
}
}
}
}
}

int main() {
int n, sum, count = 0;

printf("Введите размер матрицы: ");
scanf("%d", &n);

int matrix[n][n];

printf("Введите элементы матрицы:\n");

for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &matrix[i][j]);
}
}

for (int j = 0; j < n; j++) {
sum = 0;
for (int i = 0; i < n; i++) {
sum += matrix[i][j];
}
if (sum > 12) {
for (int i = 0; i < n; i++) {
if (i == j) {
matrix[i][j] -= matrix[i][i];
}
}
count++;
}
}

printf("Количество строк, сумма столбцов которых больше 12: %d\n", count);

sortSecondaryDiagonal(n, matrix);

printf("Побочная диагональ в порядке убывания: \n");
for (int i = 0; i < n; i++) {
printf("%d ", matrix[i][n - 1 - i]);
}
printf("\n");

return 0;
}