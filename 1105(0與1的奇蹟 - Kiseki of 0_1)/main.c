#include <stdio.h>

int main(void) {
    int a[32], b[32], c[32];

    for(int i=0; i<32; i++){
        scanf("%d", &a[i]);
    }for(int i=0; i<32; i++){
        scanf("%d", &b[i]);
    }

    for(int i=31; i>=0; i--){
        c[i]=a[i]+b[i];
        if(c[i]==2){ // !!!!!!!!! remember it's not "="
            c[i]=0;
            a[i-1]+=1;
        }if(c[i]==3){
            c[i]=1;
            a[i-1]+=1;
        }
    }
    for(int i=0; i<32; i++){
        printf("%d ", c[i]);
    }

    return 0;
}
