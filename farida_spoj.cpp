#include <bits/stdc++.h>
using namespace std;

int maxReward(vector<int> v, int n) {
	if (n == 1) 
		return v[0];
	else if (n == 2)
		return max(v[0], v[1]);
	vector<int> sum(n, 0);
	sum[0] = v[0];
	sum[1] = max(v[0], v[1]);
	for (int i = 2; i < n; i++) {
		sum[i] = max(sum[i-1], v[i] + sum[i-2]);
	}
	return sum[n-1];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int c = 1;
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i]; 
		}
		cout << "Case " << c << ":" << maxReward(v, n) << "\n";
		c++;
	}
	return 0;
}