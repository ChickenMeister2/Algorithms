#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, int>>> adj, rev_adj;
vector<long long> distFromX, distFromY, distFromZ;

// dijkstra pentru minpath de la un nod la sursa
void dijkstra(int s, vector<long long>& dist,
			  const vector<vector<pair<int, int>>>& graph) {
	unsigned long n = graph.size();
	dist.assign(n, INF);
	priority_queue<pair<long long, int>,
	        vector<pair<long long, int>>, greater<>> pq;
	pq.emplace(0, s);
	dist[s] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		long long d = pq.top().first;
		pq.pop();
		if (d > dist[u])
			continue;

		for (const auto& [v, w] : graph[u]) {  // parcurgerea vecinilor
			if (dist[u] + w < dist[v]) {  // relaxam muchia
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

int main() {
	ifstream fin("drumuri.in");
	ofstream fout("drumuri.out");
	int N, M;
	fin >> N >> M;

	adj.resize(N + 1);
	rev_adj.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		fin >> u >> v >> w;
		adj[u].emplace_back(v, w);  // adaugam muchie in graful normal
		rev_adj[v].emplace_back(u, w);  // si in graful inversat
	}

	int x, y, z;
	fin >> x >> y >> z;

	// calcularea distantelor minime de la x, y, z la toate celelalte noduri
	dijkstra(x, distFromX, adj);
	dijkstra(y, distFromY, adj);

	// folosirea grafului inversat ne ajuta sa gasim eficient distantele de
	// la celelalte noduri la z
	dijkstra(z, distFromZ, rev_adj);

	long long minSum = INF;

	// cautam suma minima care este si solutia noastra
	for (int v = 1; v <= N; ++v) {
		if (distFromX[v] < INF && distFromY[v] < INF && distFromZ[v] < INF) {
			long long totalDistance =
					distFromX[v] + distFromY[v] + distFromZ[v];
			minSum = min(minSum, totalDistance);
		}
	}

	if(minSum == INF)
		fout << -1;
	else
		fout << minSum;

	return 0;
}
