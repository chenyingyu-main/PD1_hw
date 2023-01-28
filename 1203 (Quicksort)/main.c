#include <stdio.h>
#include <stdlib.h>
#define n 8000

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high);
int main(void) {
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

int split(int a[], int low, int high);
void quicksort(int a[], int low, int high){
    int middle;
    if (low>=high){
        return; //avoid that the order is wrong.
    }
    middle=split(a, low, high);
    quicksort(a, low, middle-1); //arrange from low(0) to middle-1
    quicksort(a, middle+1, high); //arrange from middle+1 to high(n-1)
}
int split(int a[], int low, int high){
    int critical_element; //we first pick a number to start.

    critical_element=a[low];

    for(;;){ //start my loop to adjust the order and find the middle
        while (low<high && critical_element<=a[high]){
            high--;
        }
        if (low>=high)
            break;
        else
            a[low++]=a[high];
        // above is how we deal with the order from high
        // below is how we deal with the order from low

        while (low<high && critical_element>=a[low]){
            low++;
        }
        if (low>=high)
            break;
        else
            a[high--]=a[low];
    }

    a[high]=critical_element;
    return high;
}