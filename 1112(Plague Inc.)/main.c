#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double r;
    int ans=1;
    scanf("%lf %d", &r, &n);
    ans=pow(r,n);

    printf("%d", ans);

    return 0;
}
