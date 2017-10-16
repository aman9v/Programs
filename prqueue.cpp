#include <bits/stdc++.h>

using namespace std;

double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap) {
    if (maxHeap.size() == minHeap.size())
        return (((double)maxHeap.top() + minHeap.top())/2);
    else 
        return minHeap.top();
    
}
void rebalance(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap) {
    if (maxHeap.size() - minHeap.size() >= 2) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
     
}

void addNum(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap) {
    if (minHeap.size() == maxHeap.size()) {
        if (minHeap.size() == 0 || num > minHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
    }
    else {
        if (num > minHeap.top())
            minHeap.push(num);
        else maxHeap.push(num);
    }
}

void getMedians(vector<int> v) {
    priority_queue<int> maxHeap;
    priority_queue<int ,vector<int>, greater<int> > minHeap;
    int n = v.size();
    vector<double> medians(n);
    for (int i = 0; i < v.size(); ++i) {
        int num = v[i];
        addNum(num, maxHeap, minHeap);
        rebalance(maxHeap, minHeap);
    }
    cout << maxHeap.size();
    }

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    getMedians(v);
    return 0;
}