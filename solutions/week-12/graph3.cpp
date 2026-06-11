#include<bits/stdc++.h>

using namespace std;

vector<int> path(int s, int t, vector<vector<int>> &graph){
    queue<int> to_visit;
    vector<bool> visited(graph.size(), false);
    vector<int> previous(graph.size(), -1);

    to_visit.push(s);
    while(!to_visit.empty() && !visited[t]){
        int u = to_visit.front(); to_visit.pop();
        for(int v = 0; v < graph.size(); v++){
            if(graph[u][v] && !visited[v]){
                to_visit.push(v);
                previous[v] = u;
            }
        }

        visited[u] = true;
    }

    vector<int> st_path;
    if(visited[t]){
        int u = t;
        while(u != -1){
            st_path.push_back(u);
            u = previous[u];
        }
        reverse(st_path.begin(), st_path.end());
    }

    return st_path;
}

vector<pair<int, int>> mincut(int s, int t, vector<vector<bool>> &graph){
    vector<vector<int>> graph_prime(graph.size(), vector<int>(graph.size(), 0));
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            graph_prime[j][i] = 1;
        }
    }

    vector<int> st_path;
    do{
        st_path = path(s, t, graph_prime);
        for(int i = 0; i < graph_prime.size()-1; i++){
            int u, v;
            u = st_path[i];
            v = st_path[i+1];
            graph_prime[u][v]--;
            graph_prime[v][u]++;
        }
    }while(st_path.size() > 0);
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<pair<int, int>> edges = mincut(0, n-1, graph);

    return 0;
}