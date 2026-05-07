#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 20;

int n, m;
int graph[MAX_NODES][MAX_NODES];
int visited = 0;
int memo[1 << MAX_NODES][MAX_NODES];

int solve(int node){
    visited = visited | (1 << node);

    // all nodes visited
    if(visited == ((1 << n)-1)){
        memo[visited][node] = 0;
        visited = visited & (~(1 << node));
        return 0;
    }

    // memoization
    if(memo[visited][node] > -1){
        int aux = memo[visited][node];
        visited = visited & (~(1 << node));
        return aux;
    }

    int min_dist = INT_MAX;
    int neighbor_dist, returned_dist;
    for(int i = 0; i < n; i++){
        neighbor_dist = graph[node][i];
        if((neighbor_dist > 0) && !(visited & (1 << i))){
            returned_dist = solve(i);
            if(returned_dist < INT_MAX){
                min_dist = min(min_dist, neighbor_dist + returned_dist);
            }
        }
    }

    memo[visited][node] = min_dist;
    visited = visited & (~(1 << node));

    return min_dist;
}

int main(){
    cin >> n >> m;

    fill(&graph[0][0], &graph[0][0] + (MAX_NODES * MAX_NODES), 0);
    fill(&memo[0][0], &memo[0][0] + ((1 << MAX_NODES)*(MAX_NODES)), -1);
    int u, v, d;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> d;
        u--; v--;
        graph[u][v] = d;
        graph[v][u] = d;
    }

    int min_dist = solve(0);
    if(min_dist == INT_MAX){
        min_dist = -1;
    }
    cout << min_dist << endl;

    return 0;
}
