#include <stdio.h>

void star(int* , int* );

int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);

    star(arr, &result);

    printf("%d", result);

    return 0;
}

void star(int* a, int* sum){
    *sum=0;
    int* p;
    for (p = a; p < a+5; p++) {
        *sum+= *p;
    }
}