#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
    }
    
void printZigZag(vector<int>& v) {
    bool flag = true;
    
    for (unsigned int i = 0; i < v.size()-1; i++) {
        if (flag) { // 1 for < and 0 for > 
            if (v[i] > v[i+1])
                swap(v, i, i+1);
            flag = false;    
            }
        else {
            if (v[i] < v[i+1])
                swap(v, i, i+1);
            flag = true;    
            }    
        }        
    }

int main() {
    vector<int> v = {4, 3, 7, 8, 6, 2, 1};
    printZigZag(v);
    for (int a : v) 
        cout << a << " ";
    return 0;
    }