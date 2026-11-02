#include <iostream>
#include <vector>
using namespace std;
vector<int> f(string& pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    if (n == 0) {
        return lps;
    }
    lps[0] = 0;
    int longest_len = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[longest_len]) {
            longest_len++;
            lps[i++] = longest_len;
        } else {
            if (longest_len != 0) {
                longest_len = lps[longest_len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}
vector<int> kmp(string& text, string& pattern) {
    int m = text.size();
    int n = pattern.size();

    // creating the Longest Prefix Suffix array of pattern String
    vector<int> lps = f(pattern);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < m) {
        if (j == n) {
            ans.push_back(i - j);
            if (j != 0) {
                j = lps[j - 1];
            }
        } else if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if(text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return ans;
}
int main() {
    string text, pattern;
    cout << "Enter the text string : ";
    cin >> text;

    cout << "Enter the pattern string : ";
    cin >> pattern;

    vector<int> foundAt = kmp(text, pattern);

    for (int ele : foundAt) {
        cout << ele << " ";
    }

    cout << "\n";
}