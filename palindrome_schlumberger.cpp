#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {
	string s = "";
	for (char ch : str) {
		if (isalpha(ch))
			s += ch;
	}
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (tolower(s[i]) != tolower(s[j])) {
			return false;
		}
		i++; j--;
	}	
	return true;
}

int main() {
	string str = "i-i.t+h@h*T-i^I";
	if (isPalindrome(str))
		cout << "Palindrome";
	else cout << "Not a palindrome";
	return 0;
}