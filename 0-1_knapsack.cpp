#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int Val[], int n) {
	int mat[n+1][W+1];
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				mat[i][w] = 0;
			else if (wt[i-1] <= w)
				mat[i][w] = max(Val[i-1] + mat[i-1][w-wt[i-1]], mat[i-1][w]);
			else 
				mat[i][w] = mat[i-1][w];
		}	
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j<= W; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return mat[n][W];	
}

int main() {
	int W = 2;
	int wt[] = {1, 1, 1};
	int Val[] = {10, 20, 30};
	int n = sizeof(Val)/sizeof(Val[0]);
	int maxVal = knapsack(W, wt, Val, n);
	cout << maxVal;
	return 0;
}