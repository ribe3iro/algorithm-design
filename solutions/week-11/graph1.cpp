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


}

bool bipartite(){
    colors.assign(n, 0);

    bool success = true;
    while(success && !to_visit.empty())
    for(int i = 0; i < n; i++){
        success = success && bipartite_(i, 1);
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
    
    bipartite();

    return 0;
}
