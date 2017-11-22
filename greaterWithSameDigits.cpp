#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << x

void swap(string &num, int i, int j) {
	char c = num[i];
	num[i] = num[j];
	num[j] = c;
 }

void findNext(string &num) {
	int n = num.size();int min = INT_MAX;
	int minIdx = -1;
	int i, j;
	for (i = n - 1; i > 0; --i) {
		if (num[i] - '0' > num[i-1] - '0')
			break;
	}
	i--;
	if (i <= 0) // sorted in decreasing order
		return;
	for (j = i + 1; j < n; j++) {
		int x = num[j] - '0';
		if (num[i] - '0' < x) {
			if (x < min) {
				min = x;
				minIdx = j;
			}
		}
	}
	swap(num, i, minIdx);
	sort(num.begin() + i + 1, num.end());
}

int main() {
	string num = "534976";
	findNext(num);
	print(num);
	return 0;
}