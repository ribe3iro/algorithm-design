#include<bits/stdc++.h>

using namespace std;

int N, value[1000], memo[1000];

int solve(int house){
    if(house >= N){
        return 0;
    }

    if(memo[house] > -1){
        return memo[house];
    }

    memo[house] = max(
        value[house] + solve(house+2),
        solve(house+1)
    );

    return memo[house];
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> value[i];
    }
    fill_n(memo, N, -1);

    cout << solve(0) << endl;

    return 0;
}
