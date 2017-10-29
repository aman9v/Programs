#include<bits/stdc++.h>

using namespace std;

string longestSubstring(char *str) {
    int len = 0;
    while ( str[len++] != '\0');
    unordered_map<char, int> hash;
    string long_so_far= " "; string total_long = " ";
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (hash.find(ch) != hash.end()) {
            long_so_far = " ";
            hash.clear();
            }
        hash.insert({ch, 1});    
        long_so_far += ch;
        if (long_so_far.size() > total_long.size())
            total_long = long_so_far;
        }
    return total_long;    
    }

int main() {
    char str[] = "substringfindout";
    string ls = longestSubstring(str);
    cout << ls.size() << endl;
    for (char &ch : ls) 
        if (ch != ' ')
            cout << ch;
    return 0;
    }