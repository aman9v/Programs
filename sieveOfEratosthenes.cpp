#include<bits/stdc++.h>
using namespace std;
 
void crossOff(vector<bool> &flags, int prime) {
	for (int i = prime * prime; i < flags.size(); i += prime) {
		flags[i] = false;
	}
}
 
int getNextPrime(vector<bool> &flags, int prime) {
	int next = prime + 1;
	while (next < flags.size() && !flags[next]) 
		next++;
	return next;	
}
 
void findPrimes(int num) {
	vector<bool> flags(num+1, true);
	flags[0] = false;
	flags[1] = false;
	int prime = 2;
 
	while (prime <= sqrt(num)) {
		crossOff(flags, prime);
		prime = getNextPrime(flags, prime);
	}
 
	for (int i = 2; i < flags.size(); i++) {
		if (flags[i])
			cout << i << " ";
	}
}
 
int main() {
	int num = 28;
	findPrimes(num);
	return 0;
}