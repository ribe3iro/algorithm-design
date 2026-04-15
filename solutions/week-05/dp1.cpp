#include<bits/stdc++.h>

using namespace std;

int N, cost[1000], memo[1000];

int solve(int floor){
    if(floor >= N){
        return 0;
    }

    if(memo[floor] > -1){
        return memo[floor];
    }

    memo[floor] = min(
        cost[floor] + solve(floor+1),
        cost[floor] + solve(floor+2)
    );

    return memo[floor];
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }
    fill_n(memo, N, -1);

    cout << min(solve(0), solve(1)) << endl;

    return 0;
}
