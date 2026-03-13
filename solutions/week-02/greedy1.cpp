#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,d,h,accum;
    bool match;

    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0)
            break;

        priority_queue<int, vector<int>, greater<int>> diams,heights;
        for(int i=0; i<n; i++){
            cin >> d;
            diams.push(d);
        }
        for(int i=0; i<m; i++){
            cin >> h;
            heights.push(h);
        }

        if(n > m){
            cout << "no" << endl;
            continue;
        }

        accum = 0;
        do{
            d = diams.top();

            match = false;
            do{
                h = heights.top();

                if(h >= d){
                    match = true;
                    diams.pop();
                    accum += h;
                }
                heights.pop();
            }while(!heights.empty() && !match);
        }while(!diams.empty() && !heights.empty());

        if(diams.empty())
            cout << accum << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
