#include<bits/stdc++.h>
using namespace std;

int main() {
	int led[10];
	led[0] = 6;
	led[1] = 2;
	led[2] = 5;
	led[3] = 5;
	led[4] = 4;
	led[5] = 5;
	led[6] = 6;
	led[7] = 3;
	led[8] = 7;
	led[9] = 6;
	string num = "082";
	int sum = led[num[0] - '0'];
	for (int i = 1; i < num.size(); ++i) {
		sum += abs(led[num[i] - '0'] - led[num[i-1] - '0']);
	}
	cout << sum;
	return 0;
}