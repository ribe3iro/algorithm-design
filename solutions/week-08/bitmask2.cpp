#include<bits/stdc++.h>

using namespace std;

const int MAX_GROUPS = 100;
const int MAX_DISTRICTS = 20;

int n,k;
int groups[MAX_GROUPS];
int coverage = 0;

int solve(int group_index){
    if(coverage == (1 << n)-1){
        return 0;
    }

    if(group_index >= k){
        return INT_MAX;
    }

    // not including current group
    int count_not_including = solve(group_index+1);

    // including current group
    int group = groups[group_index];
    int old_coverage = coverage;
    coverage = coverage | group;
    int count_including = solve(group_index+1);
    if(count_including < INT_MAX){
        count_including += 1;
    }
    int min_antennas = min(count_not_including, count_including);
    coverage = old_coverage;

    return min_antennas;
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

    int min_antennas = solve(0);
    if(min_antennas == INT_MAX){
        min_antennas = -1;
    }

    cout << min_antennas << endl;

    return 0;
}
