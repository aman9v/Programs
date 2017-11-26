#include<bits/stdc++.h>
using namespace std;
#define print(a ,b) cout << a << "->" << b << " "; 

void findNextGreater(vector<int> v) {
		int n = v.size();
		stack<int> s;
		s.push(v[0]);
		for (int i = 1; i < n ; ++i) {
			int elem = v[i];
			if (!s.empty()) {
				int top = s.top();
				s.pop();
				
				while (elem > top) {
					print(top, elem);
					if (s.empty())	
						break;
					top = s.top();
					s.pop();
				}
				if (elem <= top)
					s.push(top);
			}
			s.push(elem);
		}
		while (!s.empty()) {
			print(s.top(), -1);
			s.pop();
		} 
	
	}

int main() {
	vector<int> v = {4, 5, 2, 25};
	findNextGreater(v);
	return 0;
}