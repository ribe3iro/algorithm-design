#ifndef NIM_H
#define NIM_H

#include<vector>

using namespace std;

class Nim{
    public:
        Nim(std::vector<int> heaps);
        int getNimSum();
    
    private:
        std::vector<int> heaps;
};

#endif
