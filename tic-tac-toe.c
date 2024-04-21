#include <stdio.h>

void initGrid(char[][3]);
void printGrid(char[][3]);

int main(){
    // Grid as 3x3 matrix
    char grid[3][3];

    // Initialising the grid with empty spaces
    initGrid(grid);

    // Printing the grid
    printGrid(grid);
}

void initGrid(char arr[][3]){
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void printGrid(char arr[][3]){
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c", arr[i][j]);
            printf(" | ");
        }
        if(i == 2){
           break; 
        }
        printf("\n-------------\n");
    }
}