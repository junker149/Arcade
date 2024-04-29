#include <stdio.h>
#include <stdlib.h>

void initGrid(char[][3]);
void printGrid(char[][3]);
int updateGrid(char[][3], int, char);
char checkWin(char[][3]);

int main(){
    // Grid as 3x3 matrix
    char grid[3][3];

    // Initialising the grid with empty spaces
    initGrid(grid);

    // Printing the grid
    printGrid(grid);

    // Player loop
    char winner;
    char player = 'X';
    while(winner != 'X' && winner != 'O' && winner != 'D')
    {
        int position;
        if(player == 'X')
        {
            do
            {
                printf("PLAYER X : ");
                scanf("%d", &position);
            } while (position > 9 && position < 1);
            updateGrid(grid, position, player);
            player = 'O';
            winner = checkWin(grid);
            continue;
        }
        do
        {
            printf("PLAYER O : ");
            scanf("%d", &position);
        } while (position > 9 && position < 1);
        updateGrid(grid, position, player);
        player = 'X';
        winner = checkWin(grid);
    }
    if(winner == 'D'){
        printf("The game is drawn!");
        return 0;
    }
    printf("The winner is : player %c", winner);
    return 0;
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
    system("cls");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c", arr[i][j]);
            if (j < 2){
                printf(" | ");
            }
        }
        if(i == 2){
           break; 
        }
        printf("\n---------\n");
    }
    printf("\n\n\n");
}

int updateGrid(char arr[][3], int pos, char player){
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (arr[row][col] != ' '){
        return 0;
    }

    arr[row][col] = player;
    printGrid(arr);
    return 1;
}

char checkWin(char arr[][3]){
    // Horizontal
    for(int i = 0; i < 3; i++)
    {
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] & arr[i][0] != ' ')
        {
            return arr[i][0];
        }
    }

    // Vertical
    for(int i = 0; i < 3; i++)
    {
        if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
        {
            return arr[0][i];
        }
    }

    // Diagonal
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
    {
        return arr[0][0];
    }
    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
    {
        return arr[0][2];
    }

    // Draw condition
    int draw = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(arr[i][j] == ' ')
            {
                draw = 0;
                break;
            }
        }
        if(draw == 0)
        {
            break;
        }
    }
    if(draw)
    {
        return 'D'; // Return 'D' for draw
    }

    return ' '; // No winner yet
}