#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

void printSubstrings(string s, set<string> &stringSet) {
	for (int i = 0; i < s.size(); i++) {
		if (isVowel(s[i])) {
			for (int j = s.size() - 1; j >= i; j--) {
				if (!isVowel(s[j])) {
					string newString = s.substr(i, j + 1);
					stringSet.insert(newString);
					
					for (int k = 1; k < newString.size() - 1; k++) {
						string rs = newString.substr(0, k) + newString.substr(k + 1);
						printSubstrings(rs, stringSet);
					}
				}

			}
		}
	}
}

int main() {
	string str = "xabcef";
	set<string> stringSet;
	printSubstrings(str, stringSet);
	for (auto it = stringSet.begin(); it != stringSet.end(); it++) {
	    cout << *it << "\n";
	}
	cout << stringSet.size();
	return 0;
}
