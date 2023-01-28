#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}
int rising_hope(char *R) {
    int value_of_hope=0;
    for (; *R!='\0'; R++){
        if (*R=='P'){
            value_of_hope+=1;
        } else if (*R=='N'){
            value_of_hope-=1;
        }else
            value_of_hope+=0;
    }
    return value_of_hope;
}
