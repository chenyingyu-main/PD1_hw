#include <stdio.h>

int ackermann(int n, int m){
    if (n==0){
        return m+1;
    }else if (m==0){
        return ackermann(n-1, 1);
    } else
        return ackermann(n-1, ackermann(n, m-1));
}

int main() {
    int n, m , answer;
    scanf("%d %d", &n, &m);
    answer=ackermann(n, m);
    printf("%d", answer);

    return 0;
}
