#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

// Функция для обмена первого и последнего слов в строке
void swapFirstAndLastWord(char *line) {
    char *tempLine = strdup(line);
    char *words[MAX_LINE_LENGTH];
    int wordCount = 0;

    // Извлекаем все слова из строки
    char *word = strtok(tempLine, " ");
    while (word != NULL) {
        words[wordCount++] = word;
        word = strtok(NULL, " ");
    }

    if (wordCount >= 2) { // Проверяем, что в строке есть как минимум два слова
        char *temp = words[0]; // Сохраняем первое слово
        words[0] = words[wordCount - 1]; // Заменяем первое слово последним
        words[wordCount - 1] = temp; // Заменяем последнее слово первым

        // Восстанавливаем строку с измененным порядком слов
        strcpy(line, words[0]);
        for (int i = 1; i < wordCount; i++) {
            strcat(line, " ");
            strcat(line, words[i]);
        }
    }

    free(tempLine);
}

int main() {
    FILE *file = fopen("input.txt", "r+");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        swapFirstAndLastWord(line);
        fputs(line, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("input.txt");
    rename("temp.txt", "input.txt");

    return 0;
}

