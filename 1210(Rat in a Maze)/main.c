#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char(*)[n], int(*)[n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            route[i][j]=0;
            scanf("%c", &maze[i][j]);
            getchar();
        }
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                printf("%d ", route[i][j]);
            printf("\n");
        }
    } else {
        printf("Can't find the exit!");
    }
    return 0;
}
// Your code goes here

// TODO: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.
bool visit(char maze[][n], int route[][n], int originX, int originY) {
    //the start is (0,0)
    int x = originX, y = originY; //use x, y as the moving point
    route[x][y] = 1;
    if (x==4 && y==4) return 1;

    //the range; the next step is not wall; the next step is unexplored before; there will be 1 all the way.
    if (x+1<5 && maze[x+1][y]=='r' && route[x+1][y]==0 && visit(maze, route, x+1, y)==1) return 1;
    if (x-1>=0 && maze[x-1][y]=='r' && route[x-1][y]==0 && visit(maze, route, x-1, y)==1) return 1;
    if (y+1<5 && maze[x][y+1]=='r' && route[x][y+1]==0 && visit(maze, route, x, y+1)==1) return 1;
    if (y-1>=0 && maze[x][y-1]=='r' && route[x][y-1]==0 && visit(maze, route, x, y-1)==1) return 1;
    else {
        route[x][y]=0;
        return 0;
    }
}
