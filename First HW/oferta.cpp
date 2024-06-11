#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream in("oferta.in");
ofstream out("oferta.out");

double minim_cost(int N, const vector<double>& P) {
	// initializez vectorul DP cu valoarea maxima pe care o poate avea
	vector<double> DP(N+1, float(INT32_MAX));
	DP[0] = 0;
	DP[1] = P[0];

	// incerc sa gasesc cea mai buna combinatie de a cumpara produsele astfel
	// incat sa obtin cel mai mic cost
	for (int i=2; i<=N; ++i) {
		DP[i] = min(DP[i], DP[i-1] + P[i-1]);

		// verificam daca grupam 2 elemente
		DP[i] = min(DP[i], DP[i-2] + max(P[i-1], P[i-2]) + min(P[i-1], P[i-2])/2);

		// verificam daca grupam 3 elemente
		if(i>2) {
			double maxim = max({P[i-1], P[i-2], P[i-3]});
			double minim = min({P[i-1], P[i-2], P[i-3]});
			double median = P[i-1] + P[i-2] + P[i-3] - maxim - minim;

			DP[i] = min(DP[i], DP[i-3] + maxim + median);
		}
	}

	// returnam suma
	return DP[N];
}

int main() {
	int N, dummy;
	in >> N;
	in >> dummy;
	vector<double> P(N);
	for (int i = 0; i < N; ++i) {
		in >> P[i];
	}

	out << fixed << setprecision(1) << minim_cost(N, P);

	return 0;
}
