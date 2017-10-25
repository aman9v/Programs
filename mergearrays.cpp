#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(vector<int> v1, vector<int> v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> sortedArray(n1+n2);
    int one = 0, two = 0, res = 0;
    while (one < n && two < n) {
        if (v1[one] == v2[two]) {
            sortedArray[res++] = v1[one++];
            sortedArray[res++] = v2[two++];
            } 
        else if (v1[one] > v2[two]) {
            sortedArray[res++] = v2[two++];
            } 
        else {
            sortedArray[res++] = v1[one++];
            }
        }
        if (two > one) {
            while (one < n) {
                sortedArray[res++] = v1[one++];
                }
            }
        else if (one > two) {
            while (two < n) {
                sortedArray[res++] = v2[two++];
                }
            }
            return sortedArray;
}
	

int main() {
    vector<int> v1 = {1, 5, 7, 7};
    vector<int> v2 = {0, 1, 2, 3};
    vector<int> sortedArray = mergeArrays(v1, v2); 
        for (int a : sortedArray) {
            cout << a << " ";
        }
    return 0;
    }
