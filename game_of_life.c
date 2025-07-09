#include <stdio.h>

#define H 25
#define W 80

void input_1(int earth[H][W]);
void show(int earth[H][W]);
void uptdate_field(int field[H][W]);
int count_neighbors(int board[H][W], int x, int y);

int main() {
    int earth[H][W] = {0};
    
    input_1(earth);
    show(earth);
    uptdate_field(earth);
    show(earth);

    return 0;
}

void input_1(int earth[H][W]) {
    FILE *f = fopen("txt1.txt", "r");    
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
                fscanf(f, "%d", &earth[y][x]);
            }
        }
    fclose(f);
}

void show(int earth[H][W]) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            printf("%c", earth[y][x] ? 'X' : ' '); 
        }
        printf("\n");
    }
}

int count_neighbors(int board[H][W], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            
            int nx = x + i;
            int ny = y + j;
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (board[nx][ny] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void uptdate_field(int field[H][W]){
    int new_field[H][W] = {0};
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            int neighbords = count_neighbors(field, y, x);
            if (field[y][x] == 1) {
                if(neighbords == 2 || neighbords == 3){
                    new_field[y][x] = 1;
                }
                else{
                    new_field[y][x] == 0;
                }
            }
            else{
                if (neighbords == 3){
                    new_field[y][x] = 1;
                }
                else{
                    new_field[y][x] = 1;
                }
            }
        }
    }
    for (int y = 0; y < H; y++){
        for (int x = 0; x < W; x++){
            field[y][x] = new_field[y][x];
        }
    }
}
