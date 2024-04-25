#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double recursive_geometric_mean(double* array, int size, int index)
{
    if (index >= size) {
        return 1.0; // Базовый случай: среднее геометрическое для одного числа равно этому числу
    } else {
        double current_number = array[index];
        return current_number * recursive_geometric_mean(array, size, index + 1);
    }
}

int main()
{
    int size;
    
    printf("Введите размер динамического массива: ");
    scanf("%d", &size);
    
    double* array = (double*)malloc(size * sizeof(double));
    
    // Заполнение массива случайными числами от 1 до 2
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = 1 + ((double)rand() / RAND_MAX);
    }
    
    double geometric_mean = recursive_geometric_mean(array, size, 0);
    
    printf("Элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("%.4f ", array[i]);
    }
    
    printf("\nСреднее геометрическое для чисел в массиве: %.4f\n", geometric_mean);
    
    free(array); // Освобождаем память, выделенную для массива
    
    return 0;
}