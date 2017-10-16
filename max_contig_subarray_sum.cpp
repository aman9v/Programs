#include <bits/stdc++.h>

using namespace std;

int maxContSum(vector<int>& v, size_t n){
    
    vector<int> ssf(n, 0);
    if(n == 0) return 0;
    
    ssf[0] = v[0];
    
    if(n == 1) return ssf[0];

    ssf[1] = max(v[0]+v[1], max(v[0], v[1]));

    if(n == 2) return ssf[1];
    
    if(n > 2){
        
        if (all_of(v.begin(), v.end(), [](int i){return i > 0;})) return *max_element(v.begin(), v.end());
            
        for(unsigned int i = 2; i< v.size(); ++i) ssf[i] = v[i] + min(v[i-1], ssf[i-1]);    
    
    }
    
    return *max_element(ssf.begin(), ssf.end());
    
    }

int main(){
    
    vector<int> v = {3, -4, 2, -3, -1, 7, -5};
    int max_sum = maxContSum(v, v.size());
    cout << min_sum;
    return 0;
    
    }