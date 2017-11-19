#include<bits/stdc++.h>
using namespace std;

void findPrimes(int num) {
	map<int, int> hash;
	while (num % 2 == 0) {
		hash[2]++;
		num /= 2;
	}
	
	for (int i = 3; i <= sqrt(num); i += 2) {
		while (num % i == 0) {
			num /= i;
			hash[i]++;
		}
	}
	
	if (num > 2)
		hash[num]++;
	
	for (auto it = hash.begin(); it != hash.end(); it++) {
		cout << it->first << " ";
	}
}

int main() {
	int num = 35;
	findPrimes(num);
	return 0;
}