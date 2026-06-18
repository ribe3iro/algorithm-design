#include<bits/stdc++.h>

using namespace std;

vector<int> get_occurrences(string pattern, string text){
    vector<int> positions;
    for(int i = 0; i < text.size(); i++){
        int j;
        for(j = 0; j < pattern.size(); j++){
            if(text[i] != pattern[j]){
                break;
            }
        }
        if(j == pattern.size()){
            positions.push_back(i);
        }
    }

    return positions;
}

int main(){
    do{
        int n;
        string pattern, text;

        cin >> n >> pattern >> text;

        vector<int> positions = get_occurrences(pattern, text);
        if(positions.size() == 0){
            cout << endl;
        }else{
            for(int i = 0; i < positions.size(); i++){
                cout << positions[i] << endl;
            }
        }
        cout << endl;

    }while(true);

    return 0;
}
