#include <stdio.h>

int sequence_X(int x1, int x2, int n){
    if (n>=3){
        if(n==3){
            return x1+x2;
        }else if (n==4){
            return sequence_X(x1, x2, n-1)+x2;
        }else
            return sequence_X(x1, x2, n-1)+sequence_X(x1, x2,n-2);
    }
}
int main() {
    int x1, x2, n, answer;
    while(1){
        scanf("%d %d %d", &x1, &x2, &n);
        if ((x2==x1 && x2==0) && (x2==n && n==0)){
            return 0;
        }
        answer = sequence_X(x1, x2, n);
        printf("%d\n", answer);
    }


    return 0;
}
