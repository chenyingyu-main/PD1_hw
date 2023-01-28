#include <stdio.h>
#include <math.h>

int main() {
    int mode;
    double length, width, height, radius;
    double volume;
    scanf("%d", &mode);

    switch (mode) {
        case 1:
            scanf("%lf", &length);
            volume=pow(length,3);
            break;
        case 2:
            scanf("%lf %lf %lf", &length, &width, &height);
            volume=length*width*height;
            break;
        case 3:
            scanf("%lf %lf", &radius, &height);
            volume=(double)3.14*radius*radius*height;
            break;
        case 4:
            scanf("%lf", &height);
            volume=pow(2/12,0.5)*pow(length,3);
            break;
    }

    printf("%.2lf", volume);
    return 0;
}
