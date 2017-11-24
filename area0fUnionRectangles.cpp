#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x;

int main() {
    ios_base::sync_with_stdio(false);
    long int arr[1001][1001];
    memset(arr, 0, sizeof(arr));
    int N;
    cin >> N;
    long int area = 0;
    while (N--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        for (int i = x1; i < y1; ++i) {
            for (int j = x2; j < y2; ++j) {
                if (arr[i][j] == 0)
                    arr[i][j] = area += 1;
            }
        }
    }
    print(area);
    return 0;
}