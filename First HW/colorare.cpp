#include <iostream>
#include <fstream>
#include <array>
#include <vector>
using namespace std;

#define MOD 1000000007

// functie pentru exponentiere rapida

uint64_t fastExpo(long long base, uint64_t exponent, long long mod) {
	base %= mod;
	long long result = 1;
	while (exponent > 0) {
		if (exponent & 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exponent >>= 1;
	}
	return result;
}

int main() {
	ifstream in("colorare.in");
	ofstream out("colorare.out");
	int count;
	vector<pair<uint64_t, char>> colorare;
	in >> count;

	// citim datele de intrare ca perechi de int si char
	for (uint64_t i = 0; i < count; i++) {
		uint64_t first;
		char second;
		in >> first >> second;
		colorare.emplace_back(first, second);
	}
	uint64_t result = 1;

	// initializez last_type pentru a fi folosit in loop
	char last_type = colorare[0].second;

	// parcurg pairurile citite
	for(int i = 0; i < count; i++) {
		// pentru primul element initializez result cu valorile corespunzatoare
		// din formulele deduse
		if(i == 0 && colorare[0].second == 'H') {
			result = 6 * fastExpo(3, (colorare[0].first - 1), MOD) % MOD;
			continue;
		} else if (i == 0 && colorare[0].second == 'V') {
			result = 3 * fastExpo(2, (colorare[0].first - 1), MOD) % MOD;
			continue;
		}
		uint64_t counter = 0;
		char type = colorare[i].second;

		// cat timp am acelasi tip de culoare, incrementez counter-ul
		while (colorare[i].second == type && i < count) {
			counter += colorare[i++].first;
		}
		i--;

		// in momentul in care se modifica tipul de culoare, schimb metoda de calcul
		if(last_type != type) {
			if (type == 'H')
				result = result * 2 * fastExpo(3, counter - 1, MOD) % MOD;
			else if (type == 'V')
				result = result * fastExpo(2, counter - 1, MOD) % MOD;
		} else {
			// daca am acelasi tip de culoare, aplic doar formula de la inmultire
			if (type == 'H')
				result = (result * fastExpo(3, counter , MOD)) % MOD;
			else if (type == 'V')
				result = (result * fastExpo(2, counter , MOD)) % MOD;
		}

		// actualizez last_type cu tipul curent
		last_type = type;
	}
	out << result % MOD << endl;

	return 0;
}
