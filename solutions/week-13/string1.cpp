#include<bits/stdc++.h>

using namespace std;

vector<int> get_LPS(string pattern){
    vector<int> LPS(pattern.size(), 0);

    int i = 1;
    int j = 0;

    while(i < pattern.size()){
        if(pattern[i] == pattern[j]){
            j++;
            LPS[i] = j;
            i++;
        }else if(j > 0){
            j = LPS[j-1];
        }else{
            LPS[i] = 0;
            i++;
        }
    }

    return LPS;
}

vector<int> get_occurrences(string pattern, string text){
    vector<int> positions;
    vector<int> LPS = get_LPS(pattern);
    
    int i = 0;  // text
    int j = 0;  // pattern

    while(i < text.size()){
        if(text[i] == pattern[j]){
            j++;
            i++;
        }

        if(j == pattern.size()){
            positions.push_back(i-j);
            j = LPS[j-1];
        }else if(i < text.size() && text[i] != pattern[j]){
            if(j != 0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
    }

    return positions;
}

int main(){
    int n;
    while(cin >> n){
        string pattern, text;

        cin >> pattern >> text;

        vector<int> positions = get_occurrences(pattern, text);
        for(int i = 0; i < positions.size(); i++){
            cout << positions[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
