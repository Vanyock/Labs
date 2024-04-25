#include <stdio.h>
#include "parabola.h"
#include <math.h>

void findIntersectionPoints(Parabola parabolas[], int N) {
    for (int i = 0; i < N; i++) {
        double discriminant = parabolas[i].b * parabolas[i].b - 4 * parabolas[i].a * parabolas[i].c;
        if (discriminant >= 0) {
            double x1 = (-parabolas[i].b + sqrt(discriminant)) / (2 * parabolas[i].a);
            double x2 = (-parabolas[i].b - sqrt(discriminant)) / (2 * parabolas[i].a);
            printf("Parabola %d: Intersection points with X-axis are %lf and %lf\n", i+1, x1, x2);
        } else {
            printf("Parabola %d: No intersection points with X-axis\n", i+1);
        }
    }
}
