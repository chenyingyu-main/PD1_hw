#include <stdio.h>

unsigned long B(int i){
    if (i<=2){
        return 1;
    } else{
        return (2 * B(i-1) + 3 * B(i-2))% 1000000007;
    }
}

int main() {
    int N;
    unsigned long answer;
    scanf("%d", &N);
    answer=B(N);
    printf("%lu", answer);
    return 0;
}
