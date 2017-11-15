#include<bits/stdc++.h>
using namespace std;

void calcSubarrays(vector<int> v, int sum) {
    int curr_sum = v[0];
    int start = 0;
    for (int i = 1; i < v.size(); i++) {
        if (curr_sum == sum){
            cout << "From index " << start << " to " << i-1 << endl;
            return ;
        }        
        if (curr_sum > sum) {
            while (curr_sum > sum && start <= i-1) {
                curr_sum -= v[start++];
                }
            } 
        if (i < v.size()) 
            curr_sum += v[i];
        }
    cout << "No subarray with the given sum" ;        
    }

int main() {
    vector<int> v = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 28;
    calcSubarrays(v, sum);
    return 0;
    }
