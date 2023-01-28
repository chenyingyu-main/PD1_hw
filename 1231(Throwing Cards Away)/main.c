#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // n=9, m=7

    int *a;
    a = malloc((m+n)*sizeof(int)); //clean the array into 0
    for (int i = 0; i < n; ++i) {
        a[i]=0;
    }
    for (int i = 0; i < n; ++i) { //0~n-1: 1~n, n~m-1:0
        a[i]=i+1;
    }

    int k=m;
    int c=1;
    while (k>0){
        for (int i = 0; i < m+n ;) {
            printf("%d ", a[i]);
            ++i;
            a[n-1+c]+=a[i]; //that is make a[9]=a[1](2)
            ++i;
            --k;
            c++;
            if (k<=0)
                break;
        }
    }

    return 0;
}
