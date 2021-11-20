#include <stdio.h>
#include "first.h"

double circularArea(double r);

double circularArea(double r){
    const double pi = 3.1415926535;
    return pi*r*r;
}
int main(){
    double radius=1.0, area=0.0;
    printf("     Areas of Circles\n\n");
    printf("     Radius   Area\n"
           "--------------------\n");
    area = circularArea(radius);
    printf("%10.1f %10.2f\n", radius, area);

    return 0;
}