#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    float salary;
};

int main() {
    FILE *file;
    
    while (1) {
        printf("Выберите операцию:\n");
        printf("1. Добавить запись в файл или начать запись нового файла\n");
        printf("2. Начать обработку созданного файла\n");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            file = fopen("Work.dat", "ab");
            struct Employee emp;
            
            printf("Введите ФИО сотрудника: \n");
            scanf("%s", emp.name);
            printf("Введите среднемесячный заработок: \n");
            scanf("%f", &emp.salary);
            
            fwrite(&emp, sizeof(struct Employee), 1, file);
            fclose(file);
        } else if (choice == 2) {
            file = fopen("Work.dat", "rb");
            struct Employee emp;
            struct Employee maxEmp = {"", 0};
            
            while (fread(&emp, sizeof(struct Employee), 1, file)) {
                if (emp.salary > maxEmp.salary) {
                    maxEmp = emp;
                }
            }
            fclose(file);
            
            if (maxEmp.salary > 0) {
                printf("Сотрудник с наибольшим заработком: %s, %.2f\n", maxEmp.name, maxEmp.salary);
            } else {
                printf("Файл пуст\n");
            }
        } else {
            break;
        }
    }
    
    return 0;
}
