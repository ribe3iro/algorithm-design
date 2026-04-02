#include<bits/stdc++.h>

using namespace std;

int N, K, dist[601];
int inf, sup;

bool walk(int walk_length){
    int dist_accum = 0;
    int stops_accum = 0;
    for(int i = 0; i < N+1; i++){
        dist_accum += dist[i];
        if(dist_accum > walk_length){
            stops_accum++;
            dist_accum = 0;
            i--;

            if(stops_accum > K){
                return false;
            }
        }
    }

    return true;
}

int search(int inf, int sup){
    if(inf == sup){
        return inf;
    }

    int walk_length = (inf+sup)/2;

    bool concluded_walk = walk(walk_length);
    if(concluded_walk){
        return search(inf, walk_length);
    } else{
        return search(walk_length+1, sup);
    }
}

int main(){
    int t;

    cin >> t;

    int max_dist, sum;
    for(int i = 0; i < t; i++){
        cin >> N >> K;

        max_dist = -1;
        sum = 0;
        for(int j = 0; j < N+1; j++){
            cin >> dist[j];
            sum += dist[j];
            if(dist[j] > max_dist)
                max_dist = dist[j];
        }

        inf = max((double)ceil(sum / (K+1)), (double)max_dist);
        sup = sum;

        cout << search(inf, sup) << endl;
    }

    return 0;
}
