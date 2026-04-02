#include<bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int modulo(int base, long long exp){
    if(exp == 1){
        return base;
    }

    long long modulated = modulo(base, floor(exp/2)) % M;
    modulated = (modulated * modulated) % M;
    if(exp % 2 == 1)
        modulated = (modulated * base) % M;
    return modulated;
}

int main(){
    int car, t;
    long long c;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> car >> c;

        // Fermat's little theorem
        c = c % (M-1);

        cout << modulo(car, c) << endl;
    }

    return 0;
}
