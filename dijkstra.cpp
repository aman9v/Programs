#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;


class Graph {
	int V;
	vector<pair<int, int> > *adjList;

public:
	Graph(int V) {
		this->V = V;
		this->adjList = new vector< pair<int, int> >[V];
	}

	void addEdge(int u, int v, weight) {
		this->adjList[u].push_back(make_pair(v, weight));
		this->adjList[v].push_back(make_pair(u , weight));
	}

	void shortestPath(int src) {
		priority_queue(iPair, vector<iPair>, greater<iPair>) nodesToVisit;
		nodesToVisit.push(src);
		vector<int> dist(V, INF);
		dist[src] = 0;

		nodesToVisit.push({0, src});


		while (!nodesToVisit.empty()) {
			iPair node = nodesToVisit.top().second;
			nodesToVisit.pop();
			vector<iPair> neighbors = this->adjList[node];

			for (iPair &v : neighbors) { // for each adjacent vertex
				int id = v.first;
				int edge_weight = v.second;

				if (dist[v] > dist[node] + edge_weight) {
					dist[v] = dist[node] + edge_weight;
					nodesToVisit.push({dist[v], id});
				}	
			}
		}
		cout << "Node\t" << "Distance from Source\n";
		for (int i = 0; i < V; i++) {
			cout << i << "\t" << dist[i] << endl;
		}
 	}

};

int main() {
	Graph G(9);
	G.addEdge(0, 1, 4);
    G.addEdge(0, 7, 8);
    G.addEdge(1, 2, 8);
    G.addEdge(1, 7, 11);
    G.addEdge(2, 3, 7);
    G.addEdge(2, 8, 2);
    G.addEdge(2, 5, 4);
    G.addEdge(3, 4, 9);
    G.addEdge(3, 5, 14);
    G.addEdge(4, 5, 10);
    G.addEdge(5, 6, 2);
    G.addEdge(6, 7, 1);
    G.addEdge(6, 8, 6);
    G.addEdge(7, 8, 7);
	return 0;
}