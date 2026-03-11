#include<bits/stdc++.h>

using namespace std;

struct query{
    int id;
    int t;
    int count = 0;

    bool operator>(const query &other) const{
        if(t > other.t){
            return true;
        }else if(t < other.t){
            return false;
        }else{
            return id > other.id;
        }
    }
};

int main(){
    int n;
    cin >> n;

    priority_queue<query, vector<query>, greater<query>> queries;
    query q;
    string dummy;
    for(int i=0; i<n; i++){
        cin >> dummy >> q.id >> q.t;
        queries.push(q);
    }

    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        q = queries.top();
        cout << q.id << endl;

        q.count++;
        q.t += q.t/q.count;

        queries.pop();
        queries.push(q);
    }

    return 0;
}