#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x << " ";

void crossOff(int prime, vector<bool> &flag) {
    for (int i = prime * prime; i < flag.size(); i += prime) {
        flag[i] = false;
    }
}

int getNextPrime(int prime, vector<bool> flag) {
    int next = prime + 1;
    while (next < flag.size() && !flag[next])
        next++;
    return next;
}

vector<int> findPrimes(int l, int r) {
    int prime = 2;
    vector<bool> flag(r+1, true);
    flag[0] = false;
    flag[1] = false;
    vector<int> primes;
    while (prime <= sqrt(r)) {
        crossOff(prime, flag);
        prime = getNextPrime(prime, flag);
    }

    for (int i = 0; i < flag.size(); i++) {
        if (flag[i] && i >= l)
            primes.push_back(i);
    }
    return primes;

}

int main() {
    int l, r;
    cin >> l >> r;
    unordered_map<int, int> hash;
    vector<int> primes = findPrimes(l ,r);
    vector<int> sum(primes.size(), 0);
    sum[0] = primes[0];
    for (int i = 1; i < primes.size(); ++i) {
        sum[i] = primes[i-1] + primes[i];
        hash[primes[i]]++;
    }
    
     for (int a : sum) {
        if (a != 2 && hash.find(a+1) != hash.end())
            print(a+1);
     }      
    return 0;
}