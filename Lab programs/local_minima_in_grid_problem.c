#include <stdio.h>
#define ROWS 5
#define COLS 5
int isLocalMinima(int grid[ROWS][COLS], int i, int j) {
   
    if (i > 0 && grid[i][j] >= grid[i-1][j])
        return 0;
    if (i < ROWS - 1 && grid[i][j] >= grid[i+1][j])
        return 0;
    
    if (j > 0 && grid[i][j] >= grid[i][j-1])
        return 0;
    
    if (j < COLS - 1 && grid[i][j] >= grid[i][j+1])
        return 0;
    return 1;
}

void findLocalMinima(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (isLocalMinima(grid, i, j)) {
                printf("Local minima found at (%d, %d) with value %d\n", i, j, grid[i][j]);
            }
        }
    }
}

int main() {

    int grid[ROWS][COLS] = {
        {10, 20, 10, 30, 40},
        {30, 15, 5, 20, 10},
        {20, 10, 20, 5, 25},
        {30, 40, 10, 50, 5},
        {10, 5, 15, 20, 10}
    };

    findLocalMinima(grid);

    return 0;
}
