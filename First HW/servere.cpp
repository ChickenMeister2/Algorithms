#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cfloat>
using namespace std;

int main() {
	ifstream in("servere.in");
	ofstream out("servere.out");

	int N;
	in >> N;

	vector<int> P(N), C(N);

	for(int i = 0; i < N; i++)
			in >> P[i];
	for(int i = 0; i < N; i++)
			in >> C[i];

	// initializez elementele pentru cautarea binara din loop
	double left = *min_element(C.begin(), C.end());
	double right = *max_element(C.begin(), C.end());
	double result = -DBL_MAX;

	// fac o cautare binara pentru a gasi puterea minima
	while (left <= right) {
		double mid = left + (right - left) / 2;
		auto minPower = DBL_MAX;

		// verific daca mid-ul gasit este puterea optima
		for (int i = 0; i < N; i++) {
			minPower = min(minPower, P[i] - fabs(mid - C[i]));
		}

		auto nextMinPower = DBL_MAX;

		// fac inca o verificare doar ca adun o varabila mica (precizia)
		// pentru a ma asigura ca minPower este sau nu este
		// solutia optima
		for (int i = 0; i < N; i++) {
			nextMinPower = min(nextMinPower, P[i] - fabs(mid + 1e-6 - C[i]));
		}

		// daca mid nu a fost solutia optima atunci modific left sau right
		// in functie de cele doua puteri calculate
		if (nextMinPower >= minPower) {
			left = mid + 1e-6;
			result = max(result, nextMinPower);  // actualizez rezultatul daca este cazul
		} else {
			right = mid - 1e-6;
		}
	}

	out << fixed << setprecision(1) << result << endl;

	return 0;
}
