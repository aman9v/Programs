#include <bits/stdc++.h>

using namespace std;

typedef vector <bool> vb;
typedef vector < vb > vvi;
typedef vector < pair <int, int> > vpii;
typedef map < pair<int, int>, bool> mpi;


bool getPath (vvi const &maze, int rows, int cols, vpii &path, mpi &cache) {
	
	if (cols < 0 || rows < 0 || !maze[rows][cols]) return false;
	pair <int, int> p = make_pair(rows, cols);
	if (cache.find(p) != cache.end()) return cache[p];
	
	bool isAtOrigin = rows == 0 && cols == 0;
	bool result = false;
	
	if (!isAtOrigin || getPath(maze, rows, cols-1, path, cache) || getPath(maze, rows-1, cols, path, cache)) {
	    path.push_back(p);
	    result = true;
	    }
	
	cache.insert(make_pair(p, result));
	return result; 
}


int main() {
	vvi maze(5, vb(5));
	maze = { {1, 1, 0, 1, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 0, 1} };
	vpii path;
    map < pair<int, int> , bool> cache;
    int rows = maze.size() - 1;
    int cols = maze[0].size() - 1;
	bool mazePathresult = getPath(maze, rows, cols, path, cache);
	cout << mazePathresult;
	return 0;
}