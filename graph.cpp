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
        
        void DFSUtil(int str, bool *visited) {
            visited[str] = true;
            cout << str << " ";
            
            for (int &v : adjList[str])
                if (!visited[v])
                    DFSUtil(v, visited);
                    
            }    

        void DFS(int strt) {
            bool *visited = new bool[V];
            for (int i = 0; i < V; i++) {
                visited[i] = false;
                }
            DFSUtil(strt, visited);    
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
    // g.printGraph(0);
    g.DFS(2);
    return 0;
    }
