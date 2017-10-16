#include <bits/stdc++.h> 

using namespace std;

int minProductUtil(int smaller, int bigger) {
    if (smaller == 0) return 0;
    if (smaller == 1) return bigger;
    
    int s = smaller >> 1;
    int halfProd = minProductUtil(s, bigger);
    
    if (smaller % 2 == 0) return halfProd + halfProd;
    else return halfProd + halfProd + bigger;
    }
    
int minProduct(int a, int b) {
    int smaller = a < b ? a : b;
    int bigger = a < b ? b : a;
    return minProductUtil(smaller, bigger);
    }    

int main() {
    ios_base::sync_with_stdio(false);
    int product = minProduct(31, 35);
    cout << product;
    return 0;
    }