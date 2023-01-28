#include <stdio.h>
#define maxN 50

int n, order = 1, k, arr[maxN];
char ch;


int main() {
    scanf("%d\n", &n);

    for (int i = 1; i <= n ; ++i){
        scanf("%c", &ch);
        arr[i] = ch - 'a';
    }

    getchar(); //getchar the new line character.

    while (scanf("%c", &ch) && ch!='\n'){
        if (order > n) order = 1; //if order exceeds, i will return to one.

        k = arr[order];

        if (ch >= 'a' && ch <= 'z'){
            printf("%c", 'a'+(ch-'a'+k)%26);
            order++;
        } else if (ch >= 'A' && ch <= 'Z'){
            printf("%c", 'A'+(ch-'A'+k)%26);
            order++;
        } else
            printf("%c", ch);
    }

    return 0;
}
