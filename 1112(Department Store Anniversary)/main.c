#include <stdio.h>
#define  maxN 10010
int n, m, arr[maxN];

int main() {
    scanf("%d %d", &n, &m);
    int N = m+n;

    for (int i = 0; i < maxN ; ++i) {
        arr[i] = 0;
    }
    for (int i = 1, x; i <= N ; ++i) {
        scanf("%d", &x);
        arr[x] = 1;
    }

    for (int i = 1; i < maxN; ++i) {
        if (arr[i]){
            printf("%d ", i);
        }
    }

    return 0;
}
