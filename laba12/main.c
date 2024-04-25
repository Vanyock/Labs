#include <stdio.h>
#include "parabola.h"

int main() {
    int N = 3; // Количество заданных парабол
    Parabola parabolas[N];

    // Заполнение коэффициентов для каждой параболы
    parabolas[0].a = 1;
    parabolas[0].b = -4;
    parabolas[0].c = 4;

    parabolas[1].a = 2;
    parabolas[1].b = -5;
    parabolas[1].c = 2;

    parabolas[2].a = 3;
    parabolas[2].b = -6;
    parabolas[2].c = 3;

    findIntersectionPoints(parabolas, N);

    return 0;
}
