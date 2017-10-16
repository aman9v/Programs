#include <bits/stdc++.h>

using namespace std;

bool isTerminating(int num, int den){
    int com_fact = __gcd(num, den);
    int n = num/com_fact; int d = den/com_fact;
    while(d > 1){
        if(d % 2 == 0) d /= 2;
        else if(d % 5 == 0) d /= 5;
        else return false;
        }
    return true;
    }

vector <int> maxPartProduct(int n){
    float frac = 0.0;
    float max_frac;
    vector <int> sum;
    for(int j = 5; j<=n; ++j){
        max_frac = (float)j/2;
        int den, N = 0;
        for(int k = 3; k <= j; k++){
            frac = pow((float)j/k, k);
            if(frac > max_frac){max_frac = frac; den = k;}
        } 
        
        N = j;   
        if(isTerminating(N, den)) N *= -1;
        sum.push_back(N);
    }
    return sum;
    }

int main(){
    
    int q, n; 
    cin >> q;
    vector <int> v;
    for(int i = 0; i < q; ++i){
        cin >> n;
        v.push_back(n);
        }
    vector <int> final_sum;
    for(unsigned int i = 0; i < v.size(); ++i){
        vector <int> final = maxPartProduct(v[i]);
        
        final_sum.push_back(accumulate(final.begin(), final.end(), 0));
        }
    for (int a : final_sum){
        cout << a << endl ;
        }
    
    return 0;
    
    }