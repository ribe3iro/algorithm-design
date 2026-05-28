#include<bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int initial_node, vector<vector<pair<int, int>>> graph){
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[initial_node] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > unvisited;

    for(int i = 0; i < graph.size(); i++){
        unvisited.push(make_pair(min_distance[i], i));
    }

    while(!unvisited.empty()){
        int curr_dist, curr_node;
        tie(curr_dist, curr_node) = unvisited.top();
        unvisited.pop();

        vector<pair<int, int>> neighbor = graph[curr_node];
        for(int i = 0; i < neighbor.size(); i++){
            int neighbor_node, weight;
            tie(neighbor_node, weight) = neighbor[i];

            int new_dist;
            if(curr_dist == INT_MAX){
                new_dist = INT_MAX;
            }else{
                new_dist = weight + curr_dist;
            }

            if(new_dist < min_distance[neighbor_node]){
                min_distance[neighbor_node] = new_dist;
                unvisited.push(make_pair(new_dist, neighbor_node));
            }

        }
    }

    return min_distance;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph, graph_inv;
    graph.assign(n, vector<pair<int, int>>());
    graph_inv.assign(n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a].push_back(make_pair(b, w));
        graph_inv[b].push_back(make_pair(a, w));
    }

    vector<int> start_to_end = dijkstra(0, graph);
    vector<int> end_to_start = dijkstra(n-1, graph_inv);

    int min_distance = INT_MAX;
    for(int i = 0; i < n; i++){
        vector<pair<int, int>> neighbor = graph[i];
        for(int j = 0; j < neighbor.size(); j++){
            int neighbor_node, weight;
            tie(neighbor_node, weight) = neighbor[j];

            min_distance = min(min_distance, start_to_end[i] + weight/2 + end_to_start[neighbor_node]);
        }
    }

    printf("%d\n", min_distance);

    return 0;
}
