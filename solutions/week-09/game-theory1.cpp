#include<bits/stdc++.h>

using namespace std;

const int GRID_SIZE = 15;

const vector<pair<int, int>> moves = {
    make_pair(-2,  1), 
    make_pair(-2, -1), 
    make_pair( 1, -2), 
    make_pair(-1, -2)
};

int grundy_matrix[GRID_SIZE][GRID_SIZE];

int mex(set<int> positions){
    int value = 0;
    while(positions.count(value) != 0){
        value++;
    }

    return value;
}

int solve(int x, int y){
    if(x < 0 || y < 0){
        return -1;
    }

    if(grundy_matrix[x][y] > -1){
        return grundy_matrix[x][y];
    }

    set<int> future_positions;
    for(int i = 0; i < moves.size(); i++){
        pair<int, int> move = moves[i];
        int future_grundy = solve(x + move.first, y + move.second);
        future_positions.insert(future_grundy);
    }

    grundy_matrix[x][y] = mex(future_positions);

    return grundy_matrix[x][y];
}

int main(){
    int t;
    cin >> t;

    int k;
    int x,y;
    int grundy = 0;
    fill(&grundy_matrix[0][0], &grundy_matrix[0][0] + (GRID_SIZE * GRID_SIZE), -1);
    grundy_matrix[0][0] = 0;
    grundy_matrix[1][0] = 0;
    grundy_matrix[0][1] = 0;
    grundy_matrix[1][1] = 0;
    for(int i = 0; i < t; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            x--;
            y--;
            grundy = grundy ^ solve(x, y);
        }
        cout << (grundy != 0 ? "Primeiro" : "Segundo") << endl;
    }

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(grundy_matrix[i][j] <= -1)
                printf("__ ");
            else
                printf("%2d ", grundy_matrix[i][j]);
        }
        cout << endl;
    }

    return 0;
}
