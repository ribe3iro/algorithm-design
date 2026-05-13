#include"Nim.h"

Nim::Nim(vector<int> heaps){
    this->heaps = heaps;
}

int Nim::getNimSum(){
    int num_heaps = this->heaps.size();
    int grundy_number = 0;

    for(int i = 0; i < num_heaps; i++){
        grundy_number = grundy_number ^ this->heaps[i];
    }

    return grundy_number;
}
