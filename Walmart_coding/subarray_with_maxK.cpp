#include<bits/stdc++.h>
using namespace std;

int calcMaxLength(vector<int> v, int k) {
	int n = v.size();
	int ans = 0;
	for (int i = 0; i < n;) {
		int len = 0;
		bool flag = false;
		while (v[i] <= k && i < n) {
			len++; i++;
			if (v[i] == k) 
				flag = true;
		}
		if (flag) 
			ans += len;
		while (v[i] > k && i < n) i++;
	}
	return ans;

}

int main() {
	vector<int> v = {2, 1, 4, 9, 9, 2, 3, 8, 3, 4};
	int k = 4;
	int len = calcMaxLength(v, k);
	cout << len;
	return 0;
}