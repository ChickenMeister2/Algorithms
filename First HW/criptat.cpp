#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

ifstream in("criptat.in");
ofstream out("criptat.out");

// functie care verifica daca cuvantul
bool hasRepeatingChar(const std::string& str) {
	map<char, int> charCount;
	for (char c : str) {
		charCount[c]++;
		if (charCount[c] > str.size() / 2) {
			return true;
		}
	}
	return false;
}

// generez toate combinatiile de cuvinte si verific daca se incadreaza in
// cerintele problemei
void generateCombinations(const vector<string>& words,
						  string currentCombination,
						  int currentIndex, string& longestWord) {
	if (currentIndex == words.size()) {
		if (hasRepeatingChar(currentCombination) &&
		currentCombination.size() > longestWord.size()) {
			longestWord = currentCombination;
		}
		return;
	}

	generateCombinations(words, currentCombination + words[currentIndex],
						 currentIndex + 1, longestWord);

	generateCombinations(words, currentCombination, currentIndex + 1,
						 longestWord);
}

int main() {
	int numWords;
	in >> numWords;

	vector<string> words(numWords);
	for (int i = 0; i < numWords; ++i) {
		in >> words[i];
	}

	string longestWord;
	generateCombinations(words, "", 0, longestWord);

	out << longestWord.size() << endl;

	return 0;
}
