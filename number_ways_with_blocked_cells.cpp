#include<bits/stdc++.h>
using namespace std;

 int main() {
 	int M, N, B;
 	int x, y; // for blocked cells
 	cin >> M >> N >> B;
 	int Grid[M+1][N+1];
 	memset(Grid, 0, sizeof(Grid));
 	for (int i = 0; i < B; ++i) {
 		cin >> x >> y;
 		Grid[x][y] = -1 ; // a blocked cell
 	}

 	if (Grid[1][1] == -1) {
 		cout << "No way of reaching any cell";
 		exit(0);
 	}

 	for (int i = 1; i <= M; i++){  // initializing the first column
 		if (Grid[i][1] != -1)
			Grid[i][1] = 1;
		else break;
 	}

	for (int j = 1; j <= N; ++j) {
		if (Grid[1][j] != -1)
			Grid[1][j] = 1;
		else break;
	}	

 	for (int i = 2; i <= M; ++i) {
 		for (int j = 2; j <= N; ++j) {
 			if (Grid[i][j] == -1) continue;

 			if (Grid[i-1][j] > 0) 
				Grid[i][j] = Grid[i-1][j] + Grid[i][j];
			if (Grid[i][j-1] > 0)
				Grid[i][j] = Grid[i][j] + Grid[i][j-1];
 		}
 	}
 	cout << (Grid[M][N] == -1 ? 0 : Grid[M][N]);
 	return 0;
 }