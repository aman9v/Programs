#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x;

void swap(string &num, int i, int j) {
	char c = num[i];
	num[i] = num[j];
	num[j] = c;
}

void odd2even(string &num) {
	int n = num.size();
	bool flag = false;
	int i = 0; int index = 0;
	while (i <= n-1) {
		int x = num[i] - '0';
		if (x % 2 == 0) {
			index = i;
			if (x <= num[n-1] - '0') {
				flag = true; break;	
			}
				
		}
		i++;
}
if (index == 0)
	return;
swap(num, index, n-1);	
}

int main() {
	string num;
	cin >> num;
	odd2even(num);
	print(num);
	return 0;
}