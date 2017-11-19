#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x << " "

void removeDuplicates(vector<int> &v) {
    unordered_map<int, int> hash;
    for (int i = 0; i< v.size(); i++)  {
        if (hash.find(v[i]) == hash.end()) {
            hash.insert({v[i], 1});
        } else {
            do {
                v[i]++;
                }while (hash.find(v[i]) != hash.end());
            hash.insert({v[i], 1});    
            }    
    }
}

int main() {
    vector<int> v = {1, 5, 6, 5, 6};
    removeDuplicates(v);
    for (int a : v) 
            print(a);
}