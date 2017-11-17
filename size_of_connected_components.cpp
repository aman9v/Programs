#include<bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 4

int computeSize(int matrix[][COL], bool visited[][COL], int row, int col) {

	if (visited[row][col] || matrix[row][col] != 0 || row < 0 || col < 0 || row >= ROW || col >= COL)
		return 0;
	int size = 1;
	visited[row][col] = true;
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) {
			size += computeSize(matrix, visited, row + dr, col + dc);
		}
	}
	return size;
}

vector<int> computeSizeUtil(int matrix[][COL]) {
	bool visited[ROW][COL];
	vector<int> sizes;
	memset(visited, false, sizeof(visited));
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			int size = computeSize(matrix, visited, r, c);
			if (size > 0)
				sizes.push_back(size);
		}
	}
	return sizes;
}

int main() {
	int matrix[][4] = {
		{0, 2, 1, 0},
		{0, 1, 0, 1},
		{1, 1, 0, 1},
		{0, 1, 0, 1}
	};

	vector<int> compSizes = computeSizeUtil(matrix);
	for (int a : compSizes)
		cout << a << " ";
	return 0;
}