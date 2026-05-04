#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 20;

int n, m;
int graph[MAX_NODES][MAX_NODES];
int memo[(1 << MAX_NODES)-1];
int visited = 0;

int solve(int node){
    visited = visited | (1 << node);

    if(visited == (1 << n)-1){
        return 0;
    }

    int min_dist = INT_MAX;
    int curr_dist = 0;
    for(int i = 0; i < MAX_NODES; i++){
        curr_dist = graph[node][j]
        if(curr_dist > 0 && (visited & (1 << node))){
            min_dist = min(min_dist, curr_dist + solve(j));
        }
    }
    if(min_dist < INT_MAX){
        memo[node] = min_dist;
    }

    return memo[node];
}

int main(){
    cin >> n >> m;

    fill(&graph[0][0], &graph[0][0] + (MAX_NODES * MAX_NODES), 0);
    fill(&memo[0], &memo[0] + (MAX_NODES), -1);
    int u, v, d;
    for(int i = 0; i < MAX_NODES; i++)
        for(int j = 0; j < MAX_NODES; j++){
            cin >> u, v, d;
            u--; v--;
            graph[u][v] = d;
            graph[v][u] = d;
        }

    cout << solve(0) << endl;

    return 0;
}
