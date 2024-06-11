#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("trenuri.in");
	ofstream fout("trenuri.out");

	string start, end;
	fin >> start >> end;

	int M;
	fin >> M;

	map<string, vector<string>> adj;
	map<string, int> inDegree, maxCities;
	queue<string> q;


	for (int i = 0; i < M; i++) {
		string x, y;
		fin >> x >> y;
		adj[x].push_back(y);
		inDegree[y]++;
		if (!inDegree.count(x)) {
			inDegree[x] = 0;
		}
	}

	// initializam coada pentru topsort
	for (auto& pair : inDegree) {
		if (pair.second == 0) {
			q.push(pair.first);
			if(pair.first == start) {
				maxCities[pair.first] = 1;  // punem 1 pt orasul de start
			} else {
				maxCities[pair.first] = 0;
			}
		}
	}

	// topsort si actualizarea numarului de orase maxime
	while (!q.empty()) {
		string node = q.front();
		q.pop();

		for (string& neighbor : adj[node]) {
			// se actualizeaza gradul interior al fiecarui vecin
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0) {
				q.push(neighbor);
			}
			// actualizam numarul de orase maxime
			if (maxCities[node] > 0) {
				maxCities[neighbor] = max(maxCities[neighbor], maxCities[node] + 1);
			}
		}
	}

	if(maxCities[end] > 0) {
		fout << maxCities[end];
	} else {
		fout << 1;
	}


	return 0;
}
