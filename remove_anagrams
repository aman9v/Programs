#include<bits/stdc++.h>

using namespace std;

void elimAnagrams(vector<string> s) {
    map<string, string> hash;
    for (unsigned int i = 0; i < s.size(); i++) {
        string str = s[i];
        sort(str.begin(), str.end());
        if (hash.find(str) == hash.end()) {
            hash.insert({str, s[i]});
            } else {
                hash[str] = " ";
                }
        }
        
        for (auto it = hash.begin(); it != hash.end(); it++) {
            pair<string, string> p = *it;
            if (p.second != " ")
                cout << it->second << endl;
            }
    }

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        }
    elimAnagrams(s);    
    return 0;
    }