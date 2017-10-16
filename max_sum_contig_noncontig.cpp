#include <bits/stdc++.h>

using namespace std;

int maxContigousSum(vector<int>& v, size_t n){
    
    vector<int> ssf(n, 0);
    
    ssf[0] = v[0];
    
    if(n == 1) return ssf[0];

    // ssf[1] = max(v[0]+v[1], max(v[0], v[1]));
    ssf[1] = v[0] + v[1];

    if(n == 2) return ssf[1];
    
    if(n > 2){
        
        // if (all_of(v.begin(), v.end(), [](int i){return i > 0;})) return accumulate(v.begin(), v.end(), 0);
            
        for(unsigned int i = 2; i< v.size(); ++i) ssf[i] = v[i] + max(v[i-1], ssf[i-1]);    
    
    }
    
    return *max_element(ssf.begin(), ssf.end());
    
    }
    
int maxSumNonContiguous(vector <int> &v, size_t n){

    vector <int> ssf(n, 0); // a vector for storing the sum so far.

    if(n==1) return v[0];

    ssf[0] = v[0];
    ssf[1] = max(v[0], v[1]); // returns the max of the two.

    if(n==2) return ssf[1];
    
    if(n>2){
        for(unsigned int i = 2; i < n; i++){
            ssf[i] = max(v[i] + ssf[i-1], ssf[i-1]);
            }     
            
        }
        // return *max_element(ssf.begin(), ssf.end()); // returns an iterator and not the element itself. 
        return ssf[n-1];
    }
    

int main(){
    
    
    int max_sum_contig, max_sum_non_contig = 0;
    vector< pair<int, int> > p;
    int test_cases, n;
    cin >> test_cases;
    for(int i = 0; i< test_cases; i++){
        vector<int> v;
        cin >> n;
        
        for(int j = 0; j<n; j++) {
            int input;
            cin >> input; 
            v.push_back(input);
            }
        
        if (all_of(v.begin(), v.end(), [](int i){return i > 0;})) {
            max_sum_contig = max_sum_non_contig = accumulate(v.begin(), v.end(), 0);
            // cout << max_sum << " " << max_sum;
            }
        else{    
            max_sum_contig = maxContigousSum(v, v.size()); 
            max_sum_non_contig = maxSumNonContiguous(v, v.size());
            // cout << max_sum_contig << " " << max_sum_non_contig;
            }    
            p.push_back(make_pair(max_sum_contig, max_sum_non_contig));
        }
    // cout << max_sum_contig << " " << max_sum_non_contig;
    
    for(unsigned int i = 0; i< p.size(); i++){
        cout << p[i].first <<" " << p[i].second << endl;
        }
    return 0;
    
    }

    retarr(int i){
        
    }