#include<bits/stdc++.h>

using namespace std;

int n;
int weights[20];
long long record_difference = 21e9;

void difference(int curr_index, long long diff){
    if(curr_index >= n){
        if(abs(diff) < record_difference){
            record_difference = llabs(diff);
        }
        return;
    }

    difference(curr_index+1, diff+weights[curr_index]);
    difference(curr_index+1, diff-weights[curr_index]);
}

int main(){
    cin >> n;

    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
        sum += weights[i];
    }

    difference(0, 0);

    cout << record_difference << endl;

    return 0;
}
