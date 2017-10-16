#include <bits/stdc++.h>

using namespace std;

class Increment{
	private:
		int num;
	public:
		Increment(int n) : num(n){};
		int operator()(int x){
			return x + num;
		}	
};

int main(){
	ios_base::sync_with_stdio(0);	
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	transform(arr, arr+n, arr, Increment(5));
	for (int a : arr) cout << a << " ";
	return 0;
}