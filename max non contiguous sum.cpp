#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxSum(vector <int> &v, size_t n){

    vector <int> ssf(n, 0); // a vector for storing the sum so far.

    if(n==1) return v[0];

    ssf[0] = v[0];
    ssf[1] = max(v[0], v[1]); // returns the max of the two.

    if(n==2) return ssf[1];
    
    if(n>2){
        for(unsigned int i = 2; i < n; i++){
            ssf[i] = max(v[i] + ssf[i-2], ssf[i-1]);
            }     
            
        return *max_element(ssf.begin(), ssf.end()); // returns an iterator and not the element itself. 
        }
    }

int main(){
    vector <int> v = {6, 7, 13, 88};
    size_t n = v.size();
    int max_sum = 0;
    max_sum = maxSum(v, n);
    cout << "The maximum non-contiguous sum is: " << max_sum;
    return 0;
}


// optimized code in terms of space: uses constant space. 

// int maxSum(vector <int> &v, size_t n){

//     int p, q, max_sum = 0;

//     if(n==1) return v[0];

//     else if(n==2) {
//     p = v[0];
//     q = v[1]; // returns the max of the two.
//     return max(p, q);
//     }
    
//     else{
//         p = v[0];
//         q = v[1]; // returns the max of the two.
        
//         for(unsigned int i = 2; i < n; i++){
//             max_sum = max(v[i]+p, q);
//             p = q;
//             q = max_sum;
//             }     
            
//         return max_sum; // returns an iterator and not the element itself. 

//         }
//     }
