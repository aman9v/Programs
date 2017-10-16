#include<bits/stdc++.h>
using namespace std;

string getSeason(const vector<int> &T) {
	int n = T.size();
	int max_sum = -1; int max_index = 0;
	for (int i = 0; i < n; i = i + n/4) {
		int max = *max_element(T.begin()+i, T.begin()+i+n/4);
		int min = *min_element(T.begin()+i, T.begin()+i+n/4);
		if ((max - min) > max_sum) {
			max_sum = max - min;
			max_index = i;
		}
	}
	int id = 0;
	if (max_index == 0) 
		return "WINTER";
	else if (max_index == id + n/4)
		return "SRPING";
	else if (max_index == id + (n/4)*2)
		return "SUMMER";
	else return "AUTUMN";	
}

int main() {
	vector<int> v = {2, -3, 42, 8, -14, -3, 17, -3};
	string season = getSeason(v);
	cout << season;
	return 0;
}
