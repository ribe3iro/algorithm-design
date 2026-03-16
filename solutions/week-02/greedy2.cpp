#include<bits/stdc++.h>

using namespace std;

float dist(float a, float b){
    return fabs(a - b);
}

int main(){
    int cases;
    cin >> cases;

    float c,n;
    float pos,curr_dist,edge_dist,center_dist;
    for(int k=0; k<cases; k++){
        cin >> c >> n;

        edge_dist=0;center_dist=c;
        for(int i=0; i<n; i++){
            cin >> pos;
            curr_dist = dist(pos, c/2);
            if(curr_dist > edge_dist)
                edge_dist = curr_dist;
            if(curr_dist < center_dist)
                center_dist = curr_dist;
        }

        cout << (int)(c/2-center_dist) << " " << (int)(c/2+edge_dist) << endl;
    }

    return 0;
}
