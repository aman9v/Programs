#include<bits/stdc++.h>
using namespace std;

int maxStations(vector<int> arr, vector<int> dep) {
	int st = 0;
	int maxSt = 0;
	multimap<int, char> order;
	for (int i = 0; i < arr.size(); i++) {
		order.insert({arr[i], 'a'});
		order.insert({dep[i], 'd'});
	}
	
	// this works because elements in a multimap are sorted by keys by default
	for (auto it = order.begin(); it != order.end(); it++) {
		if (it->second == 'a')
			st++;
		else st--;
		if (st > maxSt)
			maxSt = st;
	}
	return maxSt;
}

int main() {
	vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
	vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
	int result = maxStations(arrival, departure);
	cout << result;
	return 0;
}