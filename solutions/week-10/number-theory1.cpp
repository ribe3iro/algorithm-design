#include<bits/stdc++.h>

using namespace std;

int const MAX_VALUE = 1e6;
int const MAX_SIEVE_VALUE = ceil(sqrt(MAX_VALUE));
bitset<MAX_SIEVE_VALUE+1> sieve;
vector<int> primes;

void populateSieve(){
    sieve.set();
    sieve.reset(0);
    sieve.reset(1);
    primes.clear();

    for(int i = 2; i <= MAX_SIEVE_VALUE; i++){
        if(sieve.test(i)){
            primes.push_back(i);

            for(long long j = i*i; j <= MAX_SIEVE_VALUE; j+=i){
                sieve.reset(j);
            }
        }
    }
}

map<int, int> primeFactorization(int x){
    map<int, int> factors;
    for(int i = 0; i < primes.size() && x >= primes[i]*primes[i]; i++){
        int prime = primes[i];
        while(x % prime == 0){
            x = x / prime;
            factors[prime]++;
        }
    }

    if(x > 1){
        factors[x]++;
    }

    return factors;
}

int numDivisors(int x){
    map<int, int> factors = primeFactorization(x);
    int total_divisors = 1;
    for (auto const& [prime, exponent] : factors) {
        total_divisors *= (exponent+1);
    }

    return total_divisors;
}

int main(){
    int n;
    cin >> n;

    populateSieve();

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cout << numDivisors(x) << endl;
    }
    
    return 0;
}
