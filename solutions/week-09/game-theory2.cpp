#include<bits/stdc++.h>

using namespace std;

const vector<int> moves = {-2, -3, -5};
vector<int> memo;

int mex(set<int> positions){
    int value = 0;
    while(positions.count(value) != 0){
        value++;
    }

    return value;
}

int grundy(int n){
    if(n < 0){
        return -1;
    }

    if(memo[n] > -1){
        return memo[n];
    }

    set<int> future_positions;
    for(int i = 0; i < moves.size(); i++){
        int position = grundy(n + moves[i]);
        future_positions.insert(position);
    }

    memo[n] = mex(future_positions);

    return memo[n];
}

int main(){
    int t;
    cin >> t;

    memo.assign(1e6+1, -1);

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        cout << (grundy(n) ? "Tico" : "Teco") << endl;
    }

    return 0;
}