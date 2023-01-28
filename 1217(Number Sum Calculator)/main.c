#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
int addition(char str[]){
    //"1+2+3+4+5"
    char *p;
    int sum=0;
    p = strtok(str, "+"); //split into "1"(into p) and "2+3+4+5"(save into NULL)
    do {
        int a;
        a=atoi(p); //turn '1'(char) into int 1
        sum+=a;
        p = strtok(NULL, "+"); //split NULL("2+3+4+5") into "2" and "3+4+5"
    }while (p!= NULL); //repeat

    return sum;
}