#include<bits/stdc++.h>
using namespace std;

int factorial[30];

int func(int x, int y) {
	   return factorial[x+y] / (factorial[x] * factorial[y]);
}

void findNextStep(int x, int y, int k) {
		if (x == 1 && y == 0 ) {
			cout << "H";
			return;
		}
		if (y == 1 && x == 0) {
			cout << "V";
			return;
		}
		 
		if (func(x-1, y) > k) {
				cout << "H";
				findNextStep(x-1, y, k);
			}
				
		else {
			cout << "V";
			findNextStep(x, y-1, k - func(x-1, y));
		}			
	return;
}

int main() {
    int t;
    cin >> t;
    factorial[0] = 1;
    for (int i = 1; i < 30; ++i) {
        factorial[i] = i * factorial[i-1];
    }
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        findNextStep(x, y, k);
        cout << "\n";
    }
	return 0; 
}