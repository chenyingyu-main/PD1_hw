#include <stdio.h>

int main(void) {
    int n;
    scanf("%u\n", &n);
    unsigned int matrix[n][n];
    unsigned int row, line;

    for(row=0; row<n; row++){
        for(line=0; line<n; line++){
            scanf("%u", &matrix[row][line]);
        }
    }
    for(row=0; row<n; row++){
        for(line=0; line<n; line++){
            if (matrix[row][line]!=matrix[line][row]){
                printf("No\n");
                return 0;
            }

        }
    }
    printf("Yes\n");

    return 0;
}
