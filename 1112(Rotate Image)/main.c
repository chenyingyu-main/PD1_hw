#include <stdio.h>
int degree, row, col;
int arr[105][105], tmp[105][105];

int main() {

   scanf("%d%d%d", &degree, &row, &col);
    for (int i = 1; i <= row ; ++i) {
        for (int j = 1; j <= col ; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int k = 90; k <= degree ; k += 90) {
        for (int i = 1; i <= row ; ++i) {
            for (int j = 1; j <= col ; ++j) {
                tmp[j][row-i+1] = arr[i][j];
            }
        }

        row ^= col ^= row ^= col;

        for (int i = 1; i <= row ; ++i) {
            for (int j = 1; j <= col ; ++j) {
                arr[i][j] = tmp[i][j];
            }
        }
    }

    for (int i = 1; i <= row ; ++i) {
        for (int j = 1; j <= col ; ++j) {
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }
}
