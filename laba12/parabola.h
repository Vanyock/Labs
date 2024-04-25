#ifndef PARABOLA_H
#define PARABOLA_H

typedef struct {
    double a;
    double b;
    double c;
} Parabola;

void findIntersectionPoints(Parabola parabolas[], int N);

#endif
