#include<bits/stdc++.h>

using namespace std;

int M, N;
int grid[200][200];
int memo[200][200];

int solve(int lin, int col){
    int curr_val = grid[lin][col];

    if(memo[lin][col] > -1)
        return memo[lin][col];

    // arrived
    if(lin == M-1 && col == N-1)
        return curr_val;

    // bottom edge
    if(lin == M-1)
        memo[lin][col] = curr_val + solve(lin, col+1);

    // right edge
    else if(col == N-1)
        memo[lin][col] = curr_val + solve(lin+1, col);
    
    else
        memo[lin][col] = min(
            curr_val + solve(lin+1, col),
            curr_val + solve(lin, col+1)
        );

    return memo[lin][col];
}

int main(){
    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    fill(&memo[0][0], &memo[0][0] + (200*200), -1);

    cout << solve(0, 0) << endl;

    return 0;
}
