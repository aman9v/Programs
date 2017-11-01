#include<bits/stdc++.h>
using namespace std;

bool isInt(double n) {
    return floor(n) == n;
    }
    
int revNum(int n) {
    int rev = 0;
    while (n > 0) {
        int d = n % 10;
        rev = (rev * 10) + d;
        n /= 10;
        }
    return rev;
    }    

int calcMaxPow2(int diff) {
    int res = 1;
    for (int i = 0; i < 8*sizeof(unsigned int); i++) {
        int curr = 1 << i;
        if (curr > diff)
            break;
        res = curr;    
        }
    return res;
    }

int main()
{   
    int k = 321;
    int reverse = revNum(k);
    int diff = abs(k - reverse);
    int maxPower = calcMaxPow2(diff);
    cout << maxPower << endl;
    cout << reverse;
    return 0;
}
