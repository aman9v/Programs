 #include<bits/stdc++.h>
 using namespace std;
 
class Graph {
    int V;
    vector<int> *adjList;
    
    public: 
        vector<int> cyclePath;
        Graph(int V) {
            this->V = V;
            this->adjList = new vector<int>[V];
            }
        
        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            }    
        
        void printGraph() {
            for (int i = 0; i < V; i++) {
                cout << i;
                if (i < V)
                    cout << " -> ";\
                for (int &v : adjList[i])
                    cout << v << " "; 
                cout << endl;    
                }
               
            }   
            
            bool isCyclicUtil(int v, bool *visited, bool *inStack) {
                visited[v] = true;
                inStack[v] = true;
                cyclePath.push_back(v);
                for (int &w : adjList[v]) {
                    if (!visited[w] && isCyclicUtil(w, visited, inStack)) {
                        
                        return true;
                    }
                    else if (inStack[w]){
                        return true;
                    }
                }
                inStack[v] = false;
                return false;
            }
            
            bool isCyclic() {
                bool *visited = new bool[V];
                bool *inStack = new bool[V];
                for (int i = 0; i < V; i++) {
                    visited[i] = false;
                    inStack[i] = false;
                    }
                vector<int> cyclePath;
                for (int u = 0; u < V; u++) {
                    if (!visited[u])
                        if (isCyclicUtil(u, visited, inStack))
                            return true;
                    }     
                return false;     
                }
    };
 
 int main() {
    Graph G(4);
    G.addEdge(1, 0);
    G.addEdge(0, 2);
    G.addEdge(2, 1);
    // G.addEdge(1, 2);
    G.addEdge(2, 3);
    // G.addEdge(3, 3);
    bool hasCycle = G.isCyclic();
    if (!hasCycle)
        cout << "Graph has no cycle\n";
    else {
        cout << "Graph has a cycle\n"; 
        sort(G.cyclePath.begin(), G.cyclePath.end());
        for (int i : G.cyclePath)
            cout << i << " " ;
        cout << endl;
    }
    
    G.printGraph(); 
    return 0;   
    }
