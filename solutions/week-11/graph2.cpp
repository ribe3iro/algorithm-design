#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
int n, m;

vector<int> dijkstra(int initial_node){
    vector<int> min_distance(n, INT_MAX);
    min_distance[initial_node] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > unvisited;

    for(int i = 0; i < n; i++){
        unvisited.push(make_pair(min_distance[i], i));
    }

    while(!unvisited.empty()){
        int accum_dist, curr_node;
        tie(accum_dist, curr_node) = unvisited.top();
        unvisited.pop();

        vector<pair<int, int>> neighbor = graph[curr_node];
        for(int i = 0; i < neighbor.size(); i++){
            int neighbor_node, weight;
            tie(neighbor_node, weight) = neighbor[i];

            min_distance[neighbor_node] = min(min_distance[neighbor_node], weight+accum_dist);
        }
    }

    return min_distance;
}

int main(){
    cin >> n >> m;

    graph.assign(n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a].push_back(make_pair(b, w));
    }

    vector<int> start_to_end = dijkstra(0);
    vector<int> end_to_start = dijkstra(n-1);

    return 0;
}
