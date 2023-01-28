#include <stdio.h>
#include <stdlib.h>

int* Returns(int n);

int main(int argc, char *argv[])
{
    int in, *out;
    scanf("%d", &in);
    out = Returns(in);
    for(int i = 0;i < in;++i) {
        printf("out[%d] = %d\n", i, out[i]);
    }
    free(out);
    return 0;
}

// Your code goes here
int* Returns(int n) {
    int *a;
    a = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        a[i] = i*i;
    }
    return a;
}
