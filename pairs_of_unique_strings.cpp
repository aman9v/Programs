#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> vs = {
        "aman",
        "abhi",
        "vibhu",
        "rajat"
        };
        
    unordered_map<char, int> hash;    
    
    for (int i = 0; i < vs.size(); i++) {
        for (char ch : vs[i]) {
            if (hash.find(ch) == hash.end())
                hash.insert({ch, 1});
            else hash[ch]++;    
            }
        for (int j = i + 1; j < vs.size(); j++) {
            bool unique = true;
            for (char ch : vs[j]) {
                if (hash.find(ch) != hash.end()) {
                    unique = false;
                    break;
                }
            }    
            if (unique) 
                cout << vs[i] << " " << vs[j] << endl;
            }
            hash.clear();
        }    
    return 0;
    }