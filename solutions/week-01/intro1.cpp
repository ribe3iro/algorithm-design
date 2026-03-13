#include<iostream>

using namespace std;

int main(){
    int n,s;
    int v[(int)1e6+10];

    cin >> n >> s;
    for(int i=0; i < n; i++){
        cin >> v[i];
    }

    int complement[(int)1e4+10] = {0};
    int comp;
    int count = 0;
    for(int i=0; i < n; i++){
        count += complement[v[i]];
        comp = s - v[i];
        if(comp > 0){
            complement[comp]++;
        }
    }

    cout << count;

    return 0;
}
