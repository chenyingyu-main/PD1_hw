#include <stdio.h>

int main(void) {

    int a[10], noise=0, max_noise=0;

    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            noise=(a[i]+a[j])*(i-j);
            for(int k=0; k<100; k++){   //cause 10*10=100
                if(noise>=max_noise){
                    max_noise=noise;
                } else
                    max_noise=max_noise;
            }
        }
    }
    printf("%d", max_noise);

    return 0;
}
