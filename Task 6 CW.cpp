#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int solveWordWrap(const vector<int>& wordLengths, int lineWidth, vector<int>& dp, vector<int>& backtrack) {
    int n = wordLengths.size();
    dp.assign(n + 1, INT_MAX);
    backtrack.assign(n, -1);
    dp[n] = 0;

    for (int curr = n - 1; curr >= 0; --curr) {
        int sum = 0;
        for (int i = curr; i < n; ++i) {
            sum += wordLengths[i];
            int tot = sum + (i - curr);

            if (tot > lineWidth) break;

            int cost = (i == n - 1) ? 0 : (lineWidth - tot) * (lineWidth - tot);
            if (cost + dp[i + 1] < dp[curr]) {
                dp[curr] = cost + dp[i + 1];
                backtrack[curr] = i + 1;
            }
        }
    }

    return dp[0];
}

vector<string> reconstructSolution(const vector<string>& words, const vector<int>& backtrack) {
    vector<string> lines;
    int n = words.size();
    int curr = 0;

    while (curr < n) {
        string line;
        for (int i = curr; i < backtrack[curr]; ++i) {
            if (!line.empty()) line += " ";
            line += words[i];
        }
        lines.push_back(line);
        curr = backtrack[curr];
    }

    return lines;
}

int main() {
    int lineWidth;
    cout << "Enter the line width: ";
    cin >> lineWidth;

    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the words: \n";
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    vector<int> wordLengths(n);
    for (int i = 0; i < n; ++i) {
        wordLengths[i] = words[i].length();
    }

    vector<int> dp, backtrack;
    int minCost = solveWordWrap(wordLengths, lineWidth, dp, backtrack);
    vector<string> wrappedText = reconstructSolution(words, backtrack);

    cout << "\nOutput:\n";
    for (size_t i = 0; i < wrappedText.size(); ++i) {
        cout << "line " << i + 1 << ": " << wrappedText[i] << endl;
    }
    cout << "Total cost: " << minCost << endl;

    return 0;
}
