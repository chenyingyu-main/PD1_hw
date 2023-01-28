#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position

    spread(&graph[0][0], row, col);

    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here
void spread(char* graph, int row, int col){
    char *p = &graph[0], *a;
    a = p;

    for (p = a+row*N+col; p >= a+col ; p = p-N) {
        if (*p == 'X' || *p == *(a+row*N+col)){
            *p = *(a+row*N+col);
        } else break;
    }
    for (p = a+row*N+col; p < a+M*N+col ; p = p+N) {
        if (*p == 'X' || *p == *(a+row*N+col)){
            *p = *(a+row*N+col);
        } else break;
    }
    for (p = a+row*N+col; p >=a+row*N ; p = p-1) {
        if (*p == 'X' || *p == *(a+row*N+col)){
            *p = *(a+row*N+col);
        } else break;
    }
    for (p = a+row*N+col; p < a+row*N+N ; p = p+1) {
        if (*p == 'X' || *p == *(a+row*N+col)){
            *p = *(a+row*N+col);
        } else break;
    }
}