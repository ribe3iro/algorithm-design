#include<bits/stdc++.h>

using namespace std;

const int NUM_QUEENS = 8;

bool exploded[NUM_QUEENS][NUM_QUEENS];
int attacked[NUM_QUEENS][NUM_QUEENS];
int valid_count = 0;

void _attack(int row, int col, int val){
    // row and col
    for(int i = 0; i < NUM_QUEENS; i++){
        attacked[row][i] = max(0, attacked[row][i]+val);
        attacked[i][col] = max(0, attacked[i][col]+val);
    }

    // itself
    attacked[row][col] = 0;

    // 1st quadrant
    for(int i = 1; (row-i >= 0) && (col+i < NUM_QUEENS); i++)
        attacked[row-i][col+i] = max(0, attacked[row-i][col+i]+val);

    // 2nd quadrant
    for(int i = 1; (row-i >= 0) && (col-i >= 0); i++)
        attacked[row-i][col-i] = max(0, attacked[row-i][col-i]+val);

    // 3rd quadrant
    for(int i = 1; (row+i < NUM_QUEENS) && (col-i >= 0); i++)
        attacked[row+i][col-i] = max(0, attacked[row+i][col-i]+val);

    // 4th quadrant
    for(int i = 1; (row+i < NUM_QUEENS) && (col+i < NUM_QUEENS); i++)
        attacked[row+i][col+i] = max(0, attacked[row+i][col+i]+val);
}

void attack(int row, int col){ _attack(row, col, 1); }
void unattack(int row, int col){ _attack(row, col, -1); }

void position_queen(int row){
    if(row >= NUM_QUEENS){
        valid_count++;
        return;
    }
    
    for(int col = 0; col < NUM_QUEENS; col++){
        if(!(exploded[row][col] || attacked[row][col])){
            attack(row, col);
            position_queen(row+1);
            unattack(row, col);
        }
    }
}

int main(){
    char c;
    for(int i = 0; i < NUM_QUEENS; i++){
        for(int j = 0; j < NUM_QUEENS; j++){
            cin >> c;
            if(c == '*')
                exploded[i][j] = true;
            else
                exploded[i][j] = false;
            attacked[i][j] = 0;
        }
    }

    position_queen(0);
    cout << valid_count << endl;

    return 0;
}
