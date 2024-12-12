#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

bool AreAnagrams(string word1, string word2) {
	if (word1.length() != word2.length()) {
		return false;
	}
	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());
	return word1 == word2;
}
int main() {
	string word1, word2;
	cout << "enter the first word: " << endl;
	cin >> word1;
	cout << "enter the second word: " << endl;
	cin >> word2;
	if (AreAnagrams(word1, word2)) {
		cout << word1 << " and " << word2 << " are anagrams" << endl;

	}
	else {
		cout << word1 << " and " << word2 << " are not anagrams" << endl;
	}



}