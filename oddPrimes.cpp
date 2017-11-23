#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x << " "

void crossOff(vector<bool> &flag, int prime) {
	for (int i = prime * prime; i < flag.size(); i += prime) {
		flag[i] = false;
	}
}

bool isOddPrime(int prime) {
	string num(to_string(prime));
	for (int i = 0; i < num.size(); i++) {
		int x = num[i] - '0';
		if (x % 2 == 0)
			return false;
	}
	return true;		
}
int getNextPrime(vector<bool> flag, int prime) {
	int next = prime + 1;
	while (next < flag.size() && !flag[next])
		next++;
	return next;	
}

vector<int> findPrimes(int l, int r) {
	vector<bool> flag(r + 1, true);
	flag[0] = false;
	flag[1] = false;
	int prime = 2;
	
	while (prime <= sqrt(r)) {
		crossOff(flag, prime);
		prime = getNextPrime(flag, prime);
	}
	
	vector<int> primes;
	for (int i = 2; i < flag.size(); i++) {
		if (flag[i] && i >= l)
			primes.push_back(i);	
	}
	return primes;
}

int main() {
	int l = 21;
	int r = 30;
	int t = 2;
	int count = 0;
	vector<int> primes = findPrimes(l, r);
	for (int prime : primes) {
		if (isOddPrime(prime)) {
			if (t == 1 && prime <= 5)
				count++;
			else if (t == 2 && prime > 5)
				count++;
		}
	}
	print(count);
	return 0;
}