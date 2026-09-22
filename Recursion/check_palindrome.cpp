#include <iostream>
#include <vector>

using namespace std;
bool is_palin(string& str, int i, int j) {
    if (i >= j) {
        return true;
    }
    if (str[i] != str[j]) {
        return false;
    }
    return is_palin(str, i + 1, j - 1);
}
int main() {
    string str = "madam";
    cout << is_palin(str, 0, str.size() - 1);

    cout << '\n';
    return 0;
}