#include <iostream>
#include <vector>

using namespace std;

void subSeq(string& str, vector<string>& ans, int curr, string temp) {
    if (curr >= str.size()) {
        ans.push_back(temp);
        return;
    }
    subSeq(str, ans, curr + 1, temp);
    subSeq(str, ans, curr + 1, temp + str[curr]);
}
int main() {
    string str = "abc";
    vector<string> ans;

    subSeq(str, ans, 0, "");
    cout << ans.size() << "\n";
    for (auto ele : ans) {
        cout << ele << " ";
    }

    cout << '\n';
    return 0;
}