#include <bits/stdc++.h>

using namespace std;

int calculateIncreasingSum(vector <int> const &v){
    int a, b;
    int max_sum, sum = 0;
    a = v[0]; 
    b = v[1] > v[0]? v[0] + v[1] : v[1];
    //cout << a << "\n" << b << "\n";
    for(unsigned int i = 2; i < v.size(); ++i){
        if(v[i] > v[i-1] && v[i] > v[i-2]){
            sum = v[i] + b;
            a = b;
            b = sum;
            if(sum > max_sum) max_sum = sum;
            }
        else if((v[i] > v[i-1] && v[i] < v[i-2]) || (v[i] > v[i-2] && v[i] < v[i-1])) {
            sum = min(a, b) + v[i];
            a = b;
            b = sum;
            if(sum > max_sum) max_sum = sum;
            }
        else max_sum = v[0];
    }
    return max_sum;
    }
    
int main(){
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    while(T--){
    	vector <int> v;
	cin >> N;	
    	for(int i = 0; i < N; ++i){int k; cin >> k; v.push_back(k);}
    	cout << calculateIncreasingSum(v) << "\n";
    }
    //vector <int> v = {1, 101, 2, 3, 100, 4, 5};
    
    //cout << result;1
    return 0;
    }