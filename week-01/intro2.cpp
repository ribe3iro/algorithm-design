#include <bits/stdc++.h>

using namespace std;

int main(){
    int Q = 5;
    int n;
    int courses[Q];
    unordered_map<string, int> popularity;
    string key;
    int record;
    while(true){
        popularity.clear();
        cin >> n;
        if(n <= 0){
            break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < Q; j++){
                cin >> courses[j];
            }
            sort(courses, courses+Q);
            key = "";
            for(int j = 0; j < Q; j++){
                key += to_string(courses[j]);
            }
            if(popularity.count(key)){
                popularity[key]++;
            }else{
                popularity.insert(make_pair(key, 1));
            }
        }
        // for(unordered_map<string, int>::iterator it=popularity.begin(); it != popularity.end(); it++){
        record = 1;
        for(auto const& [key, value]:popularity){
            if(value > record){
                record = value;
            }
        }
        if(record == 1){
            record = n;
        }
        cout << record << endl;
    }

    return 0;
}