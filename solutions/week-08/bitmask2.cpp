#include<bits/stdc++.h>

using namespace std;

const int MAX_GROUPS = 100;

int n,k;
int groups[MAX_GROUPS];
int coverage = 0;

int solve(int group_index){
    int group = groups[group_index];
    coverage = coverage | group;

    if(coverage == (1 << n)-1){
        return 0;
    }

    
}

int main(){
    cin >> n >> k;

    fill(&groups[0], &groups[0] + MAX_GROUPS, 0);

    int q;
    int district;
    for(int i = 0; i < k; i++){
        cin >> q;
        for(int j = 0; j < q; j++){
            cin >> district;
            groups[i] = groups[i] | (1 << district);
        }
    }

    int min_antennas = -1;
    for(int i = 0; i < k; i++){
        min_antennas = min(min_antennas, solve(i));
    }

    cout << min_antennas << endl;

    return 0;
}
