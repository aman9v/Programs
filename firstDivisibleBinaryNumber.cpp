#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x

int mod(string s, int num) {
	int n = 0;
	for (char c : s) {
		n = n * 10 + c - '0';
	}
	return n % num;
}

string findZeroOne(int num) {
	queue<string> Q;
	Q.push("1");
	set<string> visited;
	while (!Q.empty()) {
		string str = Q.front();
		Q.pop();
		
		if (mod(str, num) == 0)
			return str;
		else if (visited.find(str) == visited.end()){
			visited.insert(str);
			Q.push(str + "0");
			Q.push(str + "1");
		}	
	}
}

int main() {
	int num = 12;
	string strNum = findZeroOne(num);
	print(strNum);
	return 0;
}