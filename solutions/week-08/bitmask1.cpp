#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 20;

int n, m;
int graph[MAX_NODES][MAX_NODES];
int visited = 0;

int solve(int node){
    visited = visited | (1 << node);

    if(visited == ((1 << n)-1)){
        return 0;
    }

    int min_dist = INT_MAX;
    int neighbor_dist, returned_dist;
    for(int i = 1; i < n; i++){
        neighbor_dist = graph[node][i];
        if((neighbor_dist > 0) && !(visited & (1 << i))){
            returned_dist = solve(i);
            if(returned_dist < INT_MAX){
                min_dist = min(min_dist, neighbor_dist + returned_dist);
            }
        }
    }

    visited = visited & (~(1 << node));

    return min_dist;
}

int main(){
    cin >> n >> m;

    fill(&graph[0][0], &graph[0][0] + (MAX_NODES * MAX_NODES), 0);
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
