#include <stdio.h>

unsigned long C(int n, int m){
    if (m==0 || m==n){
        return 1;
    } else{
        return C(n-1, m-1)+C(n-1, m);
    }
}


int main() {
    int n, m, answer;
    scanf("%d %d", &n, &m);
    answer=C(n, m);
    printf("%d", answer);
    return 0;
}
