#include <stdio.h>

int main(void) {
    int n;
    scanf("%d\n", &n);
    char a[n];

    for(int i=0; i<n; i++){
        scanf("%c", &a[i]);
    }
    for(int i=n-1; i>=0; i--){
        printf("%c", a[i]);
    }


    return 0;
}
