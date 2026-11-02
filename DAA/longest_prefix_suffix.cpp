#include <iostream>
#include <vector>
using namespace std;
vector<int> f(string& pat) {
    int n = pat.size();
    vector<int> lps(n);
    if (n == 0) {
        return lps;
    }
    lps[0] = 0;
    int longest_len = 0;
    int i = 1;
    while (i < n) {
        if (pat[i] == pat[longest_len]) {
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
int main() {
    string pat = "ababd";
    vector<int> lps = f(pat);

    for (int ele : lps) {
        cout << ele << " ";
    }
    cout << "\n";
}