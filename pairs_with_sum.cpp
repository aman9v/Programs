#include<bits/stdc++.h>

using namespace std;

int countPairs(int *arr, int k, int n) {
    unordered_map<int, int> hash;
    int count = 0;
    for (int i = 0; i < n; i++) {
        hash.insert({arr[i], i});
        if (hash.find(k - arr[i]) != hash.end()) {
            if (hash[k - arr[i]] != i) {
                count++; 
                cout << arr[i] << " " << k - arr[i] << endl;
                hash.erase(k - arr[i]);
                hash.erase(arr[i]);
                }
            }
            
        }
    return count;
    }

int main() {
    int arr[] = {1, 3, 46, 1, 3, 9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int count = countPairs(arr, 47, n);
    cout << count;    
    return 0;
    }