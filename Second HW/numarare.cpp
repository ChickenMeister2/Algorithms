#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<int> first[MAXN], second[MAXN], g[MAXN];
int dp[MAXN], finish[MAXN];
bool visited[MAXN];
stack<int> s;
int timestamp;

void DFS(int u) {
	// marchez nodul ca fiind vizitat
	visited[u] = true;
	for (int v : g[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}

	// timp de finalizare
	finish[u] = ++timestamp;
	s.push(u);
}

int main() {
	ifstream fin("numarare.in");
	ofstream fout("numarare.out");

	int n, m;
	fin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		first[u].push_back(v);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		second[u].push_back(v);
	}

	// creez graful de intersectie
	for (int i = 1; i <= n; i++) {
		for (int v : first[i]) {
			// cautam daca exista nodul v din primul graf in al doilea graf
			if (find(second[i].begin(), second[i].end(), v) !=
				second[i].end()) {
				g[i].push_back(v);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}

	// sortez in ordine desc a timpului de finalizare
	vector<int> nodes(n);
	iota(nodes.begin(), nodes.end(), 1);
	sort(nodes.begin(), nodes.end(), [](int u, int v) {
		return finish[u] > finish[v];
	});

	dp[1] = 1;

	// calculez numarul de drumuri de la nodul 1 la nodul n
	for (int u : nodes) {
		for (int v : g[u]) {
			dp[v] = (dp[v] + dp[u]) % MOD;
		}
	}

	fout << dp[n];

	return 0;
}
