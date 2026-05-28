#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;
int n, m;

bool bipartite_(int node, int color){
    if(colors[node] == color){
        return true;
    }

    if(colors[node] != 0 && colors[node] != color){
        return false;
    }

    colors[node] = color;
    vector<int> neighbors = graph[node];
    bool success = true;
    for(int i = 0; i < neighbors.size(); i++){
        int neighbor = neighbors[i];
        success = success & bipartite_(neighbor, 3-color);
    }

    return success;
}

bool bipartite(){
    colors.assign(n, 0);

    bool success = true;

    for(int i = 0; i < n; i++){
        if(colors[i] == 0){  // node i not visited
            success = success && bipartite_(i, 1);
        }
        if(!success){
            break;
        }
    }

    return success;
}

int main(){
    cin >> n >> m;

    graph.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    if(bipartite()){
        pair<int, int> counts;
        for(int i = 0; i < n; i++){
            if(colors[i] == 1){
                counts.first++;
            }else{
                counts.second++;
            }
        }

        printf("%d %d\n", counts.first, counts.second);
    }else{
        printf("impossivel\n");
    }

    return 0;
}
