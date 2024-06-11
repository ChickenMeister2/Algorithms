#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int32_t max_equal_subsequence_length(vector<unsigned long long>& first,
									 vector<unsigned long long>& second) {
	unsigned long long i = 0, j = 0;
	unsigned long long sum1 = 0, sum2 = 0;
	unsigned long long count = 0;

	// iterrez prin ambii vectori
	while (i < first.size() && j < second.size()) {
		sum1 += first[i++];
		sum2 += second[j++];
		// daca ajung intr-un moment in care sumele sunt egale
		if (sum1 == sum2) {
			count++;
			sum1 = 0;
			sum2 = 0;
		} else {
			// in cazul in care suma nu e egala din prima adun alternativ
			// in cele doua sume
			do {
				while (i < first.size() && sum1 < sum2) {
					sum1 += first[i++];
				}
				while (j < second.size() && sum2 < sum1) {
					sum2 += second[j++];
				}
				// daca dupa aceste adybaru succesive ajung la suma egala
				// incrementez counterul
				if (sum1 == sum2) {
					count++;
					sum1 = 0;
					sum2 = 0;
					break;
				}
			} while (i < first.size() && j < second.size());
		}
	}

	// cazul in care mai raman elemente in unul din vectori
	while (i < first.size()) {
		sum1 += first[i++];
	}

	while (j < second.size()) {
		sum2 += second[j++];
	}

	// daca avem sume egale aduagam inca odata la counter
	if (sum1 == sum2 && sum1 != 0) {
		count++;
	} else if (sum1 != sum2) {
		return  -1;
	}

	return count;
}
int main() {
	ifstream in("compresie.in");
	ofstream out("compresie.out");
	int n, m;
	in >> n;
	vector<unsigned long long> first(n);
	for (int i = 0; i < n; ++i) {
		in >> first[i];
	}
	in >> m;
	vector<unsigned long long> second(m);
	for (int i = 0; i < m; ++i) {
		in >> second[i];
	}

	int32_t result = max_equal_subsequence_length(first, second);
	out <<result << endl;

	return 0;
}

