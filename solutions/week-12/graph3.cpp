#include<bits/stdc++.h>

using namespace std;

vector<bool> visited;

vector<int> get_path(int s, int t, vector<vector<int>> &graph){
    queue<int> to_visit;

    visited.assign(graph.size(), false);
    vector<int> previous(graph.size(), -1);

    visited[s] = true;
    to_visit.push(s);
    while(!to_visit.empty() && !visited[t]){
        int u = to_visit.front(); to_visit.pop();
        for(int v = 0; v < graph.size(); v++){
            if(graph[u][v] && !visited[v]){
                visited[v] = true;
                to_visit.push(v);
                previous[v] = u;
            }
        }
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
            graph_prime[i][j] = graph[i][j];
        }
    }

    vector<int> st_path = get_path(s, t, graph_prime);
    while(st_path.size() > 0){
        for(int i = 0; i < st_path.size()-1; i++){
            int u, v;
            u = st_path[i];
            v = st_path[i+1];
            graph_prime[u][v]--;
            graph_prime[v][u]++;
        }

        st_path = get_path(s, t, graph_prime);
    }
    
    vector<pair<int, int>> cut_edges;
    for(int u = 0; u < graph.size()-1; u++){
        for(int v = u+1; v < graph.size(); v++){
            if(graph[u][v] && visited[u] != visited[v]){
                cut_edges.push_back(
                    make_pair(u, v)
                );
            }
        }
    }

    return cut_edges;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, false));

    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back(make_pair(a, b));
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<pair<int, int>> cut_edges = mincut(0, n-1, graph);

    // formatting
    for(int i = 0; i < cut_edges.size(); i++){
        cut_edges[i].first++;
        cut_edges[i].second++;
        bool found = false;
        for(int j = 0; j < edges.size(); j++){
            if(cut_edges[i] == edges[j]){
                found = true;
                break;
            }
        }

        if(!found){
            int u, v;
            tie(u, v) = cut_edges[i];
            cut_edges[i] = make_pair(v, u);
        }
    }
    sort(cut_edges.begin(), cut_edges.end());

    // printing
    cout << cut_edges.size() << endl;
    for(int i = 0; i < cut_edges.size(); i++){
        int u, v;
        tie(u, v) = cut_edges[i];
        printf("%d %d\n", u, v);
    }

    return 0;
}
