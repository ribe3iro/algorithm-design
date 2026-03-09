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
    int compl;
    int count = 0;
    for(int i=0; i < n; i++){
        compl = s - v[i];
        if(compl > 0){
            complement[compl]++;
            complement[v[i]]
        }
    }

    for(int i=0; i < n; i++){

    }

    return 0;
}

3 5

2 3 7

[3]=1
[2]=1
