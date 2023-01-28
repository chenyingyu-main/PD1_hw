#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM]){
    int row, col;
    // if there's a mistake mark it on my check list

    int check_list[9][9];
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            check_list[row][col]=0;
        }
    }

    //horizontal and vertical
    for (row = 0; row < 9; row++){
        for (col = 0; col < 9 ; col++) {
            for (int i = 0; i < 9; ++i) {
                if (grid_p[row][i]==grid_p[row][col] && i!=col){ //deal with the same row
                    check_list[row][col]=1;
                }
                if (grid_p[i][col]==grid_p[row][col] && i!=row){ //deal with the same col
                    check_list[row][col]=1;
                }
            }
        }
    }

    //deal with the nine boxes.
    // 1 2 3
    // 4 5 6
    // 7 8 9
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9 ; col++) {
            if (row/3==0){
                if (col/3==0){ //deal with 1
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==1){ //deal with 2
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 3; j < 6; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==2){ //deal with 3
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 6; j < 9; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
            }
            if (row/3==1){
                if (col/3==0){ //deal with 4
                    for (int i = 3; i < 6; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==1){ //deal with 5
                    for (int i = 3; i < 6; ++i) {
                        for (int j = 3; j < 6; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==2){ //deal with 6
                    for (int i = 3; i < 6; ++i) {
                        for (int j = 6; j < 9; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
            }
            if (row/3==2){
                if (col/3==0){ //deal with 7
                    for (int i = 6; i < 9; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==1){ //deal with 8
                    for (int i = 6; i < 9; ++i) {
                        for (int j = 3; j < 6; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
                if (col/3==2){ //deal with 9
                    for (int i = 6; i < 9; ++i) {
                        for (int j = 6; j < 9; ++j) {
                            if (grid_p[row][col]==grid_p[i][j] && (i!=row||j!=col))
                                check_list[row][col]=1;
                        }
                    }
                }
            }
        }
    }
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (check_list[row][col]==1){
                printf("(%d,%d)\n", row, col);
            }
        }
    }


}