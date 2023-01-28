#include <stdio.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
    char fruit[20][15] = {
            "guava",
            "litchi",
            "longan",
            "watermelon",
            "pomelo",
            "pear",
            "banana",
            "papaya",
            "pumpkin",
            "tomato",
            "mango",
            "kiwi",
            "persimmon",
            "cantaloupe",
            "strawberry",
            "grape",
            "peach",
            "orange",
            "coconut",
            "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}
// Your code goes here
// input is the fruit sequence eg: watermelon+_+watermelon+_+coconut+_+grape+_+coconut
// fruit is 20 kinds of fruit name eg: fruit[0] is "guava", fruit[1] is litchi and so on.
// you need to check the Loader code to understand above meaning

void find_fruit(char input[],char fruit[][15]){
    int check[20];
    for (int i = 0; i < 20; ++i) {
        check[i]=0;
    }

    int compare;
    char *p;

    p = strtok(input, "+_+");
    do {
        for (int i = 0; i < 20 ; ++i) {
            compare = strcmp(p,fruit[i]);
            if (compare == 0){
                check[i]++;
                break;
            }
        }
        p = strtok(NULL, "+_+");
    }while (p !=NULL);

    int big;
    for (int i = 0; i <20 ; ++i) {
        if (check[i]>=big){
            big = check[i];
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (check[i] == big){
            printf("%s\n", fruit[i]);
        }
    }
}