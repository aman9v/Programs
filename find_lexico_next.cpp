#include<bits/stdc++.h>

using namespace std;

string findNext(string str) {
    if (str == " ") 
        return "a";
    int i = str.size() - 1;
    while (str[i] == 'z' && i >= 0) {
        i--;
        }
    if (i == -1)
        str = str + 'a';
    else 
        str[i]++;
    return str;
    }

int main() {
    string str;
    cin >> str;
    string result = findNext(str);
    cout << "The next next string is: " << result; 
    return 0;
    }