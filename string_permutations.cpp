#include <bits/stdc++.h>

using namespace std;
typedef vector <string> vs;

vs permute(string remaining) {
    unsigned int len = remaining.size();
    vs result;
    
    if (len == 0) {
        result.push_back("");
        return result;
        }
        
    // if (str == "") {
    //     cout << prefix << endl;
    //     return;
    //     }
    
    for (unsigned int i = 0; i < remaining.size(); i++) {
        string before = remaining.substr(0, i);
        string after = remaining.substr(i + 1);
        vs partials = permute(before + after);
        
        for (string s : partials) {
            result.push_back(remaining[i] + s);
            }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    string str = "";
    cout << "Enter a string: ";
    cin >> str;
    vs allPermutes = permute(str);
    for (string permute : allPermutes) cout << permute << endl;
    return 0;
    }