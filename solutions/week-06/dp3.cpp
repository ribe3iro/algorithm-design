#include<bits/stdc++.h>

using namespace std;

int coin[100];
int memo[100][5001];
int N;

int solve(int i, int v){
    if(v == 0){
        return 1;
    }
    if(v < 0 || i >= N){
        return 0;
    }
    if(memo[i][v] > -1){
        return memo[i][v];
    }

    memo[i][v] = solve(i+1, v) + solve(i, v-coin[i]);
    return memo[i][v];
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }

    int v;
    cin >> v;

    fill(&memo[0][0], &memo[0][0] + (100*5001), -1);

    cout << solve(0, v) << endl;

    return 0;
}
