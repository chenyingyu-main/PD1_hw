#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}
// Your code goes here
int cmp(const void *a, const void *b) {
    struct ESPer *aptr = a;
    struct ESPer *bptr = b;

    if(aptr->level < bptr->level) return -1;
    if(aptr->level == bptr->level) return 0;
    if(aptr->level > bptr->level) return 1;
}

void sort_level(struct ESPer *arr, int length) {
    qsort(arr, length, sizeof(struct ESPer), cmp);
    /*void qsort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *a, const void *b));*/
}
