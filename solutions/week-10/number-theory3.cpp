#include<bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int potMod(int base, int exp, int m){
    if(exp == 0){
        return 1;
    }

    if(exp == 1){
        return base;
    }

    long long int modulated = potMod(base, floor(exp/2), m) % m;
    modulated = (modulated * modulated) % m;
    if(exp % 2 == 1)
        modulated = (modulated * base) % m;
    return modulated;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;

        cout << potMod(a, potMod(b, c, M-1), M) << endl;
    }

    return 0;
}
