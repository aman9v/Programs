#include<bits/stdc++.h>

using namespace std;

void removeDuplicates(char str[]) {
    int n = 0;
    while (str[n++] != '\0'); // calculates length of the string 
    
    if (n < 2) 
        return;
    int current = 0;
    for (int next = 1; next < n; next++) {
        if (str[next] != str[current]) {
            current++;
            str[current] = str[next];
            }
        }
    current++;
    str[current] = '\0';
    cout << str;
}
int main() {
    char str[] = "geeksforgeeks";
    removeDuplicates(str);
    return 0;
    }