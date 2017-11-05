#include<bits/stdc++.h>

using namespace std;

int main() {
	int row = 5, col = 5;
	int Cost[][4] = { {3, 6, 8, 2},
                      {5, 2, 4, 3},
                      {1, 1, 20, 10},
                      {1, 1, 20, 10},
                    };

int minCost[4][4];

minCost[0][0] = Cost[0][0];

for (int i = 1; i < 4; i++) {
	minCost[i][0] = minCost[i-1][0] + Cost[i][0];
}
for (int j = ; j < 4; ++j) {
	minCost[0][j] = minCost[0][j-1] + Cost[0][j];
}

for (int i = 1; i < 4; ++i) {
	for (int j = 1; j < 4; ++j) {
		minCost[i][j] = min(minCost[i-1][j], minCost[i][j-1]) + Cost[i][j];
	}
}

cout << minCost[3][3];
	return 0;

}