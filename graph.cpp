#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adjList;
    
    public:
        Graph(int v) {
            this->V = v;
            this->adjList = new vector<int>[v];
            }
            
        void addEdge(int src, int dest) {
            adjList[src].push_back(dest);
            // adjList[dest].push_back(src);
            }  
        
        void printGraph(int str) {
            for (int i = 0; i < V; i++) {
                cout << i << "->";
                for (int &v : adjList[i])
                    cout << v << " "; 
                cout << endl;    
                } 
                
            }    
    };

int main() {
    Graph g(4);    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph(0);
    return 0;
    }
